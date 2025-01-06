// Program Sun IDPROM values into an M48T59Y

// References:
//   http://www.obsolyte.com/sunFAQ/faq_nvram.html
//   https://github.com/MrSparc/idprom-repair

//////////////////////////////////////////////////////////////////////////////////
// Edit the values here as needed
//////////////////////////////////////////////////////////////////////////////////

// The data here is from a Sun Blade 100 motherboard I bought on EBay.

// Machine type
#define MACHINE_TYPE 0x83    // e.g., 0x83 for Sun Blade, 0x80 for Sun Ultra

// MAC address
const uint8_t MAC_ADDR[6] = { 0x00, 0x03, 0xBA, 0x14, 0xFE, 0x38 };

//////////////////////////////////////////////////////////////////////////////////
// You shouldn't need to edit anything beyond this point...
//////////////////////////////////////////////////////////////////////////////////

#define SHIFTREG_DATA 2
#define SHIFTREG_SCLK 3
#define SHIFTREG_RCLK 4

#define M48T59Y_NW 5
#define M48T59Y_NG 6
#define M48T59Y_NE 7

#define GO  0x10  // pin 4 of PORTC
#define LOG 0x20  // pin 5 of PORTC

// For very short delays
#define NOP() __asm__ __volatile__ ("nop\n\t")

void assert_addr(uint16_t addr) {
  for (uint8_t i = 0; i < 16; ++i) {
    // assert one bit of address
    digitalWrite( SHIFTREG_DATA, (addr & 0x8000) != 0 );

    // clock in the bit
    digitalWrite( SHIFTREG_SCLK, 1 );
    digitalWrite( SHIFTREG_SCLK, 0 );

    // continue with remaining bits
    addr <<= 1;
  }

  // clock serial data into the register
  digitalWrite( SHIFTREG_RCLK, 1 );
  digitalWrite( SHIFTREG_RCLK, 0 );
}

// Keep track of which direction the bus is configured for,
// so m48t59y_read and m48t59y_write can switch as needed
bool reading_from_bus;

// Set up DDRC and DDRB for reading from the M48T59Y.
void configure_data_bus_for_read() {
  DDRC = 0x00;
  DDRB = 0x00;
  // disable all pull ups
  PORTC = 0x00;
  PORTB = 0x00;
  reading_from_bus = true;
}

// Set up DDRC and DDRB for writing to the M48T59Y.
void configure_data_bus_for_write() {
  DDRC = 0x0F;
  DDRB = 0x0F;
  reading_from_bus = false;
}

uint8_t m48t59y_read( uint16_t addr ) {
  if ( !reading_from_bus )
    configure_data_bus_for_read();

  uint8_t data;
  digitalWrite( M48T59Y_NW, 1 ); // make sure write is de-asserted
  assert_addr( addr );
  NOP();
  digitalWrite( M48T59Y_NE, 0 ); // enable chip
  NOP();
  digitalWrite( M48T59Y_NG, 0 ); // enable output
  NOP(); // multiple NOPs to ensure at least 70ns for data to be available
  NOP();
  NOP();
  data = ((PINB & 0x0F) << 4) | (PINC & 0x0F); // read data
  digitalWrite( M48T59Y_NG, 1 ); // disable output
  digitalWrite( M48T59Y_NE, 1 ); // disable chip
  return data;
}

// Note: before calling this, make sure that DDRC and DDRB
// are both set to 0x0F so that we can assert data to the M48T59Y's
// data pins.
void m48t59y_write( uint16_t addr, uint8_t data ) {
  if ( reading_from_bus )
    configure_data_bus_for_write();

  digitalWrite( M48T59Y_NW, 1 ); // make sure write signal is de-asserted
  assert_addr( addr );
  PORTC = (PORTC & 0xF0) | (data & 0xF); // output low nybble of data
  PORTB = (PORTB & 0xF0) | ((data >> 4) & 0xF); // output high nybble of data
  NOP();
  digitalWrite( M48T59Y_NE, 0 ); // enable chip
  NOP();
  digitalWrite( M48T59Y_NW, 0 ); // enable write
  NOP(); // ensure 70 ns to allow chip to register the data being written
  NOP();
  NOP();
  digitalWrite( M48T59Y_NW, 1 ); // disable write
  NOP();
  digitalWrite( M48T59Y_NE, 1 ); // disable chip
}

void setup() {
  // de-select M48T59Y, disable output, disable write
  // (do this before enabling these pins as outputs, to avoid
  // spurious activation of the M48T59Y)
  digitalWrite( M48T59Y_NW, 1 );
  digitalWrite( M48T59Y_NG, 1 );
  digitalWrite( M48T59Y_NE, 1 );

  // set shift register and M48T59Y control pins as outputs
  pinMode( SHIFTREG_DATA, OUTPUT );
  pinMode( SHIFTREG_SCLK, OUTPUT );
  pinMode( SHIFTREG_RCLK, OUTPUT );
  pinMode( M48T59Y_NW, OUTPUT );
  pinMode( M48T59Y_NG, OUTPUT );
  pinMode( M48T59Y_NE, OUTPUT );

  // set serial and register clock low initially
  digitalWrite( SHIFTREG_SCLK, 0 );
  digitalWrite( SHIFTREG_RCLK, 0 );

  // set data bus pins to input
  configure_data_bus_for_read();

  // use serial output to report results of tests
  Serial.begin( 9600 );
  while (!Serial);
}

// Buffer used for IDPROM values
uint8_t idprom_data[16];

// Function to clear NVRAM contents and then write IDPROM info.
// Returns true if successful, false if not.
bool idprom_write() {
  Serial.println( "Clearing NVRAM..." );
  for ( uint16_t i = 0; i < 0x1FF0; ++i )
    m48t59y_write( i, 0x00 );

  Serial.println( "Verifying that NVRAM is erased..." );
  for ( uint16_t i = 0; i < 0x1FF0; ++i ) {
    uint8_t data = m48t59y_read( i );
    if ( data != 0x00 ) {
      Serial.print( "  Value at address ");
      Serial.print( i, HEX );
      Serial.println( " is not 0x00!");
      return false;
    }
  }

  // Format the IDPROM data

  // format/version number, always 0x01
  idprom_data[0] = 0x01;

  // machine type byte (MSB of hostid)
  idprom_data[1] = MACHINE_TYPE;

  // copy MAC address bytes
  for ( uint8_t i = 0; i < 6; ++i )
    idprom_data[i+2] = MAC_ADDR[i];

  // 4 byte manufacture date, can be all 0s
  idprom_data[8] = 0x00;
  idprom_data[9] = 0x00;
  idprom_data[10] = 0x00;
  idprom_data[11] = 0x00;  // put your main code here, to run repeatedly:


  // last three hostid bytes, which are the same as the last three
  // MAC address bytes
  for ( uint8_t i = 0; i < 3; ++i )
    idprom_data[i+12] = MAC_ADDR[i+3];

  // Calculate checksum, which is the bitwise XOR of bytes 0..14
  uint8_t checksum = idprom_data[0];
  for ( uint8_t i = 1; i < 15; ++i )
    checksum ^= idprom_data[i];

  idprom_data[15] = checksum;

  Serial.println( "Writing IDPROM data..." );
  for ( uint16_t i = 0; i < 16; ++i )
    m48t59y_write( 0x1DF8 + i, idprom_data[i] );

  Serial.println( "Verifying IDPROM data..." );
  for ( uint16_t i = 0; i < 16; ++i ) {
    uint8_t data = m48t59y_read( 0x1DF8 + i );
    if ( data != idprom_data[i] ) {
      Serial.print( "  Data mismatch at address " );
      Serial.print( 0x1DF8 + i, HEX );
      Serial.print( " (expected ");
      Serial.print( idprom_data[i], HEX );
      Serial.print( ", got " );
      Serial.print( data, HEX );
      Serial.println( ")" );
      return false;
    }
  }

  return true;
}

void loop() {
  if ( (PINC & GO) == 0 ) {
    bool success = idprom_write();
    if ( success )
      Serial.println( "IDPROM data written successfully" );
    else
      Serial.println( "Writing IDPROM data failed" );
  }
}

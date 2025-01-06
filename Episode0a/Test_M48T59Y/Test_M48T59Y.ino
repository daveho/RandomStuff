// Test program for M48T59Y

// Purpose of the test program is to verify that the
// functions of the M48T59Y are working correctly.

// There are two 74HC595 shift registers controlled by Arduino pins
// D2, D3, and D4. They are cascaded, and their outputs generate
// A0..A12 sent to the M48T59Y as its 13-bit address input.

// The first 74HC595 generates M48T59Y A0..A7, the second
// 74HC595 generates M48T59Y A8..A12. So, when an address is
// generated, it is shifted out in order from MSB (first)
// to LSB (last).

// Connections:
//   Arduino D2: 74HC595 serial data, pin 14 on first 74HC595
//   Arduino D3: 74HC595 serial clock, pin 11 on both 74HC595s
//   Arduino D4: 74HC595 register clock, pin 12 on both 74HC595s
//
//   Arduino D5: -W (active low write) signal to pin 27 on M48T59Y
//   Arduino D6: -G (active low output enable) to pin 22 on M48T59Y
//   Arduino D7: -E (active low chip enable) signal to pin 20 on M48T59Y
//
//   Arduino A0..A3 (controlled as low nybble of AVR PORTC):
//      connected to D0..D3 on the M48T59Y (its low 4 data bus pins)
//   Arduino D8..D11 (controlled as low nybble of AVR PORTB):
//      connected to D4..D7 on the M49T59Y (its high 4 data bus pins)
//
//   Arduino A4: connected to GO pushbutton (shorts to ground when pressed)
//   Arduino A5: connected to LOG pushbutton (shorts to ground when pressed)

#define SHIFTREG_DATA 2
#define SHIFTREG_SCLK 3
#define SHIFTREG_RCLK 4

#define M48T59Y_NW 5
#define M48T59Y_NG 6
#define M48T59Y_NE 7

#define GO  0x10  // pin 4 of PORTC
#define LOG 0x20  // pin 5 of PORTC

// All locations with addressess less than 1FF0h are memory locations.
#define M48T59Y_FIRST_REG 0x1FF0

// register addresses
#define M48T59Y_CONTROL 0x1FF8
#define M48T59Y_SECONDS 0x1FF9
#define M48T59Y_MINUTES 0x1FFA
#define M48T59Y_HOUR    0x1FFB
#define M48T59Y_DAY     0x1FFC
#define M48T59Y_DATE    0x1FFD
#define M48T59Y_MONTH   0x1FFE
#define M48T59Y_YEAR    0x1FFF

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

// We use an pseudo-random number generator
// to generate data to store in the M48T59Y's memory.
// Because the sequence is same as long as the seed is the
// same, we can store the data and then know how to verify it.
// By doing a verify pass *before* storing data, then we
// are testing whether the data contents are actually
// nonvolatile.

// https://stackoverflow.com/questions/17035441/looking-for-decent-quality-prng-with-only-32-bits-of-state

#define SEED 0

uint32_t state;
uint32_t rngData; // bytes of data available
uint8_t rngNumAvail; // how many bytes of data are available

uint32_t mulberry32(void) {
  uint32_t z = (state += 0x6D2B79F5);
  z = (z ^ z >> 15) * (1 | z);
  z ^= z + (z ^ z >> 7) * (61 | z);
  return z ^ z >> 14;
}

void rng_reset() {
  state = SEED;
  rngNumAvail = 0;
}

uint8_t rng_gen() {
  if ( rngNumAvail == 0 ) {
    rngData = mulberry32();
    rngNumAvail = 4;
  }
  uint8_t result = rngData & 0xFF;
  rngData >>= 8;
  --rngNumAvail;
  return result;
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

uint8_t tests_passed, tests_executed;

// Verify the contents of memory written previously by writeMem()
void verify_mem( bool log_mismatch = false ) {
  Serial.print( "Verifying memory contents..." );

  uint16_t addr = 0;
  uint16_t mismatch = 0;
  uint8_t data, expected;

  rng_reset();

  while ( addr < M48T59Y_FIRST_REG ) {
    data = m48t59y_read( addr );
    expected = rng_gen();
    if ( data != expected ) {
      ++mismatch;
      if ( log_mismatch ) {
        Serial.print("[");
        Serial.print( addr, HEX );
        Serial.print(",e=");
        Serial.print( expected, HEX );
        Serial.print(",a=");
        Serial.print( data, HEX );
        Serial.print("]");
      }
    }
    
    ++addr;
  }

  if ( mismatch > 0 ) {
    Serial.print( mismatch );
    Serial.println( " byte(s) did not match" );
  } else {
    Serial.println( "all bytes matched!" );
    ++tests_passed;
  }

  ++tests_executed;
}

// Write pseudo-random data
void write_mem() {
  Serial.print( "Writing memory contents..." );

  uint16_t addr = 0;
  uint16_t mismatch = 0;
  uint8_t data, expected;

  rng_reset();

  while ( addr < M48T59Y_FIRST_REG ) {
    data = rng_gen();
    m48t59y_write( addr, data );
    ++addr;
  }

  Serial.println( "done" );

  configure_data_bus_for_read();
}

uint8_t bcd_to_dec( uint8_t bcd ) {
  return (bcd >> 4)*10 + (bcd & 0xF);
}

// Test date/time values
// (03:40 PM on Jan 3, 2025, which is approximately when I wrote
// the date/time test code initially)
#define TEST_SECONDS  0x00
#define TEST_MINUTES  0x40
#define TEST_HOUR     0x15
#define TEST_DAY      0x06
#define TEST_DATE     0x03
#define TEST_MONTH    0x01
#define TEST_YEAR     0x25

void set_time_and_date() {
  Serial.println( "Setting time and date..." );

  // set the W bit in the control register
  // (note that we are leaving the calibration bits as 0,
  // and will also clear the stop bit, meaning that the
  // oscillator should run)
  m48t59y_write( M48T59Y_CONTROL, 0x80 );

  // set time and date to test values
  m48t59y_write( M48T59Y_SECONDS, TEST_SECONDS );
  m48t59y_write( M48T59Y_MINUTES, TEST_MINUTES );
  m48t59y_write( M48T59Y_HOUR, TEST_HOUR );
  m48t59y_write( M48T59Y_DAY, TEST_DAY );
  m48t59y_write( M48T59Y_DATE, TEST_DATE );
  m48t59y_write( M48T59Y_MONTH, TEST_MONTH );
  m48t59y_write( M48T59Y_YEAR, TEST_YEAR );

  // clear the W bit
  m48t59y_write( M48T59Y_CONTROL, 0x00 );

  configure_data_bus_for_read();

  // wait one second
  delay( 1000 );
}

bool check_rtc_reg( uint16_t addr, uint8_t expected, const char *name ) {
  uint8_t data = m48t59y_read( addr );
  if ( data != expected ) {
    Serial.print( "  Mismatch in " );
    Serial.print( name );
    Serial.print( " register (E=" );
    Serial.print( expected, HEX );
    Serial.print( ",A=" );
    Serial.print( data, HEX );
    Serial.println( ")" );
    return false;
  }
  return true;
}

// Verify that the date and time values programmed by set_time_and_date()
// can be read back
void verify_time_and_date() {
  Serial.println( "Test reading back time/date values..." );
  bool good = true;
  if ( !check_rtc_reg( M48T59Y_MINUTES, TEST_MINUTES, "minutes" ) ) good = false;
  if ( !check_rtc_reg( M48T59Y_HOUR, TEST_HOUR, "hour" ) ) good = false;
  if ( !check_rtc_reg( M48T59Y_DAY, TEST_DAY, "day" ) ) good = false;
  if ( !check_rtc_reg( M48T59Y_DATE, TEST_DATE, "date" ) ) good = false;
  if ( !check_rtc_reg( M48T59Y_MONTH, TEST_MONTH, "month" ) ) good = false;
  if ( !check_rtc_reg( M48T59Y_YEAR, TEST_YEAR, "year" ) ) good = false;

  if ( good ) {
    Serial.println( "  Passed, all values were read back as expected" );
    ++tests_passed;
  } else
    Serial.println( "  FAILED, one or more values did not match" );

  ++tests_executed;
}

// Verify that the clock is running by seeing the second
// counter increase. Given that it was previously set to 0,
// we shouldn't need to worry about it rolling over during this test.
void verify_clock_running() {
  Serial.println( "Verifying that clock is counting up..." );

  // set R bit in control register
  m48t59y_write( M48T59Y_CONTROL, 0x40 );

  // read current value of seconds register (will probably be 1)
  uint8_t cur_sec;
  cur_sec = m48t59y_read( M48T59Y_SECONDS );
  cur_sec = bcd_to_dec( cur_sec );
  Serial.print( "  initial seconds=" );
  Serial.print( (uint16_t) cur_sec );
  Serial.println();

  // clear R bit so that registers are updated again
  m48t59y_write( M48T59Y_CONTROL, 0x00 );

  // wait for three seconds
  delay( 3000 );

  // set R bit in control register again
  m48t59y_write( M48T59Y_CONTROL, 0x40 );

  // read updated second count
  uint8_t now_sec = m48t59y_read( M48T59Y_SECONDS );
  now_sec = bcd_to_dec( now_sec );
  Serial.print( "  updated seconds (after 3s delay)=" );
  Serial.print( (uint16_t) now_sec );
  Serial.println();

  // expect the updated second count to have increased by 3 or 4
  if ( cur_sec + 3 == now_sec || cur_sec + 4 == now_sec ) {
    Serial.println( "  Passed, seconds seem to be updating" );
    ++tests_passed;
  } else {
    Serial.println( "  FAILED, seconds are not updating correctly?" );
  }

  ++tests_executed;
}

void runTests( bool log ) {
  tests_passed = 0;
  tests_executed = 0;

  verify_mem( log );
  write_mem();
  verify_mem( log );
  set_time_and_date();
  verify_time_and_date();
  verify_clock_running();

  Serial.print( tests_passed );
  Serial.print( "/" );
  Serial.print( tests_executed );
  Serial.println( " tests passed" );
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

uint16_t test = 0;

void loop() {
  if ( (PINC & GO) == 0 ) {
    // GO button was pressed
    Serial.println( "GO pressed" );

    // Check whether LOG button is pressed
    bool log = ( (PINC & LOG) == 0 );
    if ( log )
      Serial.println( "LOG pressed, will log data mismatches" );
    
    runTests( log );
  }
}

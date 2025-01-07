#include "m48t59y.h"

void m48t59y_assert_addr(uint16_t addr) {
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
static bool reading_from_bus;

// Set up DDRC and DDRB for reading from the M48T59Y.
void m48t59y_configure_data_bus_for_read() {
  DDRC = 0x00;
  DDRB = 0x00;
  // disable all pull ups
  PORTC = 0x00;
  PORTB = 0x00;
  reading_from_bus = true;
}

// Set up DDRC and DDRB for writing to the M48T59Y.
void m48t59y_configure_data_bus_for_write() {
  DDRC = 0x0F;
  DDRB = 0x0F;
  reading_from_bus = false;
}

uint8_t m48t59y_read( uint16_t addr ) {
  if ( !reading_from_bus )
    m48t59y_configure_data_bus_for_read();

  uint8_t data;
  digitalWrite( M48T59Y_NW, 1 ); // make sure write is de-asserted
  m48t59y_assert_addr( addr );
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

void m48t59y_write( uint16_t addr, uint8_t data ) {
  if ( reading_from_bus )
    m48t59y_configure_data_bus_for_write();

  digitalWrite( M48T59Y_NW, 1 ); // make sure write signal is de-asserted
  m48t59y_assert_addr( addr );
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

// This should be called from the sketch's setup() function
void m48t59y_init() {
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
  m48t59y_configure_data_bus_for_read();

  // use serial output to report diagnostics
  Serial.begin( 9600 );
  while (!Serial);
}


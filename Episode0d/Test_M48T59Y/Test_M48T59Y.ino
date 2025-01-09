// Test program for M48T59Y

// Purpose of the test program is to verify that the
// functions of the M48T59Y are working correctly.

// Include common functions
#include <m48t59y.h>

// We use an pseudo-random number generator
// to generate data to store in the M48T59Y's memory.
// Because the sequence is same as long as the seed is the
// same, we can store the data and then know how to verify it.
// By doing a verify pass *before* storing data, then we
// are testing whether the data contents are actually
// nonvolatile.

// From: https://stackoverflow.com/questions/17035441/

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

  m48t59y_configure_data_bus_for_read();
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

  m48t59y_configure_data_bus_for_read();

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
  m48t59y_init();
}

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

// Sketch to dump the NVRAM contents of an M48T59Y

// Note: if you are using the Arduino 2.x IDE, it is not
// possible to copy all of the captured data from the Serial
// Monitor window:
//
//   https://github.com/arduino/arduino-ide/issues/1081
//
// So, you'll need to use an external program to capture
// the output. I use tio:
//
//   tio -b 115200 --log --log-file dump.txt /dev/ttyUSB0

// Include common definitions and functions
#include <m48t59y.h>

void setup() {
  m48t59y_init();
}

void dump() {
  Serial.println( "  // M48T59Y NVRAM contents" );
  for ( uint16_t addr = 0; addr < M48T59Y_FIRST_REG; ++addr ) {
    if ( (addr & 0xF) == 0 )
      Serial.print( "  " );
    Serial.print( "0x" );
    uint8_t data = m48t59y_read( addr );
    Serial.print( data, HEX );
    Serial.print( "," );
    if ( (addr & 0xF) == 15 )
      Serial.println();
  }
}

void loop() {
  if ( (PINC & GO) == 0 ) {
    dump();
  }
}

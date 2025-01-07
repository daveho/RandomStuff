// Sketch to dump the NVRAM contents of an M48T59Y

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

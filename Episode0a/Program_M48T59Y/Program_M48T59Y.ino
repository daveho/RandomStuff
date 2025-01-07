// Program Sun IDPROM values into an M48T59Y

// Include common functions
#include <m48t59y.h>

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

void setup() {
  m48t59y_init();
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
  idprom_data[11] = 0x00;

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

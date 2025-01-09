// Common definitions and functions for reading from and writing
// to a M48T59Y using the Arduino-based test circuit

#ifndef M48T59Y_H
#define M48T59Y_H

#include <Arduino.h>

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

// Pushbuttons
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

// Function prototypes
void m48t59y_assert_addr( uint16_t addr );
void m48t59y_configure_data_bus_for_read();
void m48t59y_configure_data_bus_for_write();
uint8_t m48t59y_read( uint16_t addr );
void m48t59y_write( uint16_t addr, uint8_t data );
void m48t59y_init();

#endif // M48T59Y_H


// hexdisplay16 firmware
// Copyright (c) 2017-2021, David H. Hovemeyer <david.hovemeyer@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining
// a copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject
// to the following conditions:
// 
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY
// KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
// WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
// LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
// OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
// WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#define F_CPU 1000000 // use internal oscillator, set to 1 MHz
#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define A (1<<0)
#define B (1<<1)
#define C (1<<2)
#define D (1<<3)
#define E (1<<4)
#define F (1<<5)
#define G (1<<6)

// Font for hex digits 0-F: values are inverted because
// we're using common anode LED displays, so we need to
// output a low voltage to permit current to flow from
// the common anode through a segment LED.
const uint8_t g_hexfont[16] = {
	~(A|B|C|D|E|F),
	~(B|C),
	~(A|B|D|E|G),
	~(A|B|C|D|G),
	~(B|C|F|G),
	~(A|C|D|F|G),
	~(A|C|D|E|F|G),
	~(A|B|C),
	~(A|B|C|D|E|F|G),
	~(A|B|C|F|G),
	~(A|B|C|E|F|G),
	~(C|D|E|F|G),
	~(D|E|G),
	~(B|C|D|E|G),
	~(A|D|E|F|G),
	~(A|E|F|G),
};

uint8_t g_count;

void update_display(void) {
	uint8_t which = g_count & 0x3;
	uint8_t val;
	switch (which) {
	case 0: // left pair, most significant hex digit
		val = (PINC >> 4) & 0x0f;       // get high 4 bits of high input byte
		PORTB = ~1;                     // turn on CA1
		PORTA = g_hexfont[val];         // output to hex digit
		break;
	case 1: // left pair, least significant hex digit
		val = PINC & 0x0f;              // get low 4 bits of high input byte
		PORTB = ~2;                     // turn on CA2
		PORTA = g_hexfont[val];         // output to hex digit
		break;
	case 2: // right pair, most significant hex digit
		val = (PIND >> 4) & 0x0f;       // get high 4 bits of low input byte
		PORTB = ~4;                     // turn on CA3
		PORTA = g_hexfont[val];         // output to hex digit
		break;
	case 3: // right pair, least significant hex digit
		val = PIND & 0x0f;              // get low 4 bits of low input byte
		PORTB = ~8;                     // turn on CA4
		PORTA = g_hexfont[val];         // output to hex digit
		break;
	}
	g_count++;
}

int main(void) {
	// disable JTAG, otherwise port C pins won't work correctly
	MCUCR |= (1 << JTD);
	MCUCR |= (1 << JTD);

	// ports C and D are data inputs, configure them for input and
	// enable internal pull-ups
	DDRC = 0x00;     // set port C for input
	PORTC = 0xFF;    // enable internal pull-ups on port C pins
	DDRD = 0x00;     // set port D for input
	PORTD = 0xFF;    // enable internal pull-ups on port D pins

	// port A is the segment outputs, configure pins 0-6 for output
	DDRA = 0x7F;     // enable port A pins 0-6 for output
	PORTA = 0xFF;    // set outputs high initially (and enable pull-up on pin 7)

	// port B pins 0-3 are used to control the common anodes,
	// configure for output
	DDRB = 0x0F;     // enable port B pins 0-3 for output
	PORTB = 0xFF;    // set outputs high and enable pull-ups on other pins

	for (;;) {
		update_display();
		_delay_ms(2);
	}
}

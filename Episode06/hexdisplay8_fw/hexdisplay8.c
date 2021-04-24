// hexdisplay8 firmware
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
	uint8_t which = g_count & 0x1;
	uint8_t val;
	switch (which) {
	case 0: // most significant hex digit
		val = (PINB >> 4) & 0x0f;       // get high 4 bits of input
		PORTA = ~1;                     // turn on CA2 (using PA0)
		PORTD = g_hexfont[val];         // output to most significant hex digit
		break;
	case 1: // least significant hex digit
		val = PINB & 0x0f;              // get low 4 bits of input
		PORTA = ~2;                     // turn on CA1 (using PA1)
		PORTD = g_hexfont[val];         // output to least significant hex digit
		break;
	}
	g_count++;
}

int main(void) {
	DDRB = 0x00;     // set port B for input
	PORTB = 0xFF;    // enable internal pull-ups on port B pins
	DDRD = 0x7F;     // enable port D pins 0-6 for output
	PORTD = 0x7F;    // all LED segments off
	DDRA = 0x03;     // enable A0 and A1 as output
	PORTA = 0x03;    // turn off common anodes

	for (;;) {
		update_display();
		_delay_ms(4);
	}
}

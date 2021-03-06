#include <mcs51/at89x051.h>
#include <stdint.h>

/*
 * InOut test program for 8051 variants (will this work? :-)
 *
 * LED cathode is connected to P3.3 (pin 13)
 * Pushbutton switch is connected to P3.2 (pin 12):
 * when button is pushed, P3.2 is connected to ground
 */

#define LED_BIT (1 << 3)
#define SW_BIT  (1 << 2)

int main() {
	/* set all P3 bits high: allows input and output on all pins */
	P3 = 0xFF;

	for (;;) {
		if (P3 & SW_BIT) {
			/* button not pressed: set P3.3 high (LED off) */
			P3 |= LED_BIT;
		} else {
			/* button pressed: set P3.3 low (LED on) */
			P3 &= ~LED_BIT;
		}
	}
}

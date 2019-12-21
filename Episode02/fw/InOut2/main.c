#include <mcs51/at89x051.h>
#include <stdint.h>

/*
 * InOut test program for 8051 variants (fixed version)
 *
 * LED cathode is connected to P3.3 (pin 13)
 * Pushbutton switch is connected to P3.2 (pin 12):
 * when button is pushed, P3.2 is connected to ground
 */

#define LED_BIT P3_3        /* __bit variable for P3.3 */
#define SW_BIT  P3_2        /* __bit variable for P3.2 */

int main() {
	/* set all P3 bits high: allows input and output on all pins */
	P3 = 0xFF;

	for (;;) {
		if (SW_BIT) {
			/* button not pressed: set P3.3 high (LED off) */
			LED_BIT = 1;
		} else {
			/* button pressed: set P3.3 low (LED on) */
			LED_BIT = 0;
		}
	}
}

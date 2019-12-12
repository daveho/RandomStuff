#include <mcs51/at89x051.h>
#include <stdint.h>

/*
 * InOut test program for 80C32 circuit
 *
 * LED is connected to P3.3 (pin 13)
 * Pushbutton switch is connected to P3.3 (pin 12):
 * when button is pushed, P3.2 is connected to ground
 */

int main() {
	/* set all P3 bits high to enable pull-ups */
	P3 = 0xFF;

	for (;;) {
#if 0
		/* it seems that when the pushbutton pulls P3.2 low,
		 * it STAYS low, so write a 1 to it before reading */
		P3 |= 4;
#endif
		if (P3 & 4) {
			/* button not pressed: set P3.3 high (LED off) */
			P3 |= 8;
		} else {
			/* button pressed: set P3.3 low (LED on) */
			P3 &= ~8;
		}
	}
}

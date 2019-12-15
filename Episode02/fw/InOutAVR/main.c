#include <avr/io.h>
#include <stdint.h>

/*
 * InOut test program for attiny2313
 *
 * LED cathode is connected to PD0 (pin 2)
 * Pushbutton switch is connected to PD1 (pin 3)
 * when button is pushed, PD1 is connected to ground
 */

#define LED_BIT (1 << 0)
#define SW_BIT  (1 << 1)

int main() {
	/* Set PD1 as input, all other PD pins as output */
	DDRD = ~SW_BIT;

	/* Initially set all PD output pins to high, and
	 * enable pull-up on PD1 */
	PORTD = 0xFF;

	for (;;) {
		if (PIND & SW_BIT) {
			/* button not pressed: set PD0 high (LED off) */
			PORTD |= LED_BIT;
		} else {
			/* button pressed: set PD0 low (LED on) */
			PORTD &= ~LED_BIT;
		}
	}
}

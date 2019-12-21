#include <mcs51/at89x051.h>
#include <stdint.h>

/*
 * Test program to monitor bits of P3 by outputting them on P1
 */

int main() {
	uint8_t val;

	/* set all P3 bits high to enable pull-ups */
	P1 = 0xFF;
	P3 = 0xFF;

	for (;;) {
/*		P3 = 0xFF;*/
		val = P3;
		P1 = val;
	}
}

#include <mcs51/at89x051.h>
#include <stdint.h>

// Assuming oscillator is 16MHz
#define INTERRUPTS_PER_SECOND 5208

volatile uint16_t timer_counter = INTERRUPTS_PER_SECOND;
uint8_t dir = 1;
volatile uint8_t val = 1;

void Timer0_ISR(void) __interrupt (1) {
    timer_counter--;
    if(timer_counter == 0) {
        timer_counter = (INTERRUPTS_PER_SECOND/8);
        if (dir) {
            val <<= 1;
        } else {
            val >>= 1;
        }
        if (val == 1 || val == 0x80) { dir = !dir; }
    }
}

/*
 * Send a byte to a 74HC595 shift register.
 * Serial data is sent on P3.0, serial data is
 * clocked by P3.1, and the output register is
 * clocked by P3.2.
 */
void sr_write(uint8_t val) {
    uint8_t i;
    for (i = 0; i < 8; i++) {
        uint8_t bitval = val & 0x80;
        if (bitval) {
            P3 |= 1;
        } else {
            P3 &= ~1;
        }
        // Pulse SCLK
        P3 |= 2;
        P3 &= ~2;
        val <<= 1;
    }
    // Pulse RCLK
    P3 |= 4;
    P3 &= ~4;
}

int main() {
    TMOD = 0x3;     // Timer mode - 8bits, no prescaler. freq = OSCFREQ/12/2^8
    TL0 = 0;        // Clear counter
    TH0 = 0;        // Clear register
    TR0 = 1;        // Set timer to run.
    ET0 = 1;        // Set interrupt.
    EA = 1;         // Set global interrupt.

    P3 = 0;

    while(1) {
        sr_write(val);
    }
}

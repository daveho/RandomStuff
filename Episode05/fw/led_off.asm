;; 8048 test program
;; Turn off the LED (cathode connected to P1.0)
;; by setting all P1 bits to 1.

.org 0x0

reset:
	jmp entry

.org 0x10

entry:
	mov A, #255
	outl P1, A

loop:
	jmp loop

;; vim:ft=asm48:

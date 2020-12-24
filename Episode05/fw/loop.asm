;; First test program for 8048/8049
;; Just goes into an infinite loop executing nop instructions

.org 0x0

;; Reset vector: jump to the main loop
reset:
	jmp entry

.org 0x10

;; Main loop
entry:
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	jmp entry

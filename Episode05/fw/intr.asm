;; 8048 timer interrupt test
;;
;; This program just generates a square wave on P1.0,
;; with the output toggling every time a timer interrupt
;; occurs.

.org 0x0

reset:
	jmp entry

.org 0x7

timer_int:
	jmp timer_event

.org 0x10

entry:
	;; initialization: enable timer interrupt
	mov R0, #0x0           ; R0 contains value to write to P1
	strt t                 ; start timer
	en tcnti               ; enable timer interrupt

	;; main loop: repeatedly copy R0 to P1
loop:
	mov A, R0
	outl P1, A
	jmp loop

timer_event:
	mov A, R0
	xrl A, #0x1
	mov R0, A
	retr

;; vim:ft=asm48:

;; 8048 timer interrupt test (holiday version)
;;
;; Generates a cycling pattern on LEDs connected to
;; P1.7 through P1.0

;; Pattern array is stored in data memory locations
;; 32, 33, and 34
.equ pattern_array, 32

;; How many times timer interrupt must occur before pattern
;; is cycled.  The timer interrupt occurs about 92 times per
;; second, so cycling every 45 timer interrupts updates the
;; pattern about 2 times per second.
.equ cycle_count, 45

.org 0x0

reset:
	jmp entry

.org 0x7

timer_int:
	jmp timer_event

.org 0x10

entry:
	;; set values in pattern array
	mov R0, #pattern_array
	mov @R0, #0x6D
	mov R0, #pattern_array+1
	mov @R0, #0xB6
	mov R0, #pattern_array+2
	mov @R0, #0xDB

	;; R4 is the countdown value: controls how many more
	;; timer interrupts must occur before the pattern is cycled
	mov R4, #cycle_count

	;; R2 contains 0, 1, or 2 depending on which pattern is being
	;; generated
	mov R2, #0

	;; enable timer interrupt
	strt t                 ; start timer
	en tcnti               ; enable timer interrupt

	;; main loop: repeatedly copy R0 to P1
loop:
	mov A, R0
	outl P1, A
	jmp loop

timer_event:
	;; Count down, checking to see if countdown reached 0
	djnz R4, timer_event_done

	;; countdown reached 0, so cycle the pattern
	mov R4, #cycle_count   ; reset countdown
	inc R2                 ; increment pattern count
	mov A, R2              ; move pattern count to A
	inc A                  ; increment: if pattern count is 3, A is 4
	anl A, #0x4            ; see if pattern count reached 3
	jz gen_pattern         ; if not, continue
	mov R2, #0             ; pattern count reached 3, so reset

gen_pattern:
	mov A, #pattern_array  ; base address of pattern array
	add A, R2              ; add offset to select element
	mov R1, A              ; load element address to R1
	mov A, @R1             ; retrieve element value
	mov R0, A              ; copy element value to R0

timer_event_done:
	retr

;; vim:ft=asm48:

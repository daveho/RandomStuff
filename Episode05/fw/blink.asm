;; 8048 LED blink program
;; LED cathode is connected to P1.0, so driving it low
;; should sink current and light the LED

.org 0x0

reset:
	jmp entry

.org 0x10

entry:
	mov A, #255                   ; set all A bits to 1
	outl P1, A                    ; output to port 1 (LED will be OFF)
	call delay                    ; delay
	mov A, #0                     ; set all A bits to 0
	outl P1, A                    ; output to port 1 (LED will be ON)
	call delay                    ; delay
	jmp entry                     ; repeat main loop

delay:
	mov R0, #255                  ; init outer loop counter
delay_outer:
	mov R1, #255                  ; init inner loop counter
delay_inner:
	nop                           ; waste some cycles
	nop
	nop
	nop
	djnz R1, delay_inner          ; dec inner count, continue if not zero
	djnz R0, delay_outer          ; dec outer count, continue if not zero

	ret                           ; return to caller

;; vim:ft=asm48:

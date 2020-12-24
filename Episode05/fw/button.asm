;; 8048 button press program
;;
;; * pushbutton is connected to P1.7; when the button
;;   is pressed, P1.7 is connected to ground
;; * LED cathode is connected to P1.0, so driving it low
;;   will sink current and light the LED
;;
;; The program lights the LED when the button is pressed.

.org 0x0

reset:
	jmp entry

.org 0x10

entry:
	mov R0, #0xFF                 ; R0 is value to output to P1

loop:
	mov A, R0                     ; get value to output to P1
	outl P1, A                    ; output to P1

	in A, P1                      ; read P1
	anl A, #0x80                  ; see if high bit is set
	jnz button_not_pressed

	;; button is pressed
	mov R0, #0xFE                 ; drive P1.0 low, LED is on
	jmp loop

button_not_pressed:
	mov R0, #0xFF                 ; drive P1.0 high, LED is off
	jmp loop

;; vim:ft=asm48:

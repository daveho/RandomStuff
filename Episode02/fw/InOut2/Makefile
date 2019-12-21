all : InOut2.ihx

InOut2.ihx : main.c
	sdcc -mmcs51 --code-size 2048 main.c -o $@

clean:
	rm -rf *.ihx *.lk *.lst *.map *.mem *.rel *.rst *.sym *.asm

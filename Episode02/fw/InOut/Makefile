all : InOut.ihx

InOut.ihx : main.c
	sdcc -mmcs51 --code-size 2048 main.c -o $@

clean:
	rm -rf *.ihx *.lk *.lst *.map *.mem *.rel *.rst *.sym *.asm

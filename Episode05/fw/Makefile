%.bin : %.asm
	asm48 -o $*.bin $*.asm

all : loop.bin button.bin intr.bin merry.bin

clean :
	rm -f *.bin

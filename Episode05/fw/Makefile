%.bin : %.asm
	asm48 -o $*.bin $*.asm

all : loop.bin led_off.bin led_on.bin

clean :
	rm -f *.bin

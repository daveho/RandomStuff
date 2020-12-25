# Experiments with 8048 family microcontrollers

Video link: Coming soon

In this episode, we experiment with 8048 family microcontrollers.

The [hw](hw) directory has KiCad schematic(s) for the example circuit.

The [fw](fw) directory has example programs.  You'll need [asm48](https://daveho.github.io/asm48/) to assemble them.

There are two schematics for the circuits demonstrated in the video:

* [8048 LED Blink circuit](hw/8048_Blink/8048_Blink.pdf)
* [8048 LED Blink circuit with pushbutton](hw/8048_Blink/8048_Blink-button.pdf)

It's not mentioned anywhere, but I used an 11.0592 MHz crystal.

## Resources

* [asm48](https://daveho.github.io/asm48/): 8048 cross assembler, originally written by me, but greatly enhanced by JustBurn and sy2002
* [8048 maze generator](https://hackaday.io/project/19278-8048-maze-generator): good example of a schematic incorporating the 8048, address latch, and external ROM (this was my starting point)
* [MCS-48 Family User's Manual](http://bitsavers.trailing-edge.com/components/intel/8048/9800270D_MCS-48_Family_Users_Manual_Jul78.pdf): Intel documentation for 8048 family from 1978
* [MCS-48 and UPI-41 Assembly Language Manual](http://bitsavers.trailing-edge.com/components/intel/8048/9800255D_MCS-48_and_UPI-41_Assembly_Language_Manual_Dec1978.pdf): best resource for assembly language programming of 8048 family devices

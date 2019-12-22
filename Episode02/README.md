# Episode 2: Digital I/O: AVR vs. 8051

Link to video: <https://youtu.be/I_YL9chcnso>

This video explores an important difference in how digital I/O works on AVR and 8051-family microcontrollers, and shows how to implement robust digital I/O on the 8051 using bit instructions.

The [fw](fw) directory has the example firmware programs.

The [hw](hw) directory has a KiCad schematic for the minimal 80C32 circuit shown in the video. (It also works for 8031, and should work with 8051/8052 devices as well.)  The at89c2051 circuit is the same as the one in [Episode 1](../Episode01).  I didn't create a schematic for the attiny2313 circuit since it is trivial.

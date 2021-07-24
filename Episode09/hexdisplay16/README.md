# hexdisplay16

The [KiCad](https://kicad.org/) schematics and PCB designs for the 16-bit
hex display are in this directory.

Parts list:

Component | Description                               | Value  | Footprint
--------- | ----------------------------------------- | ------ | --------------
C1        | ceramic capacitor                         | 100 nF | 1206
R1-R7     | LED segment current limiting resistor     | (a)    | 0805
R8-R11    | transistor base resistor                  | 4.7 kΩ | 0805
Q1-Q4     | MMBT3906 PNP transistor                   | (b)    | SOT-23
U1        | atmega164a microcontroller                | (f)    | TQFP-44
J11/J12, J21/J22, J31/J32, J41/J42 | common anode hex display  | (c)    | 0.2" DIP-10
J5        | 2 pos pin header (breadboard power rails) | (d)    | 2.54mm spacing
J6        | 16 pos pin header (breadboard input)      | (d)    | 2.54mm spacing
J7        | 6 pos pin header (AVR programming header) | (e)    | 2.54mm spacing

(a) I used 110Ω resistors.

(b) The transistor should be able to handle at least 100 mA of current.
(Most parts marked as MMBT3906 that I've seen will handle 150 mA or more.)

(c) 0.2" DIP-10 common anode 7-segment displays, specifically
[SUNLIGHT SLR0361DBA3BD-4.0](https://lcsc.com/product-detail/Led-Segment-Display_SUNLIGHT-SLR0361DBA3BD-4-0_C225953.html).  The common anodes should be on pins 1 and 6.
(And you should check to make sure the cathode pins are in the right places.)

(d) I prefer machined pin headers, since these will be inserted into the
breadboard, and the thinner pins are less likely to deform the metal clips
inside the breadboard.

(e) I use the cheaper square profile pin headers for this connector, since
it's only used when programming the microcontroller.

(f) The atmega324a will also work.  I'm guessing other members of the family
(with the same pinout) should work, too. Just make sure it's in
a TQFP-44 package.

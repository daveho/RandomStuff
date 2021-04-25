# hexdisplay8

The [KiCad](https://kicad.org/) schematics and PCB designs for the 8-bit
hex display are in this directory.

Parts list:

Component | Description                               | Value  | Footprint
--------- | ----------------------------------------- | ------ | --------------
C1        | ceramic capacitor                         | 100 nF | 1206
R1-R7     | LED segment current limiting resistor     | (a)    | 0805
R8, R9    | transistor base resistor                  | 4.7 kΩ | 0805
Q1, Q2    | MMBT3906 PNP transistor                   | (b)    | SOT-23
U1        | attiny2313a microcontroller               |        | SOIC-20
J1, J2    | common anode hex display                  | (c)    | DIP-10
J3        | 2 pos pin header (breadboard power rails) | (d)    | 2.54mm spacing
J4        | 8 pos pin header (breadboard input)       | (d)    | 2.54mm spacing
J5        | 6 pos pin header (AVR programming header) | (e)    | 2.54mm spacing

(a) The value will depend greatly on the type of LED used in the displays.
220 Ω is reasonable for most standard-brightness LEDs, although a lower value
might be better.  Modern bright LEDs will likely require a larger resistor
value.

(b) The transistor should be able to handle at least 100 mA of current.
(Most parts marked as MMBT3906 that I've seen will handle 150 mA or more.)

(c) HDSP-F501 or similar.  The common anodes should be on pins 1 and 6.
(And you should check to make sure the cathode pins are in the right places.)

(d) I prefer machined pin headers, since these will be inserted into the
breadboard, and the thinner pins are less likely to deform the metal clips
inside the breadboard.

(e) I use the cheaper square profile pin headers for this connector, since
it's only used when programming the microcontroller.

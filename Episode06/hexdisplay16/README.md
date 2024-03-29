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
J1-J4     | common anode hex display                  | (c)    | DIP-10
J5        | 2 pos pin header (breadboard power rails) | (d)    | 2.54mm spacing
J6        | 16 pos pin header (breadboard input)      | (d)    | 2.54mm spacing
J7        | 6 pos pin header (AVR programming header) | (e)    | 2.54mm spacing

(a) The value will depend greatly on the type of LED used in the displays.
220 Ω is likely too high for standard-brightness LEDs, since the displays
are only lit 1/4 of the time.  I'm guessing 100 Ω or so will work better for
standard-brightness LEDs, but I haven't been able to test this theory.
Modern bright LEDs will likely require a larger resistor value.
In general, 1/8 W rated resistors should be fine.

(b) The transistor should be able to handle at least 100 mA of current.
(Most parts marked as MMBT3906 that I've seen will handle 150 mA or more.)

(c) HDSP-F501 or similar.  The common anodes should be on pins 1 and 6.
(And you should check to make sure the cathode pins are in the right places.)

(d) I prefer machined pin headers, since these will be inserted into the
breadboard, and the thinner pins are less likely to deform the metal clips
inside the breadboard.

(e) I use the cheaper square profile pin headers for this connector, since
it's only used when programming the microcontroller.

(f) I think that other members of this series, such as the atmega324,
atmega644, and atmega1284 will also work.  Just make sure it's in
a TQFP-44 package.

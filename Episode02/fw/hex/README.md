# Hex files for 8051 firmware test programs

This directory has the compiled and linked Intel Hex files for the 8051 test firmware programs.

[InOut.hex](InOut.hex) is the original "buggy" program where the initial button press sets the corresponding bit to 0 and subsequently fails to read any other input changes.

[InOut2.hex](InOut2.hex) is the fixed version which uses bit access instructions.

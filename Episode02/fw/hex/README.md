# Hex files for 8051 firmware test programs

This directory has the compiled and linked Intel Hex files for the 8051 test firmware programs.

[InOut.ihx](InOut.ihx) is the original "buggy" program where the initial button press sets the corresponding bit to 0 and subsequently fails to read any other input changes.

[InOut2.ihx](InOut2.ihx) is the fixed version which uses bit access instructions.

These files were generated using SDCC 3.5.0 (default version from the package repository) on Linux Mint 18.3, which is based on Ubuntu 16.04.

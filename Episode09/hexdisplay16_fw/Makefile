PROG = hexdisplay16

# Uncomment for atmega164a
GCC_MCU = atmega164a
AVRDUDE_MCU = m164a

# Uncomment for atmega324pa
#GCC_MCU = atmega324pa
#AVRDUDE_MCU = m324pa

CC = avr-gcc
CFLAGS = -Os -Wall $(POWER_MODE) \
	-mmcu=$(GCC_MCU) -funsigned-bitfields -fpack-struct -fshort-enums -std=gnu99

OBJCOPY = avr-objcopy

# If the AVR programmer appears as a serial port, define it here
#AVRDUDE_PORT = /dev/ttyUSB0
#AVRDUDE_PORT = COM4

# Uncomment one of the following options depending on what
# AVR programmer you are using

# This is correct for the $10 USB programmer from alldav.com
#AVRDUDE_OPTIONS = -P $(AVRDUDE_PORT) -c stk500v2

# USBtinyISP, either the real one from Adafruit, or a clone
AVRDUDE_OPTIONS = -c usbtiny

# Avrdude flags
AVRDUDE_FLAGS = 

# Note that the default target just builds the hex file:
# use "make program" to burn it to the device
all : $(PROG).hex

$(PROG).o : $(PROG).c
	$(CC) $(CFLAGS) -c $(PROG).c -o $(PROG).o

$(PROG).elf : $(PROG).o
	$(CC) -mmcu=$(GCC_MCU) $(PROG).o -o $@ -Wl,-Map=$(PROG).map,--cref -lm

$(PROG).hex : $(PROG).elf
	$(OBJCOPY) -O ihex -R .eeprom $(PROG).elf $(PROG).hex

program : $(PROG).hex
	avrdude -p $(AVRDUDE_MCU) $(AVRDUDE_OPTIONS) $(AVRDUDE_FLAGS) -U flash:w:$(PROG).hex

clean :
	rm -f *.o *.elf *.hex *.map

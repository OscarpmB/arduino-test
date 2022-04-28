default:
	avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o temperature.o temperature.c
	avr-gcc -o temperature.bin temperature.o
	avr-objcopy -O ihex -R .eeprom temperature.bin temperature.hex
	sudo avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:temperature.hex

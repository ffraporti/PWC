all: link
	avr-objcopy -j .text -j .data -O ihex main.elf main.hex

link: main_compile private_utils_compile public_utils_compile
	avr-gcc -Wl,-Map,main.map -mmcu=atmega8 -o "main.elf"  ./src/private_utils.o ./src/public_utils.o  ./main.o

main_compile:
	avr-gcc -O0 -Wall -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega8 -DF_CPU=8000000UL -MMD -MP -MF"main.d" -MT"main.o" -c -o "main.o" "main.c" 

private_utils_compile:
	avr-gcc -Wall -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega8 -DF_CPU=8000000UL -MMD -MP -MF"src/private_utils.d" -MT"src/private_utils.o" -c -o "src/private_utils.o" "./src/private_utils.c"

public_utils_compile:
	avr-gcc -Wall -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega8 -DF_CPU=8000000UL -MMD -MP -MF"src/public_utils.d" -MT"src/public_utils.o" -c -o "src/public_utils.o" "./src/public_utils.c"

flash:
	avrdude -c stk500v1 -p m8 -P /dev/ttyUSB0 -U flash:w:'/home/breno/Documentos/git projects/PWC/Release/PWC.hex' -b 19200 -U lfuse:w:0xd1:m

flashMain:
	avrdude -c stk500v1 -p m8 -P /dev/ttyUSB1 -U flash:w:'/home/breno/Documentos/git projects/PWC/main.hex' -b 19200 -U lfuse:w:0xd4:m

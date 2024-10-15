# Makefile for programming ATmega32 microcontroller

# Compiler
CC = avr-gcc
AS = avr-as
FLASHER=avrdude
SIZE=avr-size
ARCH=avr
MCU=atmega32
FRQ=1000000UL

# Compiler flags
CFLAGS = -mmcu=$(MCU) -DF_CPU=$(FRQ) -Wall -gdwarf-2 -g -O0
#-ffunction-sections -fdata-sections -Wl,--gc-sections

# Linker flags
#LDFLAGS = -T linker.ld

# Programmer
#PROGRAMMER = avrdude
PROG_FLAGS = -c usbasp -p m32 -B 0.5 -U Flash:w:${PROJECT_NAME}.hex:a
SIZE_FLAGS=--format=$(ARCH) --mcu=$(MCU)

# Source files
C_SRCS:=$(wildcard ./*/*.c)
C_SRCS+=$(wildcard ./*/*/*.c)
C_SRCS+=$(wildcard *.c)
D_SRCS:=$(wildcard ./*/*.d)
D_SRCS+=$(wildcard ./*/*/*.d)
O_SRCS:=$(wildcard ./*/*.o)
O_SRCS+=$(wildcard ./*/*/*.o)
ASM_SRCS=$(wildcard *.S)


# Object files
C_OBJS = $(C_SRCS:.c=.o)
ASM_OBJS = $(ASM_SRCS:.S=.o)
DEP = $(C_OBJS:.o=.d)

# Target file
PROJECT_NAME = _Mahmoud_Driver

all: $(PROJECT_NAME).hex
	@echo "====================BUild Done=================="

#-include $(DEP)
%.o: %.c
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

%.o: %.S
	$(AS) -MMD -MP $< -o $@

$(PROJECT_NAME).hex: $(PROJECT_NAME).elf
	avr-objcopy -j .text -j .data -O ihex $< $@
	@$(SIZE) $(SIZE_FLAGS) $(PROJECT_NAME).elf

$(PROJECT_NAME).elf: $(C_OBJS) $(ASM_OBJS)
	$(CC) $(CFLAGS) -Wl,-Map,output.map $(C_OBJS) $(ASM_OBJS) -o $@

flash : $(PROJECT_NAME).hex 
	@$(FLASHER) $(PROG_FLAGS)
	#@echo flashing done

#program: $(PROJECT_NAME).hex
#	$(PROGRAMMER) $(PROG_FLAGS) -U flash:w:$<

cleanhex:
	rm -f *.elf *.hex 

clean:
	rm -f *.elf *.hex $(D_SRCS) $(O_SRCS) ./*.d ./*.o
	#@echo every thing is clean
#@copyright Mahmoud eid
CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m3 -mthumb -gdwarf-2
INCS= -I . 
LIBS=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
AS = $(wildcard *.s)
ASOBJ = $(AS:.s=.o)
Project_name=pressureController

all: $(Project_name).bin
	@echo "============== Build done successfully:) =================="

%.o: %.c
	$(CC)gcc $(CFLAGS) -c $(INCS) $< -o $@
startup.o: startup.s
	$(CC)as $(CFLAGS) $< -o $@
$(Project_name).elf: $(OBJ) $(ASOBJ)
	$(CC)ld -T linker_script.ld $(LIBS) $(OBJ) $(ASOBJ) -o $@ -Map=map_file
$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy -O binary $< $@

clean_all:
	rm *.o *.elf *.bin
clean: 
	rm *.elf *.bin
#@Eng_mahmoud Eid
CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m3 -mthumb -gdwarf-2
INCS=-I .
LIBS=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
AS=$(wildcard *.s)
ASOBJ=$(AS:.s=.o)
NAME_PROJECT=pressure_project
all:$(NAME_PROJECT).bin
	@echo"==================Done=============================="
#app.o:app.c
#	$(CC)gcc.exe -c  $(INCS) $(CFLAGS) $< -o $@
%.o:%.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@
%.o:%.s
	$(CC)as.exe -c  $(CFLAGS) $< -o $@
$(NAME_PROJECT).elf:$(OBJ) $(ASOBJ)
	$(CC)ld.exe -T Linker_script.ld -Map=output.map $(LIBS) $(OBJ) $(ASOBJ) -o $@
$(NAME_PROJECT).bin:$(NAME_PROJECT).elf
	$(CC)objcopy.exe -O binary $< $@

clean_all:
	rm *.o *.bin *.elf
clean:
	rm *.elf *.bin
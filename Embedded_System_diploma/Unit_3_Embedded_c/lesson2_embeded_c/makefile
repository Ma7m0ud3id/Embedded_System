#@Eng_mahmoud Eid
CC=arm-none-eabi-
CFLAGS=-mcpu=arm926ej-s -g
INCS=-I .
LIBS=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
AS=$(wildcard *.s)
ASOBJ=$(AS:.s=.o)

all:learn_in_depth.elf
	@echo"==================Done=============================="
#app.o:app.c
#	$(CC)gcc.exe -c  $(INCS) $(CFLAGS) $< -o $@
%.o:%.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@
%.o:%.s
	$(CC)as.exe -c  $(CFLAGS) $< -o $@
learn_in_depth.elf:$(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linker_script.ld -Map=output.map $(LIBS) $(OBJ) $(ASOBJ) -o $@

clean_all:
	rm *.o *.bin *.elf
clean:
	rm *.elf *.bin

OBJECTS = ioe.o str.o put.o str-cpy.o vec.o dic.o lng.o

AC = nasm -f elf64

all: $(OBJECTS)

ioe.o:
	$(AC) ioe.asm

str.o:
	$(AC) str.asm

put.o:
	$(CC) put.c -c

str-cpy.o:
	$(CC) str-cpy.c -c

vec.o:
	$(CC) vec.c -c

dic.o:
	$(CC) dic.c -c

lng.o:
	$(CC) lng.c -c

clean:
	$(RM) $(OBJECTS)


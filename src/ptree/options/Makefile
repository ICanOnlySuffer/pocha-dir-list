
OBJECTS = help.o listing.o number.o other.o printing.o sorting.o

AC = nasm -f elf64

all: $(OBJECTS)

help.o:
	$(CC) help.c -c

listing.o:
	$(CC) listing.c -c

number.o:
	$(CC) number.c -c

other.o:
	$(CC) other.c -c

printing.o:
	$(CC) printing.c -c

sorting.o:
	$(CC) sorting.c -c

clean:
	$(RM) $(OBJECTS)


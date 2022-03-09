
OBJECTS = file.o lang.o options.o size.o tree.o

AC = nasm -f elf64

all: $(OBJECTS)

file.o:
	$(CC) file.c -c

lang.o:
	$(CC) lang.c -c

options.o:
	$(CC) options.c -c

size.o:
	$(CC) size.c -c

tree.o:
	$(CC) tree.c -c

clean:
	$(RM) $(OBJECTS)


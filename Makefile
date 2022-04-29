
NAME = "Pocha's tree visualizer"
VERSION = "v1.5.1"
DEVELOPER = "Piero Estéfano Rojas Effio"
LICENSE = "GNU General Public License v3.0"

OS := $(shell uname -o)

ifeq ($(OS), GNU/Linux)
	DIR_BIN = /usr/bin
	DIR_LIB = /usr/lib
	DIR_SHR = /usr/share
	DIR_INSTALL_BIN := $(DIR_INSTALL)/usr/bin
	DIR_INSTALL_SHR := $(DIR_INSTALL)/usr/share
	BIN = bin/ptv
else
all: $(error operating system `$(OS)` not supported)
endif

SRC = $(shell find src -type f ! -name ptv.c)
LIB = $(addprefix $(DIR_LIB), /pul/{str,put,num,vec,cnf,dic}.o)
OBJ = $(SRC:src/%.c=obj/%.o)
DIR_SRC = $(shell find src -type d)
DIR_OBJ = $(DIR_SRC:src/%=obj/%/)

C_DEFIS = -DVERSION='$(VERSION)' \
          -DDEVELOPER='$(DEVELOPER)' \
          -DLICENSE='$(LICENSE)'
C_FLAGS = -Iinc/ -O3

all: $(BIN)

%/:
	mkdir -p $@

obj/option/miscellaneous.o: src/option/miscellaneous.c
	$(CC) $< -o $@ -c $(C_FLAGS) $(C_DEFIS)

obj/%.o: src/%.c
	$(CC) $< -o $@ -c $(C_FLAGS)

$(BIN): src/ptv.c bin/ $(DIR_OBJ) $(OBJ)
	$(CC) $(LIB) $(OBJ) $< -o $@ $(C_FLAGS) -DDIR_SHR='"$(DIR_SHR)"'

install: uninstall $(BIN) $(DIR_INSTALL_SHR)/ptv/ $(DIR_INSTALL_BIN)/
	cp -ur shr/* $(DIR_INSTALL_SHR)/ptv
	cp -u $(BIN) $(DIR_INSTALL_BIN)/ptv

uninstall:
	rm -rf $(DIR_INSTALL_SHR)/ptv
	rm -rf $(DIR_INSTALL_BIN)/ptv

clean:
	rm -rf obj/ bin/


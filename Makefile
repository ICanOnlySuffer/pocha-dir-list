
NAME = "Pocha's Tree Visualizer"
VERSION = "v1.5.1"
DEVELOPER = "Piero Estéfano Rojas Effio"
LICENSE = "GNU General Public License v3.0"

KERNEL := $(shell uname -s)

ifeq ($(KERNEL), Linux)
	PREFIX := $(if $(PREFIX),$(PREFIX),/usr)
	BIN_DIR = $(PREFIX)/bin
	SHR_DIR = $(PREFIX)/share
	INSTALL_BIN_DIR := $(INSTALL_DIR)$(BIN_DIR)
	INSTALL_SHR_DIR := $(INSTALL_DIR)$(SHR_DIR)
	BIN = bin/ptv
else
all: $(error kernel `$(KERNEL)` not supported)
endif

SRC = $(shell find src -type f ! -name ptv.c)
OBJ = $(SRC:src/%.c=obj/%.o)
SRC_DIR = $(shell find src -type d)
OBJ_DIR = $(SRC_DIR:src/%=obj/%/)

C_DEFIS = -DVERSION='$(VERSION)' \
          -DDEVELOPER='$(DEVELOPER)' \
          -DLICENSE='$(LICENSE)'
C_FLAGS = -O3 -Wall -pedantic

all: $(BIN)

%/:
	mkdir -p $@

obj/option/miscellaneous.o: src/option/miscellaneous.c
	$(CC) $< -o $@ -c $(C_FLAGS) $(C_DEFIS)

obj/%.o: src/%.c
	$(CC) $< -o $@ -c $(C_FLAGS)

$(BIN): src/ptv.c bin/ $(OBJ_DIR) $(OBJ)
	$(CC) $(OBJ) $< -o $@ $(C_FLAGS) -lpul -DSHR_DIR='"$(SHR_DIR)"'
	strip $@

install: uninstall $(BIN) $(INSTALL_SHR_DIR)/ptv/ $(INSTALL_BIN_DIR)/
	cp -ur shr/* $(INSTALL_SHR_DIR)/ptv
	cp -u $(BIN) $(INSTALL_BIN_DIR)/ptv

uninstall:
	rm -rf $(INSTALL_SHR_DIR)/ptv
	rm -rf $(INSTALL_BIN_DIR)/ptv

clean:
	rm -rf obj/ bin/


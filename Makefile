
TARGET = pdt

KERNEL := $(shell uname)
ifeq ($(KERNEL), Linux)
	PREFIX := $(if $(PREFIX),$(PREFIX),/usr)
	BIN_DIR = $(PREFIX)/bin
	SHR_DIR = $(PREFIX)/share
	INSTALL_BIN_DIR := $(INSTALL_DIR)$(BIN_DIR)
	INSTALL_SHR_DIR := $(INSTALL_DIR)$(SHR_DIR)
	BIN = bin/$(TARGET)
else
all: $(error kernel `$(KERNEL)` not supported)
endif

SRC = $(shell find src -type f ! -name $(TARGET).c)
OBJ = $(SRC:src/%.c=obj/%.o)
SRC_DIR = $(shell find src -type d)
OBJ_DIR = $(SRC_DIR:src/%=obj/%/)

C_FLAGS = -O3 -Wall -Wextra -pedantic -g3

all: $(BIN)

obj/%.o: src/%.c
	@mkdir -p $(OBJ_DIR)/
	$(CC) $< -o $@ -c $(C_FLAGS)

$(BIN): src/$(TARGET).c $(OBJ)
	@mkdir -p bin/
	$(CC) $(OBJ) $< -o $@ $(C_FLAGS) -lpul -DSHR_DIR='"$(SHR_DIR)"'
	strip $@

install: uninstall all
	@mkdir -p $(INSTALL_SHR_DIR)/$(TARGET)/
	@mkdir -p $(INSTALL_BIN_DIR)/
	cp -ur shr/* $(INSTALL_SHR_DIR)/$(TARGET)
	cp -u $(BIN) $(INSTALL_BIN_DIR)/$(TARGET)

uninstall:
	rm -rf $(INSTALL_SHR_DIR)/$(TARGET)
	rm -rf $(INSTALL_BIN_DIR)/$(TARGET)

clean:
	rm -rf obj/ bin/


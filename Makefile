
OS := $(shell uname -o)

ifeq ($(OS), GNU/Linux)
	DIR_BIN = usr/bin
	DIR_SHARE = usr/share
endif
ifeq ($(OS), Android)
	DIR_BIN = data/data/com.termux/files/usr/bin
	DIR_SHARE = data/data/com.termux/files/usr/share
endif

C_FLAGS = -Iinclude/ -O3

LIB_PTREE = $(foreach obj, file lang options size tree, lib/$(obj).o) $(foreach obj, help listing number other printing sorting, lib/options/$(obj).o)
BIN_PTREE = bin/ptree
OBJECTS = lib/*.o lib/options/*.o /usr/lib/putils/*.o

all: lib/options/ $(LIB_PTREE) bin/ $(BIN_PTREE)

%/:
	mkdir -p $@

lib/%.o: src/%.c
	$(CC) $(C_FLAGS) -c $< -o $@

lib/options/%.o: src/options/%.c
	$(CC) $(C_FLAGS) -c $< -o $@

bin/%: src/%.c
	$(CC) $(C_FLAGS) $(OBJECTS) -DDIR_SHARE='"$(DIR_SHARE)"' $< -o $@

install: all $(DEST_DIR)/$(DIR_SHARE)/ptree/
	cp -TR share/lang $(DEST_DIR)/$(DIR_SHARE)/ptree/lang
	install -Dm755 bin/ptree $(DEST_DIR)/$(DIR_BIN)/ptree

uninstall:
	rm -rf $(DEST_DIR)/$(DIR_SHARE)/ptree $(DEST_DIR)/$(DIR_BIN)/ptree

clean:
	rm -rf lib/ bin/


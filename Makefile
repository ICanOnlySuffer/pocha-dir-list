
OS := $(shell uname -o)
PREFIX := /usr
BUILD := $(DEST_DIR)$(PREFIX)

C_FLAGS = -Iinclude/ -O3

LIB = $(foreach obj, file lang option tree, lib/$(obj).o) $(foreach obj, printing listing sorting miscellaneous, lib/option/$(obj).o)

all: lib/option/ $(LIB) bin/ bin/ptv

%/:
	mkdir -p $@

lib/%.o: src/%.c
	$(CC) $(C_FLAGS) -c $< -o $@

lib/option/%.o: src/option/%.c
	$(CC) $(C_FLAGS) -c $< -o $@

bin/%: src/%.c
	$(CC) $(C_FLAGS) $(LIB) /usr/lib/pul/*.o -DPREFIX='"$(PREFIX)"' $< -o $@

install: uninstall all $(BUILD)/share/ptv/ $(BUILD)/bin/
	cp -ur share/* $(BUILD)/share/ptv/
	cp -u bin/ptv $(BUILD)/bin/ptv

uninstall:
	rm -rf $(BUILD)/share/ptv
	rm -rf $(BUILD)/bin/ptv

clean:
	rm -rf lib/ bin/



UNAME_S := $(shell uname -o)

ifeq ($(UNAME_S), GNU/Linux)
	BIN_DIR = /usr/bin/
	SHARE_DIR = /usr/share/
	PUTILS_SRC = c_putils/
endif
ifeq ($(UNAME_S), Android)
	BIN_DIR = /data/data/com.termux/files/usr/bin/
	SHARE_DIR = /data/data/com.termux/files/usr/share/
	PUTILS_SRC = c_putils/
endif

BUILD_DIR = build/
TARGET = ptree

AC      = nasm
A_FLAGS = -f elf64
C_FLAGS = -O

define objs
	$(foreach obj, $2, $(BUILD_DIR)$1$(obj).o)
endef


DIRS    = $(BUILD_DIR) $(addprefix $(BUILD_DIR), putils ptree ptree/options)
PUTILS  = $(call objs,putils/, str put vec dic lng)
PTREE   = $(call objs,ptree/, file lang options size tree)
OPTIONS = $(call objs,ptree/options/, help listing number other printing sorting)
OBJECTS = $(PUTILS) $(PTREE) $(OPTIONS)

all: $(DIRS) $(OBJECTS) $(BUILD_DIR)$(TARGET).bin

$(DIRS):
	mkdir $@

$(BUILD_DIR)putils/%.o: src/$(PUTILS_SRC)%.c
	$(CC) $(C_FLAGS) -Isrc/$(PUTILS_SRC) -o $@ $< -c

$(BUILD_DIR)putils/%.o: src/$(PUTILS_SRC)%.asm
	$(AC) $(A_FLAGS) -Isrc/$(PUTILS_SRC) -o $@ $<

$(BUILD_DIR)$(TARGET)/%.o: src/$(TARGET)/%.c
	$(CC) $(C_FLAGS) -Isrc/$(PUTILS_SRC) -o $@ $< -c

$(BUILD_DIR)$(TARGET)/%.o: src/$(TARGET)/%.asm
	$(AC) $(A_FLAGS) -Isrc/$(PUTILS_SRC) -o $@ $<

$(BUILD_DIR)$(TARGET)/options/%.o: src/$(TARGET)/options/%.c
	$(CC) $(C_FLAGS) -Isrc/$(PUTILS_SRC) -o $@ $< -c

$(BUILD_DIR)$(TARGET)/options/%.o: src/$(TARGET)/options/%.asm
	$(AC) $(A_FLAGS) -Isrc/$(PUTILS_SRC) -o $@ $<

$(BUILD_DIR)$(TARGET).bin: src/$(TARGET).c
	$(CC) $(C_FLAGS) $(OBJECTS) -DSHARE_DIR='"$(SHARE_DIR)"' -Isrc/$(PUTILS_SRC) -o $@ $<

install: lang build/$(TARGET).bin
	mkdir -p $(DEST_DIR)$(SHARE_DIR)$(TARGET)
	cp -TR lang $(DEST_DIR)$(SHARE_DIR)$(TARGET)/lang
	install -Dm755 build/$(TARGET).bin $(DEST_DIR)$(BIN_DIR)$(TARGET)

uninstall:
	$(RM) -rf $(DEST_DIR)$(SHARE_DIR)$(TARGET)
	$(RM) -r $(DEST_DIR)$(BIN_DIR)$(TARGET)

clean:
	$(RM) -r $(BUILD_DIR)


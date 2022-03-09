
UNAME_S := $(shell uname -o)

ifeq ($(UNAME_S), GNU/Linux)
	PREFIX_BIN = /usr/bin/
	PREFIX_SHARE = /usr/share/
endif
ifeq ($(UNAME_S), Android)
	PREFIX_BIN = /data/data/com.termux/files/usr/bin/
	PREFIX_SHARE = /data/data/com.termux/files/usr/share/
endif

TARGET = ptree

PTREE = src/ptree
PUTILS = src/putils
PTREE_OPTIONS = src/ptree/options

OBJECTS = $(PTREE)/*.o $(PUTILS)/*.o $(PTREE_OPTIONS)/*.o

CDEFS = -DPREFIX_BIN=\"$(PREFIX_BIN)\" -DPREFIX_SHARE=\"$(PREFIX_SHARE)\"
CFLAGS = -Ofast

MKDIR = mkdir -pv
CP = cp -TRv
RM = rm -rfv

all:
	$(MAKE) -C $(PTREE)
	$(MAKE) -C $(PUTILS)
	$(MAKE) -C $(PTREE_OPTIONS)
	$(MKDIR) $(DESTDIR)$(PREFIX_SHARE)$(TARGET)
	$(CP) -TRv lang $(DESTDIR)$(PREFIX_SHARE)$(TARGET)/lang
	$(CC) $(CDEFS) $(CFLAGS) $(OBJECTS) src/$(TARGET).c -o $(TARGET)

install: $(TARGET)
	install -Dm755 $(TARGET) $(DESTDIR)$(PREFIX_BIN)$(TARGET)

uninstall: $(TARGET)
	$(RM) $(DESTDIR)$(PREFIX_SHARE)$(TARGET)
	$(RM) $(DESTDIR)$(PREFIX_BIN)$(TARGET)

clean:
	$(MAKE) clean -C $(PTREE)
	$(MAKE) clean -C $(PUTILS)
	$(MAKE) clean -C $(PTREE_OPTIONS)
	$(RM) $(TARGET)


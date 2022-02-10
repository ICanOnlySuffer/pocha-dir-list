
UNAME_S := $(shell uname -o)

ifeq ($(UNAME_S), GNU/Linux)
	PREFIX = /usr
endif
ifeq ($(UNAME_S), Android)
	PREFIX = /data/data/com.termux/files/usr
endif

TARGET  = ptree
CFLAGS  = -Ofast

all: $(TARGET)

$(TARGET): src/$(TARGET).c

install: $(TARGET)
	$(CC) src/$(TARGET).c -o $(TARGET) $(CFLAGS)
	mkdir -pv $(DESTDIR)$(PREFIX)/share/$(TARGET)
	cp -TRv lang $(DESTDIR)$(PREFIX)/share/$(TARGET)/lang
	install -Dm755 $(TARGET) $(DESTDIR)$(PREFIX)/bin/$(TARGET)
	rm -v $(TARGET)

uninstall: $(TARGET)
	rm -rfv $(DESTDIR)$(PREFIX)/share/$(TARGET)
	rm -rfv $(DESTDIR)$(PREFIX)/bin/$(TARGET)


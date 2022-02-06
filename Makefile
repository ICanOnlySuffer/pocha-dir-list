
UNAME_S := $(shell uname -o)

ifeq ($(UNAME_S), GNU/Linux)
	PREFIX = /usr
endif
ifeq ($(UNAME_S), Android)
	PREFIX = /data/data/com.termux/files/usr
endif

TARGET  = ptree
CFLAGS  = -Ofast
LIBS    = -lpthread

all: $(TARGET)

$(TARGET): src/$(TARGET).c

install: $(TARGET)
	$(CC) src/$(TARGET).c -o $(TARGET) $(LIBS) $(CFLAGS)
	mkdir -pv $(DESTDIR)$(PREFIX)/share/$(TARGET)
	cp -TRv lang $(DESTDIR)$(PREFIX)/share/$(TARGET)/lang
	install -Dm755 $(TARGET) $(DISTDIR)$(PREFIX)/bin/$(TARGET)

uninstall: $(TARGET)
	rm -rf $(DESTDIR)$(PREFIX)/share/$(TARGET)
	rm $(DESTDIR)$(PREFIX)/bin/$(TARGET)

clean:
	rm $(TARGET)


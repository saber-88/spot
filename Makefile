CC = gcc
CFLAGS = -Wall -O2
TARGET = spot

all: $(TARGET)

$(TARGET): spot.c
	$(CC) $(CFLAGS) -o $(TARGET) spot.c

install: $(TARGET)
	install -m 755 $(TARGET) /usr/local/bin/

clean:
	rm -f $(TARGET)

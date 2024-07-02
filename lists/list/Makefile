TARGET = program
CC = gcc
CFLAGS = -Wall -g -O0
#CFLAGS = -O3
OBJECTS = main.o list.o


all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)

$(OBJECTS): %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(TARGET) *.o

.PHONY: all clean

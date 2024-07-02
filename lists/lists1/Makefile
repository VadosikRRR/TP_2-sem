TARGET = program
CC = gcc
CFLAGS = -Wall -g -O0
#CFLAGS = -O3
OBJECTS = main.o
STATLIC_LIB = libset.a
DYNAMIC_LIB = set
PATH_LIB = /home/vadosik/programming/lists/lists1/lib

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET) $(PATH_LIB)/$(STATLIC_LIB)
#	$(CC) -L$(PATH_LIB) -Wl,-rpath=$(PATH_LIB) $(CFLAGS) -o $(TARGET) main.c -l$(DYNAMIC_LIB)

$(OBJECTS): %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(TARGET) *.o

.PHONY: all clean

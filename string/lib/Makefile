LIB_STATIC_NAME = libstring.a
LIB_DYNAMIC_NAME = libstring.so
CC = gcc
CFLAGS = -O3
OBJECTS = string.o

lib: $(LIB_STATIC_NAME)

solib: $(LIB_DYNAMIC_NAME)

$(LIB_STATIC_NAME): $(OBJECTS)
	ar -cvq $(LIB_STATIC_NAME) $(OBJECTS)

$(LIB_DYNAMIC_NAME): $(OBJECTS)
	$(CC) -shared -o $(LIB_DYNAMIC_NAME) $(OBJECTS)

$(OBJECTS): %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(LIB_STATIC_NAME) $(LIB_DYNAMIC_NAME) *.o

.PHONY: clean lib solib

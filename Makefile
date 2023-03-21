FLAGS= -Wall
CC= gcc
OBJECTS=objects
BUILD=build
SRC=src
INCLUDE=include

STATIC=$(BUILD)/libshm-utils.a
SHARED=$(BUILD)/libshm-utils.so

OBJECTS_FILES=$(OBJECTS)/utils.o

all: $(STATIC) $(SHARED)

$(STATIC): $(OBJECTS_FILES)
	ar rcs $@ $(OBJECTS_FILES)

$(SHARED): $(OBJECTS_FILES)
	$(CC) -shared $(FLAGS) $(OBJECTS_FILES) -o $@

$(OBJECTS)/%.o: $(SRC)/%.c $(INCLUDE)/*.h
	$(CC) $(FLAGS) -c -fPIC -o $@ $<

install: $(STATIC) $(SHARED)
	sudo cp $(SHARED) /usr/lib
	sudo mkdir -p /usr/include/shm-utils
	sudo cp $(INCLUDE)/*.h /usr/include/shm-utils

uninstall:
	sudo rm -rf /usr/include/shm-utils
	sudo rm -f /usr/lib/libshm-utils.so

test: test.c
	$(CC) -o test test.c -lshm-utils

clean: uninstall
	rm -f $(OBJECTS)/*
	rm -f $(BUILD)/*
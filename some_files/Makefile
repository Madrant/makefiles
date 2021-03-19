C_FILES = main.c logic.c
TARGET = target

CC = g++
C_WARN += -Wall -Wextra -Wconversion -Wsign-conversion -Weffc++ -Wno-unused-function

all: build

build:
	@echo "Build started"
	$(CC) -O2 $(C_WARN) $(C_FILES) -o $(TARGET)

clean:
	@echo "Cleaning generated files"
	rm -f $(TARGET)
	rm -f *.o

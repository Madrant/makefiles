# Project directories
INC_DIR := .
SRC_DIR := .
OBJ_DIR := .
OUT_DIR := .

# Files to compile
C_FILES = main.c logic.c

# Output file
TARGET = target

# Compiler setup
CC = g++

# Build parameters
C_DEF += -DDEBUG
C_WARN += -Wall -Wextra -Wconversion -Wsign-conversion -Weffc++ -Wno-unused-function
C_PARAMS += -O2

.PHONY: all
all: build

.PHONY: build
build:
	@echo "Build started"
	$(CC) $(C_PARAMS) $(C_WARN) $(C_DEF) $(C_FILES) -o $(OUT_DIR)/$(TARGET)

.PHONY: clean
clean:
	@echo "Cleaning generated files"
	rm -f $(OUT_DIR)/$(TARGET)
	rm -f $(OBJ_DIR)/*.o

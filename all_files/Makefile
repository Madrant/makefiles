# Project directories
OBJ_DIR := obj
OUT_DIR := out

# Files to compile
C_FILES += $(wildcard sum/*.c)
C_FILES += $(wildcard dif/*.c)
C_FILES += $(wildcard *.c)

# Associate .c files with .o files by name
vpath %.c dif
vpath %.c sum
vpath %.c .

# Place all object files to $(OBJ_DIR) during build
O_FILES := $(addprefix $(OBJ_DIR)/, $(patsubst %.c, %.o, $(notdir $(C_FILES))))

# Output file
TARGET = target

# Compiler setup
CC = g++

# Set include path
INCLUDE_PATH += -Isum
INCLUDE_PATH += -Idif

# C Build parameters
C_DEF += -DDEBUG
C_WARN += -Wall -Wextra -Wconversion -Wsign-conversion -Weffc++ -Wno-unused-function
C_PARAMS += -Ofast -fpic

# Linker parameters
L_PARAMS += -flto
L_PARAMS += -Wl,--gc-sections
LIBS +=

.PHONY: all
all: static dynamic list

.PHONY: prepare
prepare:
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OUT_DIR)

.PHONY: list
list:
	ls -lh $(OUT_DIR)

obj/%.o: %.c
	@echo "# $< : $@"
	$(CC) $(C_PARAMS) $(C_WARN) $(C_DEF) $(M_STD_DEF) $(M_DEF) $(INCLUDE_PATH) -c -o $@ $<

.PHONY: app
app: prepare $(O_FILES)
	$(CC) -o $(OUT_DIR)/$(TARGET) $(O_FILES)

.PHONY: static
static: prepare $(O_FILES)
# Link object files
	@echo "# Linking lib$(TARGET).a"
	ar rcs $(OUT_DIR)/lib$(TARGET).a $(O_FILES)

# Show sections size
	@echo "# Information for $(TARGET).a"
	size $(OUT_DIR)/lib$(TARGET).a

.PHONY: dynamic
dynamic: prepare $(O_FILES)
# Link object files
	@echo "# Linking lib$(TARGET).so"
	$(CC) -shared -o $(OUT_DIR)/lib$(TARGET).so $(O_FILES)

.PHONY: clean
clean:
	@echo "Cleaning generated files"
	rm -f $(OBJ_DIR)/*.o
	rm -f $(OUT_DIR)/lib$(TARGET).a
	rm -f $(OUT_DIR)/lib$(TARGET).so
	rm -f $(OUT_DIR)/*.sym
	rm -f $(OUT_DIR)/*.S

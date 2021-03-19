INC_DIR := .
SRC_DIR := .
OBJ_DIR := .
OUT_DIR := .

C_FILES = logic.c
O_FILES := $(patsubst %.c, $(OBJ_DIR)/%.o, $(C_FILES))

TARGET = logic

# Compiler configuration
CC = g++

# Compiler warnings
C_DEF += -DDEBUG
C_WARN += -Wall -Wextra -Wconversion -Wsign-conversion -Weffc++ -Wno-unused-function
C_PARAMS += -fpic

# Linker parameters
L_PARAMS += -flto
L_PARAMS += -Wl,--gc-sections

.PHONY: all
all: static dynamic

$(OBJ_DIR)/%.o: $(C_FILES)
	@echo "# $<:"
	$(CC) $(C_PARAMS) $(C_DEF) $(C_WARN) -I$(INC_DIR) -c -o $@ $<

.PHONY: static
static: $(O_FILES)
# Link object files
	@echo "# Linking $(TARGET).a"
	ar rcs $(TARGET).a $(O_FILES)

# Create .S and .sym files
	@echo "# Disassembling $(TARGET).a"
	objdump -dS $(TARGET).a > $(TARGET).S
	objdump -t  $(TARGET).a > $(TARGET).sym

# Show sections size
	@echo "# Information for $(TARGET).a"
	size $(TARGET).a

.PHONY: dynamic
dynamic: $(O_FILES)
# Link object files
	@echo "# Linking $(TARGET).so"
	$(CC) -shared -o $(TARGET).so $(O_FILES)

.PHONY: clean
clean:
	@echo "Cleaning generated files"
	rm -f $(OBJ_DIR)/*.o
	rm -f $(OUT_DIR)/$(TARGET).a
	rm -f $(OUT_DIR)/$(TARGET).so
	rm -f $(OUT_DIR)/$(TARGET).sym
	rm -f $(OUT_DIR)/$(TARGET).S

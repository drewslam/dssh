CC = gcc
CFLAGS = -Wall -Wextra -std=c17 -Iinclude
DEPFLAGS = -MMD -MP

TARGET = dssh
SRC_DIR = src
BUILD_DIR = build

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))
DEPS = $(OBJ:.o=.d)

# Default rule
all: $(TARGET)

# Links object files to create executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compiles .c files into .o files, placing them in build directory
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Ensure build directory exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Debug build
debug: CFLAGS += -g -O0
debug: clean all

# Clean up object files and the executable
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Include generated dep files
-include $(DEPS)

.PHONY: all clean debug

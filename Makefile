CC = gcc
CFLAGS = -Wall -Wextra -std=c17 -Iinclude -g

TARGET = dssh
SRC_DIR = src
BUILD_DIR = build
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))

# Default rule
all: $(BUILD_DIR) $(TARGET)

# Links object files to create executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compiles .c files into .o files, placing them in build directory
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Ensure build directory exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean up object files and the executable
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean

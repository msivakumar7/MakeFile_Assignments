# ============================================================
# Assignment 1: Student Database Build Automation
# Makefile with Multiple Executables and Shared Objects
# ============================================================

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -I./include
CFLAGS_DEBUG = $(CFLAGS) -g -DDEBUG
CFLAGS_RELEASE = $(CFLAGS) -O2 -DNDEBUG

# Directories
SRC_DIR = src
APPS_DIR = apps
BUILD_DIR = build
BIN_DIR = bin
INCLUDE_DIR = include

# Source files
COMMON_SRC = $(SRC_DIR)/common.c $(SRC_DIR)/file_ops.c
ADD_SRC = $(SRC_DIR)/add_student.c
SEARCH_SRC = $(SRC_DIR)/search_student.c
DISPLAY_SRC = $(SRC_DIR)/display_student.c

# Object files (with build directory)
COMMON_OBJ = $(BUILD_DIR)/common.o $(BUILD_DIR)/file_ops.o
ADD_OBJ = $(BUILD_DIR)/add_student.o
SEARCH_OBJ = $(BUILD_DIR)/search_student.o
DISPLAY_OBJ = $(BUILD_DIR)/display_student.o

# Main files
ADD_MAIN_OBJ = $(BUILD_DIR)/add_main.o
SEARCH_MAIN_OBJ = $(BUILD_DIR)/search_main.o
DISPLAY_MAIN_OBJ = $(BUILD_DIR)/display_main.o

# Executables
EXECUTABLES = $(BIN_DIR)/add_student $(BIN_DIR)/search_student $(BIN_DIR)/display_student

# Build mode
BUILD_MODE ?= release

# Default target
.PHONY: all clean debug release help run

all: $(EXECUTABLES)

# Debug build
debug: BUILD_MODE = debug
debug: CFLAGS = $(CFLAGS_DEBUG)
debug: clean $(EXECUTABLES)
	@echo "Debug build complete!"

# Release build
release: BUILD_MODE = release
release: CFLAGS = $(CFLAGS_RELEASE)
release: clean $(EXECUTABLES)
	@echo "Release build complete!"

# Main targets
$(BIN_DIR)/add_student: $(COMMON_OBJ) $(ADD_OBJ) $(ADD_MAIN_OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^
	@echo "Built: $@"

$(BIN_DIR)/search_student: $(COMMON_OBJ) $(SEARCH_OBJ) $(SEARCH_MAIN_OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^
	@echo "Built: $@"

$(BIN_DIR)/display_student: $(COMMON_OBJ) $(DISPLAY_OBJ) $(DISPLAY_MAIN_OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^
	@echo "Built: $@"

# Object file compilation rules
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled: $<"

$(BUILD_DIR)/%.o: $(APPS_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled: $<"

# Dependency generation
%.d: %.c
	@$(CC) -MM $(CFLAGS) $< > $@

# Include dependency files
-include $(BUILD_DIR)/*.d

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR)/*.o $(BUILD_DIR)/*.d
	rm -rf $(BIN_DIR)/*
	@echo "Cleaned build artifacts"

# Run the display executable
run: $(BIN_DIR)/display_student
	./$(BIN_DIR)/display_student

# Help
help:
	@echo "================================"
	@echo "Student Database - Build Targets"
	@echo "================================"
	@echo "make                - Build all executables (release mode)"
	@echo "make debug          - Build with debug symbols"
	@echo "make release        - Build optimized release"
	@echo "make clean          - Remove build artifacts"
	@echo "make run            - Run display_student executable"
	@echo "make help           - Show this help message"
	@echo "================================"

# ============================================================
# Assignment 2: Mini Linux Command Clone Project
# Advanced Makefile with Install/Uninstall and Packaging
# ============================================================

# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Wstrict-prototypes -I./include
CFLAGS_DEBUG = $(CFLAGS) -g -O0 -DDEBUG
CFLAGS_RELEASE = $(CFLAGS) -O2 -DNDEBUG

# Directories
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin
INCLUDE_DIR = include
INSTALL_DIR = $(BIN_DIR)/installed

# Source files (using wildcard and patsubst)
ALL_SRC = $(wildcard $(SRC_DIR)/*.c)
MAIN_SRC = $(filter %_main.c, $(ALL_SRC))
UTIL_SRC = $(filter-out %_main.c, $(ALL_SRC))

# Object files with pattern substitution
ALL_OBJ = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(ALL_SRC))
UTIL_OBJ = $(filter-out %_main.o, $(ALL_OBJ))
MAIN_OBJ = $(filter %_main.o, $(ALL_OBJ))

# Executables
PROGRAMS = myls mycat mycp
EXECS = $(addprefix $(BIN_DIR)/, $(PROGRAMS))

# Build mode
BUILD_MODE ?= release

# .PHONY targets
.PHONY: all clean debug release install uninstall package help

# Default target
all: $(EXECS)

# Debug mode
debug: BUILD_MODE = debug
debug: CFLAGS = $(CFLAGS_DEBUG)
debug: clean $(EXECS)
	@echo "✓ Debug build complete!"

# Release mode
release: BUILD_MODE = release
release: CFLAGS = $(CFLAGS_RELEASE)
release: clean $(EXECS)
	@echo "✓ Release build complete!"

# Build executables
$(BIN_DIR)/myls: $(UTIL_OBJ) $(BUILD_DIR)/myls_main.o
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^
	@echo "✓ Built: $@"

$(BIN_DIR)/mycat: $(UTIL_OBJ) $(BUILD_DIR)/mycat_main.o
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^
	@echo "✓ Built: $@"

$(BIN_DIR)/mycp: $(UTIL_OBJ) $(BUILD_DIR)/mycp_main.o
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^
	@echo "✓ Built: $@"

# Pattern rule for object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "✓ Compiled: $<"

# Dependency generation
$(BUILD_DIR)/%.d: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	@$(CC) -MM $(CFLAGS) $< | sed 's|$*.o|$(BUILD_DIR)/$*.o|' > $@

# Include dependency files
-include $(BUILD_DIR)/*.d

# Install targets
install: all
	@mkdir -p $(INSTALL_DIR)
	@for prog in $(PROGRAMS); do \
		if [ -f $(BIN_DIR)/$$prog ]; then \
			cp $(BIN_DIR)/$$prog $(INSTALL_DIR)/; \
			echo "✓ Installed: $(INSTALL_DIR)/$$prog"; \
		fi \
	done
	@echo "✓ Installation complete!"

# Uninstall targets
uninstall:
	@for prog in $(PROGRAMS); do \
		if [ -f $(INSTALL_DIR)/$$prog ]; then \
			rm $(INSTALL_DIR)/$$prog; \
			echo "✓ Removed: $(INSTALL_DIR)/$$prog"; \
		fi \
	done
	@if [ -d $(INSTALL_DIR) ]; then rmdir $(INSTALL_DIR) 2>/dev/null || true; fi
	@echo "✓ Uninstallation complete!"

# Packaging target
package: clean release
	@echo "Creating tar.gz package..."
	@tar -czf linux_tools.tar.gz \
		$(SRC_DIR)/ \
		$(INCLUDE_DIR)/ \
		Makefile \
		$(BIN_DIR)/myls $(BIN_DIR)/mycat $(BIN_DIR)/mycp
	@echo "✓ Package created: linux_tools.tar.gz"
	@ls -lh linux_tools.tar.gz

# Clean targets
clean:
	@rm -rf $(BUILD_DIR)
	@rm -rf $(BIN_DIR)/*.o $(BIN_DIR)/*.d
	@rm -f $(BIN_DIR)/myls $(BIN_DIR)/mycat $(BIN_DIR)/mycp
	@rm -rf $(INSTALL_DIR)
	@echo "✓ Cleaned build artifacts"

# Help target
help:
	@echo ""
	@echo "=========================================="
	@echo "Linux Tools Clone - Build Targets"
	@echo "=========================================="
	@echo "make              - Build all (release)"
	@echo "make debug        - Build with debug info"
	@echo "make release      - Build optimized"
	@echo "make install      - Install to bin/installed/"
	@echo "make uninstall    - Remove installed files"
	@echo "make package      - Create tar.gz package"
	@echo "make clean        - Remove build artifacts"
	@echo "make help         - Show this help"
	@echo "=========================================="
	@echo ""

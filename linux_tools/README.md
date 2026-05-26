# Assignment 2: Mini Linux Command Clone Project - Quick Reference

## Overview
This project implements three Linux command clones using advanced Makefile techniques.

## Quick Start
```bash
cd linux_tools
make              # Build all
make install      # Install to bin/installed/
make package      # Create linux_tools.tar.gz
make uninstall    # Remove installed files
make clean        # Clean build artifacts
```

## Program Descriptions

### myls - List Files
Lists all files in the current directory with their sizes
```bash
./bin/myls
./bin/myls /path/to/dir
```

### mycat - Display File Contents
Shows the complete content of a file
```bash
./bin/mycat filename.txt
```

### mycp - Copy Files
Copies a file from source to destination with progress info
```bash
./bin/mycp source.txt destination.txt
```

## Makefile Features Used
- `wildcard` - Automatic source file discovery
- `patsubst` - Pattern substitution for object files
- `filter` & `filter-out` - Selective file filtering
- `addprefix` - Adding directory prefixes
- Automatic variables ($@, $^, $<)
- `.PHONY` - Declaring non-file targets
- Dependency generation with -MM
- Install/uninstall functionality
- Packaging with tar command

## Build Modes
```bash
make debug       # With debugging symbols and no optimization
make release     # Optimized for performance (default)
```

## Directory Structure
```
build/    → Object files (.o files)
bin/      → Executable binaries
installed/→ Installed copies of binaries (after make install)
```

## Key Implementation Details

### Shared Utils
All three programs use `utils.c` which contains:
- File existence checking
- Error message printing
- File size calculation
- File information formatting

### Pattern-Based Compilation
The Makefile uses patterns to handle multiple programs efficiently:
```makefile
$(BIN_DIR)/myls: $(UTIL_OBJ) $(BUILD_DIR)/myls_main.o
```

### Automatic Dependency Tracking
Dependencies are automatically generated and included:
```makefile
-include $(BUILD_DIR)/*.d
```

This prevents unnecessary recompilation when headers haven't changed.


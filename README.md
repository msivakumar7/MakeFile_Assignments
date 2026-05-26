# Assignment 1: Student Database Build Automation

## Overview
A comprehensive student database system demonstrating multiple executables, shared object reuse, and advanced Makefile features.

## Project Structure
```
student_db/
├── Makefile              # Multi-target build automation
├── include/
│   └── student.h         # Header with data structures
├── src/
│   ├── common.c          # Common database functions
│   ├── file_ops.c        # File I/O operations
│   ├── add_student.c     # Add student functionality
│   ├── search_student.c  # Search functionality
│   └── display_student.c # Display functionality
├── apps/
│   ├── add_main.c        # Add executable entry point
│   ├── search_main.c     # Search executable entry point
│   └── display_main.c    # Display executable entry point
├── build/                # Object files directory
└── bin/                  # Final executables directory
```

## Executables
1. **add_student** - Add new student records to database
2. **search_student** - Search for student by ID
3. **display_student** - Display all students in database

## Building

### Build All (Release Mode)
```bash
cd student_db
make
```

### Debug Mode
```bash
make debug
```

### Release Mode (Optimized)
```bash
make release
```

### Clean Build
```bash
make clean
```

### Run Display
```bash
make run
```

## Usage

### Add a Student
```bash
./bin/add_student S001 "John Doe" 3.85
```

### Search for a Student
```bash
./bin/search_student S001
```

### Display All Students
```bash
./bin/display_student
```

## Key Features
- ✓ Multiple executables from single Makefile
- ✓ Shared object reuse (common.o, file_ops.o)
- ✓ Conditional compilation (debug/release modes)
- ✓ Automatic dependency generation
- ✓ Pattern substitution rules
- ✓ Separate build and bin directories
- ✓ File-based persistent storage

## Makefile Highlights
- Uses `wildcard` for flexible source discovery
- Implements `patsubst` for object file naming
- Separate debug and release compilation flags
- Automatic dependency file generation
- `.PHONY` targets for non-file targets
- Organized directory structure for scalability

---

# Assignment 2: Mini Linux Command Clone Project

## Overview
Advanced Makefile project implementing simplified Linux command clones with install/uninstall functionality and packaging capabilities.

## Project Structure
```
linux_tools/
├── Makefile              # Advanced multi-target Makefile
├── include/
│   └── utils.h          # Utility function declarations
├── src/
│   ├── utils.c          # Shared utility functions
│   ├── myls.c           # ls clone implementation
│   ├── mycat.c          # cat clone implementation
│   ├── mycp.c           # cp clone implementation
│   ├── myls_main.c      # myls entry point
│   ├── mycat_main.c     # mycat entry point
│   └── mycp_main.c      # mycp entry point
├── build/               # Object files directory
└── bin/                 # Executables directory
```

## Programs
1. **myls** - List files in a directory with sizes
2. **mycat** - Display file contents
3. **mycp** - Copy files with progress information

## Building

### Build All (Release Mode)
```bash
cd linux_tools
make
```

### Debug Build
```bash
make debug
```

### Release Build (Optimized)
```bash
make release
```

## Installation & Management

### Install to bin/installed/
```bash
make install
```

### Uninstall
```bash
make uninstall
```

### Create Package (tar.gz)
```bash
make package
```
Creates `linux_tools.tar.gz` with all source files and executables.

### Clean Build Artifacts
```bash
make clean
```

## Usage

### List Files
```bash
./bin/myls
./bin/myls /path/to/directory
```

### Display File Contents
```bash
./bin/mycat filename.txt
```

### Copy File
```bash
./bin/mycp source.txt destination.txt
```

## Key Features
- ✓ Shared utility functions (utils.o)
- ✓ Multiple independent executables
- ✓ Install/uninstall targets
- ✓ Package creation with tar.gz
- ✓ Debug and release modes
- ✓ Automatic dependency generation
- ✓ Advanced Makefile functions

## Makefile Advanced Features
- ✓ `wildcard` - Dynamic source discovery
- ✓ `patsubst` - Pattern-based file transformations
- ✓ `filter` & `filter-out` - Selective object compilation
- ✓ `addprefix` - Add directory prefix to file lists
- ✓ Automatic variables ($@, $^, $<)
- ✓ `.PHONY` targets for non-file operations
- ✓ Dependency file generation with -MM
- ✓ Install to custom directory with mkdir -p

## Bonus Features Implemented
- ✓ Both assignments complete with all required functionality
- ✓ Error handling and validation
- ✓ File size display with units (B, KB, MB)
- ✓ Directory traversal support
- ✓ Binary file copy support
- ✓ Progress messages during operations

## Building Strategy

### Object File Reuse
Both projects efficiently reuse common object files:
- **Assignment 1**: `common.o` and `file_ops.o` used by all three executables
- **Assignment 2**: `utils.o` used by all three executables

### Dependency Management
Automatic dependency generation prevents unnecessary recompilation:
```bash
gcc -MM -I./include src/file.c > build/file.d
```

### Scalability
The Makefile design allows easy addition of:
- New source files (automatically detected via `wildcard`)
- New programs (add to PROGRAMS list)
- New targets (install, uninstall, package, etc.)

---

## How to Test

### Assignment 1 Testing
```bash
# Build and run
cd ../Assignment1/student_db
make clean
make

# Add students
./bin/add_student S001 "Alice Johnson" 3.9
./bin/add_student S002 "Bob Smith" 3.7
./bin/add_student S003 "Carol White" 3.8

# Search
./bin/search_student S001

# Display all
./bin/display_student

# Or use make run
make run
```

### Assignment 2 Testing
```bash
# Build and test
cd ../Assignment2/linux_tools
make clean
make

# Create test file
echo "Hello from Linux Tools" > test.txt

# Test myls
./bin/myls

# Test mycat
./bin/mycat test.txt

# Test mycp
./bin/mycp test.txt copy.txt

# Install
make install

# Package
make package

# Uninstall
make uninstall
```


#include "../include/utils.h"

extern void display_file_contents(const char *filename);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        printf("Example: %s test.txt\n", argv[0]);
        return 1;
    }
    
    display_file_contents(argv[1]);
    return 0;
}

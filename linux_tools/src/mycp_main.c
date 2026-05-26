#include "../include/utils.h"

extern int copy_file(const char *src, const char *dst);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        printf("Example: %s original.txt copy.txt\n", argv[0]);
        return 1;
    }
    
    if (copy_file(argv[1], argv[2])) {
        return 0;
    } else {
        return 1;
    }
}

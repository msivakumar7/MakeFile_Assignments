#include "../include/utils.h"

extern void list_files(const char *path);

int main(int argc, char *argv[]) {
    const char *path = ".";
    
    if (argc > 1) {
        path = argv[1];
    }
    
    list_files(path);
    return 0;
}

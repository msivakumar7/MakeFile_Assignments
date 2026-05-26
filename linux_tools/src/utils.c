#include "../include/utils.h"

int file_exists(const char *filename) {
    if (filename == NULL) return 0;
    FILE *file = fopen(filename, "r");
    if (file) {
        fclose(file);
        return 1;
    }
    return 0;
}

void print_error(const char *operation, const char *filename) {
    if (operation == NULL || filename == NULL) {
        fprintf(stderr, "Error: Invalid parameters\n");
        return;
    }
    fprintf(stderr, "Error: Cannot %s '%s'\n", operation, filename);
}

long get_file_size(const char *filename) {
    struct stat st;
    if (stat(filename, &st) == -1) {
        return -1;
    }
    return st.st_size;
}

void print_file_info(const char *filename, long size) {
    if (size >= 1024*1024) {
        printf("%-40s %10.2f MB\n", filename, (float)size / (1024*1024));
    } else if (size >= 1024) {
        printf("%-40s %10.2f KB\n", filename, (float)size / 1024);
    } else {
        printf("%-40s %10ld B\n", filename, size);
    }
}

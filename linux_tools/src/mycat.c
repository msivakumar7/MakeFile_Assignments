#include "../include/utils.h"

void display_file_contents(const char *filename) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    int line_num = 1;
    
    if (!filename || strlen(filename) == 0) {
        fprintf(stderr, "Error: No filename provided\n");
        return;
    }
    
    if (!file_exists(filename)) {
        print_error("open", filename);
        return;
    }
    
    file = fopen(filename, "r");
    if (!file) {
        print_error("read", filename);
        return;
    }
    
    printf("\n========== CONTENT OF: %s ==========\n\n", filename);
    
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
        fwrite(buffer, 1, bytes_read, stdout);
    }
    
    printf("\n\n=========================================\n\n");
    
    if (ferror(file)) {
        print_error("read", filename);
    }
    
    fclose(file);
}

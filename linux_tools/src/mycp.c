#include "../include/utils.h"

int copy_file(const char *src, const char *dst) {
    FILE *src_file, *dst_file;
    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    long total_bytes = 0;
    
    if (!src || !dst) {
        fprintf(stderr, "Error: Invalid source or destination\n");
        return 0;
    }
    
    if (!file_exists(src)) {
        print_error("access source", src);
        return 0;
    }
    
    /* Check if destination already exists */
    if (file_exists(dst)) {
        printf("Warning: Destination '%s' already exists. Overwriting...\n", dst);
    }
    
    src_file = fopen(src, "rb");
    if (!src_file) {
        print_error("open source", src);
        return 0;
    }
    
    dst_file = fopen(dst, "wb");
    if (!dst_file) {
        fclose(src_file);
        print_error("open destination", dst);
        return 0;
    }
    
    printf("Copying '%s' to '%s'...\n", src, dst);
    
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, src_file)) > 0) {
        if (fwrite(buffer, 1, bytes_read, dst_file) != bytes_read) {
            fprintf(stderr, "Error: Write failure\n");
            fclose(src_file);
            fclose(dst_file);
            return 0;
        }
        total_bytes += bytes_read;
    }
    
    fclose(src_file);
    fclose(dst_file);
    
    printf("Successfully copied %ld bytes.\n", total_bytes);
    return 1;
}

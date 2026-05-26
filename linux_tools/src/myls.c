#include "../include/utils.h"

void list_files(const char *path) {
    DIR *dir;
    struct dirent *entry;
    struct stat st;
    char full_path[MAX_PATH];
    int file_count = 0;
    
    if (path == NULL) {
        path = ".";
    }
    
    dir = opendir(path);
    if (!dir) {
        print_error("open directory", path);
        return;
    }
    
    printf("\n%-40s %15s\n", "FILENAME", "SIZE");
    printf("=======================================================\n");
    
    while ((entry = readdir(dir)) != NULL) {
        /* Skip . and .. */
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        
        snprintf(full_path, MAX_PATH, "%s/%s", path, entry->d_name);
        
        if (stat(full_path, &st) == 0) {
            if (S_ISDIR(st.st_mode)) {
                printf("%-40s %15s [DIR]\n", entry->d_name, "");
            } else {
                print_file_info(entry->d_name, st.st_size);
            }
            file_count++;
        }
    }
    
    printf("=======================================================\n");
    printf("Total items: %d\n\n", file_count);
    
    closedir(dir);
}

#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

/* Buffer size for file operations */
#define BUFFER_SIZE 4096
#define MAX_PATH 1024
#define MAX_FILES 1000

/* Function declarations */
void list_files(const char *path);
void display_file_contents(const char *filename);
int copy_file(const char *src, const char *dst);
int file_exists(const char *filename);
void print_error(const char *operation, const char *filename);

#endif

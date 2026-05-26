#include "../include/student.h"

void save_students_to_file(Student *students, int count) {
    FILE *file = fopen(DB_FILE, "wb");
    if (!file) {
        perror("Error opening file for writing");
        return;
    }
    
    fwrite(&count, sizeof(int), 1, file);
    if (count > 0) {
        fwrite(students, sizeof(Student), count, file);
    }
    
    fclose(file);
    printf("Database saved successfully (%d records)\n", count);
}

Student* load_students_from_file(int *count) {
    static Student students[MAX_STUDENTS];
    *count = 0;
    
    FILE *file = fopen(DB_FILE, "rb");
    if (!file) {
        return students;
    }
    
    fread(count, sizeof(int), 1, file);
    if (*count > 0 && *count <= MAX_STUDENTS) {
        fread(students, sizeof(Student), *count, file);
    }
    
    fclose(file);
    return students;
}

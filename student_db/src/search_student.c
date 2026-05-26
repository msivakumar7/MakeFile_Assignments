#include "../include/student.h"

void search_student_record(const char *id) {
    if (id == NULL || strlen(id) == 0) {
        printf("Invalid ID provided!\n");
        return;
    }
    
    int count = 0;
    Student *students = load_students_from_file(&count);
    
    if (count == 0) {
        printf("No students found in database.\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].id, id) == 0) {
            printf("Student Found:\n");
            print_student(&students[i]);
            return;
        }
    }
    
    printf("Student with ID '%s' not found.\n", id);
}

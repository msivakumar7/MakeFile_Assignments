#include "../include/student.h"

void display_all_students(void) {
    int count = 0;
    Student *students = load_students_from_file(&count);
    
    if (count == 0) {
        printf("No students in database.\n");
        return;
    }
    
    printf("\n========== STUDENT DATABASE ==========\n");
    printf("%-12s %-32s %s\n", "ID", "NAME", "GPA");
    printf("========================================\n");
    
    for (int i = 0; i < count; i++) {
        print_student(&students[i]);
    }
    
    printf("========================================\n");
    printf("Total Students: %d\n\n", count);
}

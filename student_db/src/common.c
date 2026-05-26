#include "../include/student.h"

/* Global student database */
static Student students[MAX_STUDENTS];
static int student_count = 0;

void init_database(void) {
    student_count = 0;
    load_students_from_file(&student_count);
}

void print_student(Student *student) {
    if (student == NULL) {
        printf("Invalid student pointer\n");
        return;
    }
    printf("ID: %-10s Name: %-30s GPA: %.2f\n", 
           student->id, student->name, student->gpa);
}

int get_student_count(void) {
    return student_count;
}

Student* get_students_array(void) {
    return students;
}

void set_student_count(int count) {
    student_count = count;
}

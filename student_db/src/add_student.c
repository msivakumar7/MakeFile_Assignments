#include "../include/student.h"

static Student students[MAX_STUDENTS];
static int student_count = 0;

void add_student_record(const char *id, const char *name, float gpa) {
    if (student_count >= MAX_STUDENTS) {
        printf("Database is full! Cannot add more students.\n");
        return;
    }
    
    /* Check for duplicate ID */
    for (int i = 0; i < student_count; i++) {
        if (strcmp(students[i].id, id) == 0) {
            printf("Student with ID %s already exists!\n", id);
            return;
        }
    }
    
    /* Add new student */
    strcpy(students[student_count].id, id);
    strcpy(students[student_count].name, name);
    students[student_count].gpa = gpa;
    
    student_count++;
    printf("Student added successfully: ID=%s, Name=%s, GPA=%.2f\n", 
           id, name, gpa);
    
    /* Save to file */
    save_students_to_file(students, student_count);
}

int get_student_count(void) {
    return student_count;
}

Student* get_students_array(void) {
    return students;
}

void load_database(void) {
    Student *loaded = load_students_from_file(&student_count);
    memcpy(students, loaded, sizeof(Student) * student_count);
}

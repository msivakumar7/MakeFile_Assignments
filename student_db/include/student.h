#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME 50
#define MAX_ID 10
#define DB_FILE "students.dat"

typedef struct {
    char id[MAX_ID];
    char name[MAX_NAME];
    float gpa;
} Student;

/* Function declarations */
void add_student_record(const char *id, const char *name, float gpa);
void search_student_record(const char *id);
void display_all_students(void);
void save_students_to_file(Student *students, int count);
Student* load_students_from_file(int *count);
void init_database(void);
void print_student(Student *student);

#endif

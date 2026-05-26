#include "../include/student.h"

extern void add_student_record(const char *id, const char *name, float gpa);
extern void load_database(void);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <student_id> <student_name> <gpa>\n", argv[0]);
        printf("Example: %s S001 \"John Doe\" 3.85\n", argv[0]);
        return 1;
    }
    
    char *id = argv[1];
    char *name = argv[2];
    float gpa = atof(argv[3]);
    
    if (gpa < 0.0 || gpa > 4.0) {
        printf("Error: GPA must be between 0.0 and 4.0\n");
        return 1;
    }
    
    add_student_record(id, name, gpa);
    return 0;
}

#include "../include/student.h"

extern void search_student_record(const char *id);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <student_id>\n", argv[0]);
        printf("Example: %s S001\n", argv[0]);
        return 1;
    }
    
    char *id = argv[1];
    search_student_record(id);
    
    return 0;
}

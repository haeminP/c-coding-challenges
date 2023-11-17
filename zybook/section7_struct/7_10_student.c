#include <stdio.h>
#include "Student.h"
#include "Student.c"

int main()
{
    Student student = InitStudent();
    char name[20];

    GetName(name, student);
    printf("%s/%.1lf\n", name, GetGPA(student));

    student = SetName("Felix", student);
    student = SetGPA(3.7, student);
    GetName(name, student);
    printf("%s/%.1lf\n", name, GetGPA(student));


    return 0;
}
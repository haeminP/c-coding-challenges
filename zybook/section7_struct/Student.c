#include <stdio.h>
#include <string.h>
#include "Student.h"


Student InitStudent(){
    Student newStudent;
    strcpy(newStudent.studentName, "Louie");
    newStudent.gpa = 1.0;
    return newStudent;
}

Student SetName(char* name, Student s){
    strcpy(s.studentName, name);
    return s;
}

Student SetGPA(double gpa, Student s){
    s.gpa = gpa;
    return s;
}

void GetName(char* studentName, Student s){
    strcpy(studentName, s.studentName);
}

double GetGPA(Student s){
    return s.gpa;
}

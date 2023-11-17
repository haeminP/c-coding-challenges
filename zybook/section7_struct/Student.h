#ifndef STUDENT_H
#define STUDENT_H


typedef struct Student_struct
{
    char studentName[20];
    double gpa;

} Student;

Student InitStudent();
Student SetName(char* name, Student s);
Student SetGPA(double gpa, Student s);
void GetName(char* studentName, Student s);
double GetGPA(Student s);

#endif


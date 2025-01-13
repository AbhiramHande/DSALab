#ifndef STUDENT_H
#define STUDENT_H

#define LENGTH_OF_ID 13

typedef struct student student;

struct student{
    char ID[LENGTH_OF_ID+1];
    float CGPA;
}; 

#endif

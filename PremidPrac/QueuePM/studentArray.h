#ifndef STUDENTARRAY_H
#define STUDENTARRAY_H

#define MAX 32

typedef struct {
    char LName[16];
    char FName[24];
    char Mi;
} Name;

typedef struct {
    Name name;
    unsigned int id;
    char course[8];
    int grade;
} Student;

typedef struct {
    Student students[MAX];
    int front;
    int rear;
} Queue;

#endif
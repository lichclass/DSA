#ifndef STUDENTLL_H
#define STUDENTLL_H

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

typedef struct node {
    Student student;
    struct node *next;
} *Stack;


#endif
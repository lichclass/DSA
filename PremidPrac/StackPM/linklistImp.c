#include <stdio.h>
#include <stdlib.h>
#include "studentLL.h"

typedef enum {false, true} boolean;

void push(Student stud, Stack *s);
Student pop(Stack *s);
Student top(Stack s);
boolean isEmpty(Stack s);
void initStack(Stack *s);
void displayStack(Stack s);

void push(Student stud, Stack *s){
    Stack temp = (Stack)malloc(sizeof(struct node));
    temp->student = stud;
    temp->next = *s;
    *s = temp;
}

Student pop(Stack *s){
    Student dummy = { {"XXXX", "XXXX", 'X'}, 0, "XXXX", 0 };
    if(!isEmpty(*s)){
        Stack temp = *s;
        dummy = temp->student;
        *s = temp->next;
        free(temp);
    }
    return dummy;
}

Student top(Stack s){
    Student dummy = { {"XXXX", "XXXX", 'X'}, 0, "XXXX", 0 };
    if(!isEmpty(s)){
        dummy = s->student;
    }
    return dummy;
}

boolean isEmpty(Stack s){
    return s == NULL;
}

void initStack(Stack *s){
    *s = NULL;
}

void makenull(Stack *s){
    while(!isEmpty(*s)){
        pop(s);
    }
}

void displayStack(Stack s){

    while(!isEmpty(s)){
        Student stud = top(s);
        printf("Name: %s %s, ID: %u, Course: %s, Grade: %d\n",
               stud.name.FName, stud.name.LName, stud.id, stud.course, stud.grade);
        s = s->next;
    }
}

int main(){
    Stack s;
    initStack(&s);

    Student stud1 = {{"Smith", "John", 'A'}, 1001, "CS", 85};
    Student stud2 = {{"Doe", "Jane", 'B'}, 1002, "IT", 90};
    Student stud3 = {{"Brown", "Charlie", 'C'}, 1003, "EE", 88};
    Student stud4 = {{"Taylor", "Chris", 'D'}, 1004, "ME", 92};
    Student stud5 = {{"White", "Ashley", 'E'}, 1005, "CE", 87};

    push(stud1, &s);
    push(stud2, &s);
    push(stud3, &s);
    push(stud4, &s);
    push(stud5, &s);

    // makenull(&s);

    displayStack(s);
    printf("\nIs Empty? %d\n", isEmpty(s));
    displayStack(s);

    return 0;
}

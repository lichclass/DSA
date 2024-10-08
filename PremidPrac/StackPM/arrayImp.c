#include <stdio.h>
#include "studentArray.h"

typedef enum {false, true} boolean;

void push(Student stud, Stack *s);
Student pop(Stack *s);
Student top(Stack s);
boolean isEmpty(Stack s);
boolean isFull(Stack s);
void initStack(Stack *s);
void displayStack(Stack s);

void push(Student stud, Stack *s){
    if(!isFull(*s)){
        s->students[++s->top] = stud;
    }
}

Student pop(Stack *s){
    Student dummy = { {"XXXX", "XXXX", 'X'}, 0, "XXXX", 0 };
    if(!isEmpty(*s)){
        dummy = s->students[s->top--];
    }
    return dummy;
}

Student top(Stack s){
    Student dummy = { {"XXXX", "XXXX", 'X'}, 0, "XXXX", 0 };
    if(!isEmpty(s)){
        dummy = s.students[s.top];
    }
    return dummy;
}

boolean isEmpty(Stack s){
    return s.top == -1;
}

boolean isFull(Stack s){
    return s.top == MAX - 1;
}

void initStack(Stack *s){
    s->top = -1;
}

void makenull(Stack *s){
    s->top = -1;
}

void displayStack(Stack s){
    char name[48];
    printf("\nStack: \n");
    while(s.top != -1){ 
        Student stud = pop(&s); 
        sprintf(name, "%s, %s %c.", stud.name.LName, stud.name.FName, stud.name.Mi);
        printf("| %s |\n", name);
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

    makenull(&s);

    displayStack(s);
    printf("\nIs Empty? %d", isEmpty(s));
    printf("\nIs Full? %d", isFull(s));

    return 0;
}
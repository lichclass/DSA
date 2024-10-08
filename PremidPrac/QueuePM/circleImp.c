#include <stdio.h>
#include "studentArray.h"

typedef enum {false, true} boolean;

void enqueue(Student stud, Queue *Q);
Student dequeue(Queue *Q);
Student front(Queue Q);
boolean isEmpty(Queue Q);
boolean isFull(Queue Q);
void initQueue(Queue *Q);
void makenull(Queue *Q);
void displayQueue(Queue Q);

void enqueue(Student stud, Queue *Q){
    if(!isFull(*Q)){
        Q->rear = (Q->rear + 1) % MAX;
        Q->students[Q->rear] = stud;
    }
}

Student dequeue(Queue *Q){
    Student dummy = { {"XXXX", "XXXX", 'X'}, 0, "XXXX", 0 };
    if(!isEmpty(*Q)){
        dummy = Q->students[Q->front];
        Q->front = (Q->front + 1) % MAX;
    }
    return dummy;
}

Student front(Queue Q){
    Student dummy = { {"XXXX", "XXXX", 'X'}, 0, "XXXX", 0 };
    if(!isEmpty(Q)){
        dummy = Q.students[Q.front];
    }
    return dummy;
}

boolean isEmpty(Queue Q){
    return (Q.rear + 1) % MAX == Q.front;
}

boolean isFull(Queue Q){
    return (Q.rear + 2) % MAX == Q.front;
}

void initQueue(Queue *Q){
    Q->front = 0;
    Q->rear = MAX-1;
}

void makenull(Queue *Q){
    initQueue(Q);
}

void displayQueue(Queue Q){
    char name[48];
    printf("Queue: ");
    while(!isEmpty(Q)){
        Student stud = dequeue(&Q);
        sprintf(name, "%s, %s %c.", stud.name.LName, stud.name.FName, stud.name.Mi);
        printf("\n%s", name);
    }
}

int main(){

    Queue Q;
    initQueue(&Q);

    Student stud1 = {{"Smith", "John", 'A'}, 1001, "CS", 85};
    Student stud2 = {{"Doe", "Jane", 'B'}, 1002, "IT", 90};
    Student stud3 = {{"Brown", "Charlie", 'C'}, 1003, "EE", 88};
    Student stud4 = {{"Taylor", "Chris", 'D'}, 1004, "ME", 92};
    Student stud5 = {{"White", "Ashley", 'E'}, 1005, "CE", 87};

    enqueue(stud1, &Q);
    enqueue(stud2, &Q);
    enqueue(stud3, &Q);
    enqueue(stud4, &Q);
    enqueue(stud5, &Q);

    displayQueue(Q);

    return 0;
}
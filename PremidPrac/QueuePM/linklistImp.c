#include <stdio.h>
#include <stdlib.h>
#include "studentLL.h"

typedef enum {false, true} boolean;

void enqueue(Student stud, Queue *Q);
Student dequeue(Queue *Q);
Student front(Queue Q);
boolean isEmpty(Queue Q);
void initQueue(Queue *Q);
void makenull(Queue *Q);
void displayQueue(Queue Q);

void enqueue(Student stud, Queue *Q){
    Nodetype temp = (Nodetype)malloc(sizeof(struct node));
    temp->student = stud;
    temp->next = NULL;
    if(Q->front != NULL){
        Q->rear = Q->rear->next = temp;  
    } else {
        Q->front = Q->rear = temp;
    }
}

Student dequeue(Queue *Q){
    Student dummy = { {"XXXX", "XXXX", 'X'}, 0, "XXXX", 0 };
    if(Q->front != NULL){
        Nodetype temp = Q->front;
        dummy = Q->front->student;
        Q->front = temp->next;
        free(temp);
    }
    return dummy;
}

Student front(Queue Q){
    Student dummy = { {"XXXX", "XXXX", 'X'}, 0, "XXXX", 0 };
    if(!isEmpty(Q)){
        dummy = Q.front->student;
    }
    return dummy;
}

boolean isEmpty(Queue Q){
    return Q.front == NULL;
}

void initQueue(Queue *Q){
    Q->front = Q->rear = NULL;
}

void makenull(Queue *Q){ 
    while(Q->front!=NULL){ 
        dequeue(Q); 
    } 
}

void displayQueue(Queue Q){
    char name[48];
    printf("Queue: ");
    while(!isEmpty(Q)){
        Student stud = front(Q);
        sprintf(name, "%s, %s %c.", stud.name.LName, stud.name.FName, stud.name.Mi);
        printf("\n%s", name);
        Q.front = Q.front->next;
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
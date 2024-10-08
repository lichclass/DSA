#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node{
    char Elem;
    struct node *next;
} *Nodetype;

typedef struct {
    Nodetype front;
    Nodetype rear;
} Queue;

void enqueue(char elem, Queue *Q);
void dequeue(Queue *Q);
char front(Queue Q);
int isEmpty(Queue Q);
void initQueue(Queue *Q);
void makenull(Queue *Q);
void displayQueue(Queue Q);


void enqueue(char elem, Queue *Q){
    Nodetype temp = (Nodetype) malloc(sizeof(struct node));
    temp->Elem = elem;
    temp->next = NULL;
    if(Q->front!=NULL){
        Q->rear = Q->rear->next = temp;  
    } else {
        Q->front = Q->rear = temp;
    }
}

void dequeue(Queue *Q){
    if(Q->front!=NULL){
        Nodetype temp = Q->front;
        Q->front = temp->next;
        free(temp);
    }
}

char front(Queue Q){ return (Q.front!=NULL) ? Q.front->Elem : '0'; }

int isEmpty(Queue Q){ return Q.front==NULL; }

void initQueue(Queue *Q){ Q->front = Q->rear = NULL; }

void makenull(Queue *Q){ while(Q->front!=NULL){ dequeue(Q); } }

void displayQueue(Queue Q){
    printf("Queue: ");
    Nodetype temp = Q.front;
    while(temp!=NULL){
        printf("| %c ", temp->Elem);
        temp = temp->next;
    }
    printf("|\n");
}

int main(){
    Queue Q;

    initQueue(&Q);
    enqueue('a', &Q);
    enqueue('b', &Q);
    enqueue('c', &Q);

    displayQueue(Q);

    return 0;
}


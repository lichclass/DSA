#include <stdio.h>
#include <ctype.h>

#define MAX 8

typedef struct {
    char Elem[MAX];
    int front;
    int rear;
} Queue;   

void enqueue(char elem, Queue *Q);
void dequeue(Queue *Q);
char front(Queue Q);
void initQueue(Queue *Q);
void displayQueue(Queue Q);


void enqueue(char elem, Queue *Q){
    if((Q->rear + 1) % MAX != Q->front){
        if(Q->front == -1){ Q->front = 0; }
        Q->rear = (Q->rear + 1) % MAX;
        Q->Elem[Q->rear] = elem;
    } else {
        printf("Queue is full!\n");
    }
}

void dequeue(Queue *Q){
    if(Q->front != -1){
        Q->front = (Q->front + 1) % MAX;
        if(Q->front > Q->rear) { initQueue(Q); }
    } else {
        printf("Queue is already empty!\n");
    }
}

char front(Queue Q) { return (Q.rear!=-1) ? Q.Elem[Q.front] : '0'; }

int isEmpty(Queue Q){ return Q.front==-1; }

int isFull(Queue Q){ return (Q.rear + 1) % MAX != Q.front; }

void initQueue(Queue *Q){ Q->front = Q->rear = -1; }

void makenull(Queue *Q);

void displayQueue(Queue Q){
    printf("Queue: ");
    for(int i=0; i<MAX; i++){
        printf("| %c ", (isalnum(Q.Elem[i])) ? Q.Elem[i] : '0' );
    }
    printf("|\n");
}

int main(){
    Queue Q;

    initQueue(&Q);
    enqueue('a', &Q);
    enqueue('b', &Q);
    enqueue('c', &Q);
    enqueue('d', &Q);
    enqueue('e', &Q);

    dequeue(&Q);
    dequeue(&Q);
    dequeue(&Q);
    dequeue(&Q);
    dequeue(&Q);

    enqueue('1', &Q);
    enqueue('2', &Q);
    enqueue('3', &Q);
    enqueue('4', &Q);
    enqueue('5', &Q);

    dequeue(&Q);
    dequeue(&Q);
    dequeue(&Q);

    printf("--Front: index %d \n--Rear : index %d\n", Q.front, Q.rear);
    
    displayQueue(Q);

    return 0;
}
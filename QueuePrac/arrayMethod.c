#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 5

typedef struct {
    char Elem[MAX];
    int front;
    int rear;
} Queue;

void enqueue(char elem, Queue *Q);
void dequeue(Queue *Q);
char front(Queue Q);
int isEmpty(Queue Q);
int isFull(Queue Q);
void initQueue(Queue *Q);
void makenull(Queue *Q);
void displayQueue(Queue Q);

void enqueue(char elem, Queue *Q){
    if(Q->rear - Q->front != MAX-1){

        if(Q->front == -1){ Q->front = 0; }

        if(Q->rear == MAX-1 && Q->front > 0){
            int x;
            for(x=0; x<MAX-Q->front; x++){
                Q->Elem[x] = Q->Elem[Q->front+x];
            }
            Q->front = 0;
            Q->rear = x-1;
        }
        
        Q->rear++;
        Q->Elem[Q->rear] = elem;
    } 
}

void dequeue(Queue *Q){
    if(Q->rear!=-1){
        Q->front++;
        if(Q->front > Q->rear) {
            initQueue(Q);
        }
    } 
}

char front(Queue Q) { 
    return (Q.rear!=-1) ? Q.Elem[Q.front] : '0'; 
}

int isEmpty(Queue Q){ 
    return Q.rear==-1; 
}

int isFull(Queue Q){ 
    return Q.rear - Q.front == MAX-1; 
}

void initQueue(Queue *Q){ 
    Q->front = Q->rear = -1; 
}

void makenull(Queue *Q){ 
    initQueue(Q); 
}

void displayQueue(Queue Q){
    printf("Queue: ");
    while(!isEmpty(Q)){
        printf("| %c ", front(Q));
        dequeue(&Q);
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

    printf("--Front: index %d \n--Rear : index %d \n--Front: %c\n", Q.front, Q.rear, front(Q));
    
    displayQueue(Q);

    return 0;
}
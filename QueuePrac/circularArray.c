#include <stdio.h>
#include <ctype.h>

#define MAX 6

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
int isEmpty(Queue Q);
int isFull(Queue Q);

void enqueue(char elem, Queue *Q){
    if(!isFull(*Q)){
        Q->rear = (Q->rear + 1) % MAX;
        Q->Elem[Q->rear] = elem;
    }
}

void dequeue(Queue *Q){
    if(!isEmpty(*Q)){
        Q->front = (Q->front + 1) % MAX;
    }
}

char front(Queue Q) { 
    return (!isEmpty(Q)) ? Q.Elem[Q.front] : '0'; 
}

int isEmpty(Queue Q){ 
    return (Q.rear + 1) % MAX == Q.front; 
}

int isFull(Queue Q){ 
    return (Q.rear + 2) % MAX == Q.front; 
}

void initQueue(Queue *Q){ 
    Q->front = 0;
    Q->rear = -1; 
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

    enqueue('A', &Q);
    enqueue('B', &Q);
    enqueue('C', &Q);
    enqueue('D', &Q);
    enqueue('E', &Q);

    printf("--Front: index %d \n--Rear : index %d\n", Q.front, Q.rear);
    printf("\nisEmpty: %d", isEmpty(Q));
    printf("\nisFull: %d\n", isFull(Q));
    
    displayQueue(Q);

    return 0;
}
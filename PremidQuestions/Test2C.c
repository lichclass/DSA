#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char FName[24], LName[16], MI;
} nametype;

typedef struct {
    unsigned int ID;
    nametype SName;
    char course[8];
    int yr;
} studRec;

typedef struct node {
    studRec stud;
    struct node *link;
} *qptr;

typedef struct {
    qptr front;
    qptr rear;
    int count;
} studQueue;

typedef enum {TRUE, FALSE} Boolean;

Boolean isAscendingID(studQueue *Q){

    Boolean isAscending = FALSE;

    if(Q->count > 1) {

        studQueue tempQueue = {NULL, NULL, 0};
        qptr temp; 

        while( (Q->front->link != NULL) && (Q->front->stud.ID < Q->front->link->stud.ID) ){

            // Dequeueing
            temp = Q->front;
            Q->front = temp->link;
            
            // Enqueue in temporary stack
            if(tempQueue.rear == NULL){
                tempQueue.front = tempQueue.rear = temp;
            } else {
                tempQueue.rear->link = temp;
                tempQueue.rear = temp;
            }
            temp->link = NULL;
            tempQueue.count++;
            Q->count--;

        }
        
        // Change the boolean if they are ascending or not
        isAscending = (Q->count > 1) ? FALSE : TRUE;

        // Enqueuing back all the elements
        while(tempQueue.count > 0) {
            temp = tempQueue.front;
            tempQueue.front = temp->link;
            temp->link = NULL;
            if(Q->rear == NULL) {
                Q->front = Q->rear = temp;
            } else {
                Q->rear->link = temp;
                Q->rear = temp;
            }
            tempQueue.count--;
            Q->count++;
        }

    }

    return isAscending;
}

/**
 * @brief Priority Queue
 * 
 */


#include <stdio.h>

#define MAX 10

typedef struct {
    int data[MAX];
    int lastNdx;
} PriorityQueue;


PriorityQueue initPriorityQueue();
void insert(int value, PriorityQueue *pq);
int deleteMin(PriorityQueue *pq);
void display(PriorityQueue pq);
PriorityQueue heapSort(PriorityQueue pq);


int main() {
    PriorityQueue pq = initPriorityQueue();
    insert(1, &pq);
    insert(2, &pq);
    insert(4, &pq);
    insert(6, &pq);
    insert(7, &pq);
    insert(9, &pq);
    display(pq);
    display(heapSort(pq));
    return 0;
}


PriorityQueue initPriorityQueue() {
    PriorityQueue pq;
    pq.lastNdx = -1;
    return pq;
}

void insert(int value, PriorityQueue *pq) {
    if(pq->lastNdx != MAX - 1) {
        
        pq->data[++pq->lastNdx] = value;
        int i;
        for(i = pq->lastNdx; i > 0 && pq->data[i] < pq->data[(i - 1) / 2]; i = (i - 1) / 2) {
            int temp = pq->data[i];
            pq->data[i] = pq->data[(i - 1) / 2];
            pq->data[(i - 1) / 2] = temp;
        }

    } else {
        printf("Priority Queue is full\n");
    }
}

int deleteMin(PriorityQueue *pq) {
    int deleted = -1;
    if (pq->lastNdx != -1) {
        // Store the minimum element to return
        deleted = pq->data[0];
        
        // Replace the root with the last element
        pq->data[0] = pq->data[pq->lastNdx--];
        
        // Heapify down from the root
        int i, left, right, smallest;
        for(i = 0, left = (2 * i) + 1, right = (2 * i) + 2; left <= pq->lastNdx; i++, left = (2 * i) + 1, right = (2 * i) + 2) {

            // Find the smallest child
            smallest = (right <= pq->lastNdx && pq->data[right] < pq->data[left]) ? right : left;
            
            if(pq->data[i] > pq->data[smallest]) {
                // Swap the parent
                int temp = pq->data[i];
                pq->data[i] = pq->data[smallest];
                pq->data[smallest] = temp;

            } else {
                break;
            }

        }
    } else {
        printf("Priority Queue is empty\n");
    }
    return deleted;
}

PriorityQueue heapSort(PriorityQueue pq) {
    PriorityQueue sortedPQ = initPriorityQueue();
    if(pq.lastNdx != -1){
        int oldLastNdx = pq.lastNdx;
        int i;
        for(i = 0; i <= oldLastNdx; i++) {
            sortedPQ.data[++sortedPQ.lastNdx] = deleteMin(&pq);
        }
    }
    return sortedPQ;
}


void display(PriorityQueue pq) {
    int i;
    for(i = 0; i <= pq.lastNdx; i++) {
        printf("%d ", pq.data[i]);
    }
    printf("\n");
}


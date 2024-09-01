#include <stdio.h>
#define MAX 50

typedef struct {
    int Elements[MAX];
    int count;
} ListV1, *ListV2;

typedef struct {
    int *elemPtr;
    int count;
    int ArrSize;
} ListV3, *ListV4;

void initializeV2(ListV2 L){
    L = (ListV2) malloc(sizeof(ListV1));
}

void initializeV3(ListV3 *L){
    L->elemPtr = (int*) malloc(sizeof(int) * MAX);
    L->count = 0;
    L->ArrSize = MAX;
}

void initializeV4(ListV4 L){
    L->elemPtr = (int*) malloc(sizeof(int) * MAX);
    L->count = 0;
    L->ArrSize = MAX;
}
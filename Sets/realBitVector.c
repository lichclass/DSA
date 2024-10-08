#include <stdio.h>
#include <stdbool.h>

typedef unsigned char SET;

void initSet(SET *s) {
    *s = 0;
}

void insertElem(SET *s, int elem) {
    if(elem < sizeof(SET) * 8){
        *s |= (1 << elem);
    }
}

void displaySet(SET s, const char *name) {
    printf("Set %s: ", name);
    int i;
    for(i = 0; i < sizeof(SET) * 8; i++){
        if((s >> i) & 1) { 
            printf("%d ", i); 
        }
    }
    printf("\n");
}

bool isMember(SET s, int elem){
    int result = false;
    if(elem < sizeof(SET) * 8){
        result = ((s >> elem) & 1) ? true : false;
    }
    return result;
}

void delete(SET *s, int elem) {
    if(elem < sizeof(SET) * 8){
        *s ^= (1 << elem);
    }
}

SET unionSet(SET A, SET B){
    return A | B;
}

SET intersection(SET A, SET B) {
    return A & B;
}

SET difference(SET A, SET B) {
    return A & ~(B);
}

int main() {
    SET A;
    SET B;
    initSet(&A);
    initSet(&B);

    insertElem(&A, 3);
    insertElem(&A, 5);
    insertElem(&A, 0);

    insertElem(&B, 1);
    insertElem(&B, 6);
    insertElem(&B, 0);

    displaySet(A, "A");
    displaySet(B, "B");
    printf("Is member of A? (%d): %d\n", 3, isMember(A, 3));

    displaySet(unionSet(A, B), "Union");
    displaySet(intersection(A, B), "Intersection");
    displaySet(difference(A, B), "Difference");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_SIZE 16

typedef struct {
    unsigned int *bit;
    int size;
} SET;

void initBit(SET *s){
    s->bit = (unsigned int *) calloc(DEFAULT_SIZE, sizeof(unsigned int));
    s->size = DEFAULT_SIZE;
}

void addElement(SET *s, int element){
    if(element > 0){
        if(element >= s->size){
            s->bit = (unsigned int *) realloc(s->bit, sizeof(unsigned int) * element);
            for(int i = s->size; i <= element; i++){
                s->bit[i] = 0;
            }
            s->size = element + 1;  
        }
        s->bit[element] = 1;
    }
}

void removeElement(SET *s, int element){
    if(element < s->size){
        s->bit[element] = 0;
    }
}

SET Union(SET s1, SET s2){
    SET s;
    initBit(&s);

    for(int i = 0; i < s1.size; i++){
        s.bit[i] = s1.bit[i] | s2.bit[i];
    }

    return s;
}

SET Intersection(SET s1, SET s2){
    SET s;
    initBit(&s);

    for(int i = 0; i < s1.size; i++){
        s.bit[i] = s1.bit[i] & s2.bit[i];
    }

    return s;
}

SET Difference(SET s1, SET s2){
    SET s;
    initBit(&s);

    for(int i = 0; i < s1.size; i++){
        s.bit[i] = s1.bit[i] & ~s2.bit[i];
    }

    return s;
}

void displayBitPattern(SET s){
    printf("Bit Pattern: ");
    for(int i = s.size - 1; i >= 0; i--){
        printf("%d ", s.bit[i]);
    }
    printf("\n");
}

int main(){
    SET A;
    SET B;

    initBit(&A);
    initBit(&B);

    addElement(&A, 0);
    addElement(&A, 1);
    addElement(&A, 2);
    addElement(&A, 6);
    addElement(&A, 10);

    addElement(&B, 0);
    addElement(&B, 1);
    addElement(&B, 3);
    addElement(&B, 5);
    addElement(&B, 7);

    printf("\nSize: %d\n", A.size);
    printf("Size: %d\n", B.size);

    displayBitPattern(A);
    displayBitPattern(B);
    displayBitPattern(Union(A, B));
    displayBitPattern(Intersection(A, B));
    displayBitPattern(Difference(A, B));

    free(A.bit);
    return 0;
}
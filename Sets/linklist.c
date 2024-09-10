#include <stdio.h>
#include <stdlib.h>

typedef struct SET {
    int data;
    struct SET *next;
} *SET;

void initSet(SET *L){
    *L = NULL;
}

void addElement(SET *L, int element){
    SET temp = (SET) malloc(sizeof(struct SET));
    if(temp != NULL){
        temp->data = element;
        temp->next = *L;
        *L = temp;
    }
}

void addElementLast(SET *L, int element){
    SET *trav;
    for(trav = L; *trav != NULL && (*trav)->data != element; trav = &(*trav)->next){}
    if(*trav == NULL){
        SET temp = (SET) malloc(sizeof(struct SET));
        if(temp != NULL){
            temp->data = element;
            temp->next = NULL;
            *trav = temp;
        }
    }
}

void removeElement(SET *L, int element){
    SET *trav;
    for(trav = L; *trav != NULL && (*trav)->data != element; trav = &(*trav)->next){}
    if(*trav != NULL){
        SET temp = *trav;
        *trav = (*trav)->next;
        free(temp);
    }
}

// Sorted Sets
SET UnionSorted(SET A, SET B) {
    SET C;
    initSet(&C);

    SET aptr = A, bptr = B, *cptr = &C;
    int data;
    while(aptr != NULL && bptr != NULL){
        if(aptr->data < bptr->data){
            data = aptr->data;
            aptr = aptr->next;
        } else if(aptr->data > bptr->data){
            data = bptr->data;
            bptr = bptr->next;
        } else {
            data = aptr->data;
            aptr = aptr->next;
            bptr = bptr->next;
        }
        addElement(cptr, data);
        cptr = &(*cptr)->next;
    }

    aptr = (aptr == NULL) ? bptr : aptr;
    while(aptr != NULL){
        data = aptr->data;
        aptr = aptr->next;
        addElement(cptr, data);
        cptr = &(*cptr)->next;
    }

    return C;
}

SET IntersectionSorted(SET A, SET B) {
    SET C;
    initSet(&C);

    SET aptr = A, bptr = B, *cptr = &C;
    while(aptr != NULL && bptr != NULL){
        if(aptr->data < bptr->data){
            aptr = aptr->next;
        } else if(aptr->data > bptr->data){
            bptr = bptr->next;
        } else {
            addElement(cptr, aptr->data);
            cptr = &(*cptr)->next;
            aptr = aptr->next;
            bptr = bptr->next;
        }
    }

    return C;
}

SET DifferenceSorted(SET A, SET B) {
    SET C;
    initSet(&C);

    SET aptr = A, bptr = B, *cptr = &C;
    while(aptr != NULL && bptr != NULL){
        if(aptr->data < bptr->data){
            addElement(cptr, aptr->data);
            cptr = &(*cptr)->next;
            aptr = aptr->next;
        } else if(aptr->data > bptr->data){
            bptr = bptr->next;
        } else {
            aptr = aptr->next;
            bptr = bptr->next;
        }
    }

    while(aptr != NULL){
        addElement(cptr, aptr->data);
        cptr = &(*cptr)->next;
        aptr = aptr->next;
    }

    return C;
}

// Unsorted Sets
SET UnionUnsorted(SET A, SET B) {
    SET C;
    initSet(&C);

    SET aptr = A, bptr = B, *cptr = &C;
    while(aptr != NULL){
        addElement(cptr,  aptr->data);
        aptr = aptr->next;
        cptr = &(*cptr)->next;
    }

    while(bptr != NULL){
        for(aptr = C; aptr != NULL && aptr->data != bptr->data; aptr = aptr->next){}
        if(aptr == NULL){
            addElement(cptr, bptr->data);
            cptr = &(*cptr)->next;
        }
        bptr = bptr->next;
    }

    return C;
}

SET IntersectionUnsorted(SET A, SET B) {
    SET C;
    initSet(&C);

    SET aptr = A, bptr, *cptr = &C;
    while(aptr != NULL){
        for(bptr = B; bptr != NULL && bptr->data != aptr->data; bptr = bptr->next){}
        if(bptr != NULL){
            addElement(cptr, aptr->data);
            cptr = &(*cptr)->next;
        }
        aptr = aptr->next;
    }

    return C;
}

SET DifferenceUnsorted(SET A, SET B) {
    SET C;
    initSet(&C);

    SET aptr = A, bptr, *cptr = &C;
    while(aptr != NULL){
        for(bptr = B; bptr != NULL && bptr->data != aptr->data; bptr = bptr->next){}
        if(bptr == NULL){
            addElement(cptr, aptr->data);
            cptr = &(*cptr)->next;
        }
        aptr = aptr->next;
    }

    return C;
}

// Display Set
void displaySet(SET L){
    printf("Set: ");
    for(SET trav = L; trav != NULL; trav = trav->next){
        printf("%d ", trav->data);
    }
    printf("\n");
}

int main(){
    SET A;
    SET B;

    initSet(&A);
    initSet(&B);

    addElementLast(&A, 0);
    addElementLast(&A, 1);
    addElementLast(&A, 2);
    addElementLast(&A, 6);

    addElementLast(&B, 0);
    addElementLast(&B, 1);
    addElementLast(&B, 3);

    displaySet(A);
    displaySet(B);

    printf("\nSorted Sets\n");
    SET C = UnionSorted(A, B);
    displaySet(C);
    SET D = IntersectionSorted(A, B);
    displaySet(D);
    SET E = DifferenceSorted(A, B);
    displaySet(E);

    printf("\nUnsorted Sets\n");
    SET F = UnionUnsorted(A, B);
    displaySet(F);
    SET G = IntersectionUnsorted(A, B);
    displaySet(G);
    SET H = DifferenceUnsorted(A, B);
    displaySet(H);

    return 0;
}
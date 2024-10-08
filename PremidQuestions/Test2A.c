#include <stdio.h>
#include <string.h>

#define SIZE 0XAA

typedef struct {
    char name[48];          // Lastname, Firstname, middle initial
    char course[8];         // BSCS, BSIT, BSIS, BSMATH
    int yearLevel;
} info;

typedef struct {
    info data;
    int link;
} Nodetype;

typedef struct VHnode {
    Nodetype heap[SIZE];
    int availList;
} *VHeap;                   /* Shared by all cursorList */

typedef struct {
    int elemPtr;            /* Points to the first element of the list */
    VHeap VH;               /* Points to the shared Virtual Heap */
} cursorList;

cursorList removeCourse(cursorList *List, char *course) {

    // Initializing the new list to be returned
    cursorList newList; 
    newList.elemPtr = -1;
    newList.VH = List->VH;

    int *trav = &List->elemPtr;
    while(*trav != -1){

        if(strcmp(List->VH->heap[*trav].data.course, course) == 0){

            // Removing from the original list
            int temp = *trav;
            *trav = List->VH->heap[temp].link;

            // Inserting removed data in the new list
            newList.VH->heap[temp].link = newList.elemPtr;
            newList.elemPtr = temp;

        } else {
            trav = &List->VH->heap[*trav].link;
        }

    }

    return newList;

}
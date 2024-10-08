#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[48];
    char course[8];
    int yearLevel;
} info;

typedef struct node {
    info data;
    struct node *link;
} *Stack;

/* This Function, removes all the students that are in BSMATH */
Stack popBSMATH(Stack *s) {

    // Initialize new Stack
    Stack newStack = NULL, tempStack = NULL, temp;

    // Finding all the BSMATH
    while(*s != NULL) {

        // Popping the stack
        temp = *s;
        *s = temp->link;

        if(strcmp(temp->data.course, "BSMATH") == 0) {
            // Pushing the node into the new stack
            temp->link = newStack;
            newStack = temp;
        } else {
            // Pushing the node into a temp stack
            temp->link = tempStack;
            tempStack = temp;
        }

    }

    // Pushing all the remaining values back into the original Stack
    while(tempStack != NULL) {
        temp = tempStack;
        tempStack = temp->link;
        temp->link = *s;
        *s = temp;
    }

    return newStack;

}
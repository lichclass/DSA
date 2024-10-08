#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node {
    char Elem;
    struct node *next;
} *Stack;


void push(char x, Stack *s){
    Stack temp = (Stack) malloc(sizeof(struct node));
    temp->Elem = x;
    temp->next = *s;
    *s = temp;
}

void pop(Stack *s){
    if(*s!=NULL){
        Stack temp = *s;
        *s = temp->next;
        free(temp);
    }
}

char peek(Stack s){ return (s!=NULL) ? s->Elem : '0'; }

int isEmpty(Stack s){ return s==NULL; }

void initialize(Stack *s){ *s = NULL; }

void makenull(Stack *s){
    while(*s!=NULL){ pop(s); }
}

// Note: No isFull(), its only for Array implementation

void displayStack(Stack *s){
    printf("Stack (display by popping): ");

    Stack temp = NULL; // Temporary stack to store popped elements

    // Pop elements from the original stack and display them
    while (*s != NULL) {
        // Print the top element
        printf("%c ", (*s)->Elem);

        // Push the element to the temporary stack
        Stack newNode = (Stack)malloc(sizeof(struct node));
        newNode->Elem = (*s)->Elem;
        newNode->next = temp;
        temp = newNode;

        // Move to the next element (pop)
        *s = (*s)->next;
    }

    printf("\n");

    // Restore the original stack from the temporary stack
    while (temp != NULL) {
        // Pop from the temporary stack and push back to the original stack
        Stack newNode = (Stack)malloc(sizeof(struct node));
        newNode->Elem = temp->Elem;
        newNode->next = *s;
        *s = newNode;

        // Move to the next element (pop from temp)
        Stack oldNode = temp;
        temp = temp->next;
        free(oldNode);
    }
}




int main(){
    Stack s;

    initialize(&s);
    push('U', &s);
    push('S', &s);
    push('C', &s);

    printf("Is it empty: %d\n", isEmpty(s));
    printf("Peek: %c\n", peek(s));

    displayStack(&s);

    displayStack(&s);

    // makenull(&s);

    // printf("Is it empty: %d\n", isEmpty(s));

    return 0;

}

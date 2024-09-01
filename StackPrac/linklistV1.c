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

void displayStack(Stack s){
    printf("Stack: ");
    for(Stack trav=s; trav!=NULL; trav=trav->next){
        printf("| %c ", (isalnum(trav->Elem)) ? trav->Elem : '0' );
    }
    printf("|\n");
}

int main(){
    Stack s;

    initialize(&s);
    push('U', &s);
    push('S', &s);
    push('C', &s);
    push('D', &s);
    push('F', &s);

    printf("Is it empty: %d\n", isEmpty(s));
    printf("Peek: %c\n", peek(s));

    displayStack(s);

    makenull(&s);

    printf("Is it empty: %d\n", isEmpty(s));

    return 0;

}

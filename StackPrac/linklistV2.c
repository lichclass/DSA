#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node {
    char Elem;
    struct node *next;
} *Stack;

void push(char x, Stack *s){
    Stack *trav;
    for(trav=s; *trav!=NULL; trav=&(*trav)->next){}
    *trav = (Stack) malloc(sizeof(struct node));
    (*trav)->Elem = x;
    (*trav)->next = NULL;
}

void pop(Stack *s){
    if(*s!=NULL){
        Stack *trav;
        for(trav=s; (*trav)->next!=NULL; trav=&(*trav)->next){}
        Stack temp = *trav;
        (*trav)->next = NULL;
        free(temp);
    }
}

char peek(Stack s){
    char elem = '0';
    if(s!=NULL){
        Stack trav;
        for(trav=s; trav->next!=NULL; trav=trav->next){}
        elem = trav->Elem;
    }
    return elem;
}

int isEmpty(Stack s){ return s==NULL; }

void initialize(Stack *s){ *s = NULL; }

void makenull(Stack *s){
    while(*s!=NULL){ 
        Stack temp = *s;
        *s = temp->next;
        free(temp); 
    }
}

// Note: No isFull(), its only for Array implementation

void displayStack(Stack s){
    printf("Stack: ");
    
    Stack temp;
    initialize(&temp);

    Stack *trav;
    for(trav = s; (*trav)->next != NULL; trav = &(*trav)->next){

    }
    Stack temp = *trav;
    (*trav)->next = NULL;
    free(temp);

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
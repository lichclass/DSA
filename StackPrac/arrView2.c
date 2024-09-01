#include <stdio.h>
#include <ctype.h>

#define MAX 5

typedef struct {
    char Elem[MAX];
    int top;
} Stack;

void push(char x, Stack *s){
    if(s->top<MAX-1){
        s->top++;
        s->Elem[s->top] = x;
    }
}

void pop(Stack *s){ if(s->top>-1){ s->top--; } }

char peek(Stack s){ return (s.top!=-1) ? s.Elem[s.top] : '0'; }

int isEmpty(Stack s){ return s.top==-1; }

int isFull(Stack s){ return s.top==MAX-1; }

void initialize(Stack *s){ s->top = -1; }

void makenull(Stack *s){ s->top = -1; }

void displayStack(Stack s){
    printf("Stack: ");
    for(int i=0; i<MAX; i++){
        printf("| %c ", (isalnum(s.Elem[i])) ? s.Elem[i] : '0' );
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
    printf("Is it full: %d\n", isFull(s));
    printf("Value of top: %d\n", s.top);
    printf("Peek: %c\n", peek(s));

    makenull(&s);

    printf("Is it empty: %d\n", isEmpty(s));

    displayStack(s);

    return 0;

}
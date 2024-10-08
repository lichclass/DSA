#include <stdio.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    char Elem[MAX];
    int top;
} Stack;

void push(char x, Stack *s){
    if(s->top < MAX - 1){
        s->top++;
        s->Elem[s->top] = x;
    }
}

char pop(Stack *s){ 
    if(s->top>-1){ 
        s->top--; 
    } 
}

bool isValidParenthesis(char str[]) {
    
}
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct node {
    int elem;
    struct node *next;
} *List;

typedef List Dictionary[SIZE];

void initDictionary(Dictionary dict){
    int i;
    for(i = 0; i < SIZE; i++){
        dict[i] = NULL;
    }
}

int getHash(int num){
    return num % 10;
}

void insert(int num, Dictionary dict){
    int hash = getHash(num);
    List temp = (List)malloc(sizeof(struct node));
    temp->elem = num;
    temp->next = dict[hash];
    dict[hash] = temp;
}

void delete(int num, Dictionary dict){
    int hash = getHash(num);
    List *trav;
    for(trav = dict + hash; *trav != NULL && (*trav)->elem != num; trav = &(*trav)->next){}
    if(*trav != NULL){
        List temp = *trav;
        *trav = temp->next;
        free(temp);
    }
}

void displayPls(int hashValue, Dictionary dict){
    List trav;
    for(trav = dict[hashValue]; trav != NULL; trav = trav->next){
        printf("%d ", trav->elem);
    }
    printf("\n");
}

int main(){
    Dictionary dict;
    initDictionary(dict);

    insert(127, dict);
    insert(37, dict);

    insert(23, dict);
    insert(13, dict);

    displayPls(7, dict);
    displayPls(3, dict);

    return 0;
}

/**
 * 
 * @author Nash Muñoz
 */
#include <stdio.h>

#define MAX 50

typedef char String[100];

typedef struct {
    char Elem[MAX];
    int count;
} List;

/* Displays the list */
void displayList(String msg, List L){
    int x;
    printf("%s: (", msg);
    for(x=0; x<L.count; x++){
        if(x==L.count-1)
            printf("%c", L.Elem[x]);
        else
            printf("%c, ", L.Elem[x]);
    }
    printf(")\n");
}

/* Inserts a character at a certain position */
void insert(char elem, int p, List *L) {
    if(L->count<MAX && (p<=L->count && p>=0)){
        if(p!=L->count){
            int x;
            for(x=L->count; x>p; x--){
                L->Elem[x] = L->Elem[x-1];
            }
        }
        L->Elem[p] = elem;
        L->count++;
    }
}

/* Deletes an element at a certain position */
void delete(int p, List *L) {
    if(p<L->count && p>=0) {
        if(p!=L->count-1){
            int x;
            for(x=p; x<L->count-1; x++){
                L->Elem[x] = L->Elem[x+1];
            }
        }
        L->count--;
    }
}

/* Finds the given element and returns the position */
int locate(char elem, List L){
    int x;
    for(x=0; x<L.count && L.Elem[x]!=elem; x++){}
    return (x<L.count) ? x : -1;
}

/* Version 1 of inserting an element in a sorted list (With function call) */
void insertSortedV1(char elem, List *L){
    if(L->count<MAX) {
        int x;
        for(x=0; x<L->count && elem>L->Elem[x]; x++){}
        insert(elem, x, L);
    }
}

/* Version 2 of inserting an element in a sorted list (Without function call) */
void insertSortedV2(char elem, List *L){
    if(L->count<MAX){
        int x;
        for(x=0; x<L->count && elem>L->Elem[x]; x++){}
        if(x!=L->count){
            int y;
            for(y=L->count; y>x; y--){
                L->Elem[y] = L->Elem[y-1];
            }
        }
        L->Elem[x] = elem;
        L->count++;
    }
}


int main() {
    List myList = {
        {},
        0
    };

    displayList("Before Insertion", myList);
    insert('E', 0, &myList);
    displayList("After Insertion", myList);
    delete(0, &myList);
    displayList("After Deletion", myList);
    insert('D', 0, &myList);
    displayList("After Insertion", myList);
    printf("Location of F: %d\n", locate('F', myList));

    insertSortedV1('A', &myList);
    displayList("After Insertion(SortedV1)", myList);

    insertSortedV2('C', &myList);
    displayList("After Insertion(SortedV2)", myList);

    return 0;
}
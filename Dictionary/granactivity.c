#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10
#define MAX_VALUES 2
#define THRESHOLD 0.65
#define LIMIT MAX_VALUES * THRESHOLD

typedef struct {
    int stdID;
    char studName[30];
    char program[10];
    int year;
} Student;

typedef struct node {
    Student stud;
    struct node *link;
} NodeType, *NodePtr;

typedef struct {
    NodePtr elems[MAX];
    int count;
} HashTable;

int getHash(Student s);
/*
    Get the hash based on the summation of the first 3 letters of the name plus the letters 
    in the program and must be able to return a value from 0-19.
*/
void initDictionary(HashTable *ht);
bool insert(HashTable *ht, Student s);
/*
    Use insert sorted if multiple data are already in the list.
*/
bool delete(HashTable *ht, Student s);
void visualizeTable(HashTable ht);


int getHash(Student s){
    int hash = 0;
    for (int i = 0; i < 3; i++){
        hash += s.studName[i];
    }
    for(int i = 0; i < strlen(s.program); i++){
        hash += s.program[i];
    }
    return hash % MAX;
}

void initDictionary(HashTable *ht){
    ht->count = 0;
    int i;
    for (i = 0; i < MAX; i++){
        ht->elems[i] = NULL;
    }
}

bool insert(HashTable *ht, Student s){

    bool isFull = true;

    if(ht->count <= LIMIT){
        isFull = false;

        int hash = getHash(s);
        NodePtr *trav;

        for(trav = &(ht->elems[hash]);  *trav != NULL && s.year < (*trav)->stud.year; trav = &(*trav)->link){
            if(s.stdID == (*trav)->stud.stdID){
                return false;
            }
        }
        
        NodePtr temp = (NodePtr) malloc(sizeof(NodeType));
        temp->stud = s;
        temp->link = *trav;
        *trav = temp;

        ht->count++;
    }
    return isFull;
}

void visualizeTable(HashTable ht){
    char name[30];
    int x;
    NodePtr trav;
    for(x = 0; x < MAX; x++){
        printf("Hash Value[%d]: ", x);
        for(trav = ht.elems[x]; trav != NULL; trav=trav->link){
            printf("[%d] %s ", getHash(trav->stud), trav->stud.studName);
        }
        printf("\n");
    }
}

int main(){
    HashTable table;
    initDictionary(&table);

    Student s = {
        21700005,
        "Elijah",
        "BSCS",
        2024
    };

    insert(&table, s);
    insert(&table, s);

    visualizeTable(table);

    return 0;
}
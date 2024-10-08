#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 10
#define EMPTY '#'
#define DELETED '!'

typedef struct {
    char Cells[MAX];
    int count;
} HashTable;

/**
 * Initializes all the cells in the hash table as EMPTY
 */
void initHashTable(HashTable *ht); 
/**
 * hash(char) = char mod MAX
 */
int hash(char elem);
/**
 * ADT Operations
 */
void insert(char elem, HashTable *ht);
void delete(char elem, HashTable *ht);
bool isMember(char elem, HashTable ht);

/**
 * Utility Functions
 */
void displayHashTable(HashTable ht){
    int i;
    char hashString[20];
    for(i = 0; i < MAX; i++){
        char color[10];
        if(ht.Cells[i] == EMPTY) {
            strcpy(color, "\033[0;31m");
        } else if(ht.Cells[i] == DELETED) {
            strcpy(color, "\033[0;33m");
        } else {
            sprintf(hashString, "Hash Value = %d", hash(ht.Cells[i]));
            strcpy(color, "\033[0;32m");
        }
            
        printf("| [%d] - %s \'%c\' \033[1;0m | %s \n", i, color, ht.Cells[i], hashString);
        strcpy(hashString, "");
    }
}

int main(){
    HashTable ht;
    initHashTable(&ht);

    insert('a', &ht);
    insert('b', &ht);
    insert('c', &ht);

    delete('b', &ht);   

    // insert('t', &ht);

    char elem = 'a';
    // printf("Is \'%c\' a member: %s\n", elem, (isMember(elem, ht)) ? "Yes" : "No");
    displayHashTable(ht);

    return 0;
}


void initHashTable(HashTable *ht) {
    int i;
    ht->count = 0;
    for(i = 0; i < MAX; i++){
        ht->Cells[i] = EMPTY;
    }
}

int hash(char elem){
    return elem % MAX;
}

void insert(char elem, HashTable *ht){

    bool found = isMember(elem, *ht);

    if(ht->count < MAX && !found){
        int hashValue = hash(elem);

        if(ht->Cells[hashValue] == EMPTY){
            ht->Cells[hashValue] = elem;
        } else {
            int i = (hashValue + 1) % MAX;
            while(ht->Cells[i] != EMPTY && ht->Cells[i] != DELETED) {
                i = (i + 1) % MAX;
            }
            ht->Cells[i] = elem;
        }
        ht->count++;
    } else {
        printf("Failed insertion!\n");
    }
}

void delete(char elem, HashTable *ht){
    if(ht->count > 0){
        int hashValue = hash(elem);
        int i = hashValue % MAX;

        while(ht->Cells[i] != EMPTY){
            if(ht->Cells[i] == elem){
                ht->Cells[i] = DELETED;
                ht->count--;
                break;
            }
            i = (i + 1) % MAX;
        }
    }
}

bool isMember(char elem, HashTable ht){

    bool found = false;

    if(ht.count > 0){
        // Hashing the value
        int hashValue = hash(elem);
        int i = hashValue % MAX;

        // Probing
        while(ht.Cells[i] != EMPTY){
            if(ht.Cells[i] == elem){
                found = true;
                break;
            }
            i = (i + 1) % MAX;
        }
    }

    return found;
}
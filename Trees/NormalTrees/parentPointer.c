/**
 * @brief Parent-Pointer Representation of Trees (Array Implementation)
 * @details Cons: Does not support identifying the leftmost/rightmost child of a node.
 * @warning This file is not done yet.
 */


#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define ROOT 0

typedef int Tree[MAX];

Tree *initTree();
void insert(int data, int parent, Tree *T);
void inorder(int root, Tree T);
int root(Tree T);
int parent(int node, Tree T);


int main() {

    Tree *T = initTree();

    insert(2, ROOT, T);
    insert(3, 2, T);
    insert(4, 2, T);
    insert(5, 3, T);
    insert(6, 3, T);
    insert(7, 4, T);
    insert(8, 4, T);
    insert(9, 5, T);

    printf("Inorder Traversal: ");
    inorder(root(*T), *T);

    return 0;
}


Tree *initTree() {
    Tree *T = (Tree*)malloc(sizeof(Tree));
    for(int i = 0; i < MAX; i++) {
        (*T)[i] = -1;
    }
    return T;
}

void insert(int data, int parent, Tree *T) {
    if((*T)[data] == -1){
        (*T)[data] = parent;
    } else {
        printf("Node already exists\n");
    }
}

void inorder(int node, Tree T) {
    if (node != 0 && node < MAX && T[node] != -1) {
        printf("%d ", node);  // Visit node
        inorder(2 * node, T); // Visit left child
        inorder(2 * node + 1, T); // Visit right child
    }
}

int root(Tree T) {
    int i;
    for(i = 0; i < MAX && T[i] != 0; i++){}
    return i < MAX ? i : -1;
}

int parent(int node, Tree T) {
    return T[node];
}
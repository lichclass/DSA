#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} *Node;

Node initRoot();
Node createNode(int data);
void insert(int data, Node *root);
void inorder(Node root);


int main() {
    Node root = initRoot();
    
    insert(1, &root);
    insert(2, &root);
    insert(3, &root);
    insert(4, &root);
    insert(5, &root);
    insert(6, &root);

    inorder(root);

    return 0;
}

Node initRoot(){
    return NULL;
}

Node createNode(int data) {
    Node newNode = (Node)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(int data, Node *root){
    if(*root == NULL){
        *root = createNode(data);
    } else {
        if(data < (*root)->data){
            insert(data, &(*root)->left);
        } else {
            insert(data, &(*root)->right);
        }
    }
}

void inorder(Node root){
    if(root != NULL){
        printf("%d ", root->data);
        inorder(root->left);
        inorder(root->right);
    }
}
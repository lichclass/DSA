
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct node {
    int freq;
    struct node *left, *right;
} Node;

typedef struct {
    Node *data[MAX];
    int size;
} PriorityQueue;


Node* createNode(int freq) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->freq = freq;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void initQueue(PriorityQueue *pq) {
    pq->size = 0;
}

// Insert a node into the priority queue
void insert(PriorityQueue* pq, Node* node) {
    int i = pq->size++;
    while (i > 0 && pq->data[(i - 1) / 2]->freq > node->freq) {
        pq->data[i] = pq->data[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    pq->data[i] = node;
}

// Extract the node with the smallest frequency
Node* extractMin(PriorityQueue* pq) {
    Node* minNode = pq->data[0];
    Node* lastNode = pq->data[--pq->size];

    int i = 0;
    int child;
    while (i * 2 + 1 < pq->size) {
        child = i * 2 + 1;
        if (child + 1 < pq->size && pq->data[child + 1]->freq < pq->data[child]->freq) {
            child++;
        }
        if (lastNode->freq <= pq->data[child]->freq) break;
        pq->data[i] = pq->data[child];
        i = child;
    }
    pq->data[i] = lastNode;
    return minNode;
}


Node* buildHuffmanTree(PriorityQueue* pq) {
    while (pq->size > 1) {
        // Extract two nodes with the smallest frequency
        Node* left = extractMin(pq);
        Node* right = extractMin(pq);
        
        // Create a new internal node with these two nodes as children
        Node* newNode = createNode(left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        
        // Insert the new node back into the priority queue
        insert(pq, newNode);
    }
    
    // The remaining node is the root of the Huffman tree
    return extractMin(pq);
}

void printCodes(Node* root, int* code, int top) {
    if (root->left) {
        code[top] = 0;
        printCodes(root->left, code, top + 1);
    }
    if (root->right) {
        code[top] = 1;
        printCodes(root->right, code, top + 1);
    }
    if (!root->left && !root->right) {
        printf("Character with frequency %d has code: ", root->freq);
        for (int i = 0; i < top; i++) {
            printf("%d", code[i]);
        }
        printf("\n");
    }
}

int main() {
    // Example frequencies
    int freqs[] = {5, 9, 12, 13, 16, 45};
    int n = sizeof(freqs) / sizeof(freqs[0]);
    
    PriorityQueue pq;
    initQueue(&pq);

    // Insert all nodes into the priority queue
    for (int i = 0; i < n; i++) {
        insert(&pq, createNode(freqs[i]));
    }
    
    // Build the Huffman Tree
    Node* root = buildHuffmanTree(&pq);
    
    // Print Huffman Codes
    int code[100];
    printCodes(root, code, 0);
    
    return 0;
}

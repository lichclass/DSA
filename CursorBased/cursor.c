/*=======================================
Output:
    List: A B C D E 
    List: A B C D E 
    L1 and L2 are equal
    List: A B D E 
    List: A B D E 
    L1 and L2 are equal
    List: B D E 
    List: B D E 
    L1 and L2 are equal
=======================================*/

#include <stdio.h>

#define MAX_HEAP 32

typedef struct {
    char elem;
    int next;
} NodeType;

typedef struct {
    NodeType Nodes[MAX_HEAP];
    int avail;
} VirtualHeap;

typedef int List;

typedef enum {false, true} boolean;

// Heap Management Operations
void initVirtualHeap(VirtualHeap *VH);
int allocSpace(VirtualHeap *VH);
void deallocSpace(VirtualHeap *VH, int index);

// List Operations
void initList(List *L);
void insertFirst(List *L, char elem, VirtualHeap *VH);
void insertLast(List *L, char elem, VirtualHeap *VH);
boolean findElem(List L, char elem, VirtualHeap *VH);
void deleteElem(List *L, char elem, VirtualHeap *VH);
void deleteAllOccurences(List *L, char elem, VirtualHeap *VH);
void insertSorted(List *L, char elem, VirtualHeap *VH);
boolean isEqualList(List L1, List L2, VirtualHeap *VH);

// Display Operations
void displayList(List L, VirtualHeap *VH);


/**
 * Main Function
 */
int main(){
    VirtualHeap VH;
    initVirtualHeap(&VH);

    List L1, L2;
    initList(&L1);
    initList(&L2);

    insertLast(&L1, 'A', &VH);
    insertLast(&L1, 'B', &VH);
    insertLast(&L1, 'C', &VH);
    insertLast(&L1, 'D', &VH);
    insertLast(&L1, 'E', &VH);

    insertLast(&L2, 'A', &VH);
    insertLast(&L2, 'B', &VH);
    insertLast(&L2, 'C', &VH);
    insertLast(&L2, 'D', &VH);
    insertLast(&L2, 'E', &VH);

    displayList(L1, &VH);
    displayList(L2, &VH);

    printf("L1 and L2 are %s\n", isEqualList(L1, L2, &VH) ? "equal" : "not equal");

    deleteElem(&L1, 'C', &VH);
    deleteElem(&L2, 'C', &VH);

    displayList(L1, &VH);
    displayList(L2, &VH);

    printf("L1 and L2 are %s\n", isEqualList(L1, L2, &VH) ? "equal" : "not equal");

    deleteAllOccurences(&L1, 'A', &VH);
    deleteAllOccurences(&L2, 'A', &VH);

    displayList(L1, &VH);
    displayList(L2, &VH);

    printf("L1 and L2 are %s\n", isEqualList(L1, L2, &VH) ? "equal" : "not equal");

    return 0;
}

/**
 * Display Operations
 */
void displayList(List L, VirtualHeap *VH) {
    List trav;
    printf("List: ");
    for(trav = L; trav != -1; trav = VH->Nodes[trav].next) {
        printf("%c ", VH->Nodes[trav].elem);
    }
    printf("\n");
}


/**
 * Heap Management Operations
 */
void initVirtualHeap(VirtualHeap *VH) {
    VH->avail = 0;
    int i;
    for (i = 0; i < MAX_HEAP - 1; i++) {
        VH->Nodes[i].next = i + 1;
    }
    VH->Nodes[i].next = -1;
}

int allocSpace(VirtualHeap *VH) {
    int space = VH->avail;
    if (space != -1) {
        VH->avail = VH->Nodes[space].next;
    }
    return space;
}

void deallocSpace(VirtualHeap *VH, int index) {
    VH->Nodes[index].next = VH->avail;
    VH->avail = index;
}


/**
 * List Operations
 */
void initList(List *L) {
    *L = -1;
}

void insertFirst(List *L, char elem, VirtualHeap *VH) {
    int space = allocSpace(VH);
    if (space != -1) {
        VH->Nodes[space].elem = elem;
        VH->Nodes[space].next = *L;
        *L = space;
    }
}

void insertLast(List *L, char elem, VirtualHeap *VH) {
    int space = allocSpace(VH);
    if (space != -1) {
        List *trav;
        for (trav = L; *trav != -1; trav = &VH->Nodes[*trav].next){}
        VH->Nodes[space].elem = elem;
        VH->Nodes[space].next = -1;
        *trav = space;
    }
}

boolean findElem(List L, char elem, VirtualHeap *VH) {
    List trav;
    for (trav = L; trav != -1 && VH->Nodes[trav].elem != elem; trav = VH->Nodes[trav].next){}
    return (trav != -1) ? true : false;
}

void deleteElem(List *L, char elem, VirtualHeap *VH) {
    List *trav, temp;
    for (trav = L; *trav != -1 && VH->Nodes[*trav].elem != elem; trav = &VH->Nodes[*trav].next){}
    if (*trav != -1) {
        temp = *trav;
        *trav = VH->Nodes[*trav].next;
        deallocSpace(VH, temp);
    }
}

void deleteAllOccurences(List *L, char elem, VirtualHeap *VH) {
    List *trav = L, temp;
    while (*trav != -1) {
        if (VH->Nodes[*trav].elem == elem) {
            temp = *trav;
            *trav = VH->Nodes[*trav].next;
            deallocSpace(VH, temp);
        } else {
            trav = &VH->Nodes[*trav].next;
        }
    }
}

void insertSorted(List *L, char elem, VirtualHeap *VH) {
    List *trav, space;
    space = allocSpace(VH);
    if (space != -1) {
        for (trav = L; *trav != -1 && VH->Nodes[*trav].elem < elem; trav = &VH->Nodes[*trav].next){}
        VH->Nodes[space].elem = elem;
        VH->Nodes[space].next = *trav;
        *trav = space;
    }
}

boolean isEqualList(List L1, List L2, VirtualHeap *VH) {
    List trav1, trav2;
    for (trav1 = L1, 
         trav2 = L2; 
            (trav1 != -1 && trav2 != -1) &&
            (VH->Nodes[trav1].elem == VH->Nodes[trav2].elem); 
                                 trav1 = VH->Nodes[trav1].next, trav2 = VH->Nodes[trav2].next) {
    }
    return (trav1 == -1 && trav2 == -1) ? true : false;
}






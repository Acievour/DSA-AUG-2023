#include <stdio.h>

#define MAX 20

typedef struct {
    int data;
    int link;
} HeapSpace;

typedef struct {
    HeapSpace nodes[MAX];
    int avail;
} VirtualHeap;

typedef int List;

void initVirtualHeap(VirtualHeap *VH) { // using version 2
    int i;
    for(i = MAX - 1; i >= 0; i--) {
        VH->nodes[i].link = i - 1;
    }
    VH->avail = MAX - 1;
}

int allocSpace(VirtualHeap *VH) {
    int retval = VH->avail;
    if(retval != -1) {
        VH->avail = VH->nodes[retval].link;
    }
    return retval;
}

void deallocSpace(VirtualHeap *VH, int index) {
    if(index != -1 && index < MAX) {
        VH->nodes[index].link = VH->avail;
        VH->avail = index;
    }
}

void insertFirst(VirtualHeap *VH, List *L, int elem) {
    List temp = allocSpace(VH);
    if(temp != -1) {
        VH->nodes[temp].data = elem;
        VH->nodes[temp].link = *L;
        *L = temp;
    }
}

void insertElem(VirtualHeap *VH, List *L, int elem) { // or insertLast
    List *trav, temp = allocSpace(VH);
    if(temp != -1) {
        for(trav = L; *trav != -1; trav = &VH->nodes[*trav].link) {}
        VH->nodes[temp].data = elem;
        VH->nodes[temp].link = *trav;
        *trav = temp;
    }
}

void insertSorted(List *L, VirtualHeap *VH, int elem) {
    List *trav, temp = allocSpace(VH);
    if(temp != -1) {
        for(trav = L; *trav != -1 && VH->nodes[*trav].data < elem; trav = &VH->nodes[*trav].link) {}
        VH->nodes[temp].data = elem;
        VH->nodes[temp].link = *trav;
        *trav = temp;
    }
}

void deleteElem(VirtualHeap *VH, List *L, int elem) {
    List *trav, temp;
    for(trav = L; *trav != -1 && VH->nodes[*trav].data != elem; trav = &VH->nodes[*trav].link) {}
    if(*trav != -1) {
        temp = *trav;
        *trav = VH->nodes[temp].link;
        deallocSpace(VH, temp);
    }
}

// void deleteAllOccur(VirtualHeap *VH, List *L, int elem) {

// }

void displayList(VirtualHeap VH, List L) {
    List trav;
    for(trav = L; trav != -1; trav = VH.nodes[trav].link) {
        printf("%d ", VH.nodes[trav].data);
    }
}

int main() {
    List A;
    VirtualHeap V;
    initVirtualHeap(&V);

    insertFirst(&V, &A, 10);
    insertFirst(&V, &A, 10);
    insertFirst(&V, &A, 27);
    insertFirst(&V, &A, 27);
    insertFirst(&V, &A, 76);
    insertFirst(&V, &A, 33);
    insertFirst(&V, &A, 27);
    insertFirst(&V, &A, 27);


    printf("\n");
    displayList(V, A);

    insertElem(&V, &A, 56);

    printf("\n");
    displayList(V, A);

    return 0;
}
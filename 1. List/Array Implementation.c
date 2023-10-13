#include <stdio.h>

#define MAX 10

typedef struct {
    int data[MAX];
    int count;
} List;

void initList(List *L) {
    L->count = 0;
}

void insertFirst(List *L, int elem) {
    if(L->count < MAX) {
        int i;
        for(i = L->count; i >= 0; i--) {
            L->data[i] = L->data[i - 1];
        }
        L->data[0] = elem;
        L->count++;
    }
}

void insertPos(List *L, int elem, int pos) {
    if(L->count < MAX) {
        int i;
        for(i = L->count; i > pos; i--) {
            L->data[i] = L->data[i - 1];
        }
        L->data[pos] = elem;
        L->count++;
    }
}

void insertElem(List *L, int elem) { // or insertLast
    if(L->count < MAX) {
        L->data[L->count] = elem;
        L->count++;
    }
}

void deleteFirst(List *L) {
    if(L->count != 0) {
        int i;
        for(i = 0; i < L->count; i++) {
            L->data[i] = L->data[i + 1];
        }
        L->count--;
    }
}

void deletePos(List *L, int pos) {
    if(L->count != 0) {
        int i;
        for(i = pos; i < L->count; i++) {
            L->data[i] = L->data[i + 1];
        }
        L->count--;
    }
}

void deleteElem(List *L) { // or deleteLast
    if(L->count != 0) {
        L->count--;
    }
}

void displayList(List L) {
    int i;
    for(i = 0; i < L.count; i++) {
        printf("%d ", L.data[i]);
    }
}

int main() {
    List A;
    initList(&A);

    insertElem(&A, 1);
    insertElem(&A, 4);
    insertElem(&A, 7);

    displayList(A);
    printf("\n");

    insertPos(&A, 10, 3);

    displayList(A);
    printf("\n");

    insertFirst(&A, 16);

    displayList(A);
    printf("\n");

    deleteElem(&A);

    displayList(A);
    printf("\n");

    deletePos(&A, 2);

    displayList(A);
    printf("\n");

    deleteFirst(&A);
    
    displayList(A);
    printf("\n");

    return 0;
}
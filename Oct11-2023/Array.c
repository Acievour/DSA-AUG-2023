#include <stdio.h>
#define MAX 10

typedef struct {
    char data[MAX];
    int count;
} ArrayList;

typedef enum {TRUE, FALSE} Boolean;

void initArr(ArrayList *A) {
    A->count = 0;
}

void insertElem(ArrayList *A, char elem) {
    if(A->count < MAX) {
        A->data[A->count] = elem;
        A->count++;
    } else {
        printf("Array is full!");
    }
}

void insertFront(ArrayList *A, char elem) {
    if(A->count < MAX) {
        int i;
        for(i = A->count; i > 0; i--) {
            A->data[i] = A->data[i - 1];
        }
        A->data[0] = elem;
        A->count++;
    } else {
        printf("Array is full!");
    }
}

void displayList(ArrayList A) {
    int i;
    for(i = 0; i < A.count; i++) {
        printf("%c ", A.data[i]);
    }
}

Boolean findElem(ArrayList L, char elem) {
    int x;
    for(x = 0; x < L.count && L.data[x] != elem; x++) {}
    return (x < L.count) ? TRUE : FALSE;
}



// void deleteFirstOccur(ArrayList *L, char elem) {
//     int x;
//     for(x = 0; x < L->count && L->data[x] != elem; x++) {}
//     if(L->data[x] == elem) {

//     }
// }

int main() {
    ArrayList new;
    initArr(&new);

    insertElem(&new, 'A');
    insertElem(&new, 'B');
    insertElem(&new, 'Z');

    printf("\n");
    displayList(new);

    insertFront(&new, 'V');

    printf("\n");
    displayList(new);
}
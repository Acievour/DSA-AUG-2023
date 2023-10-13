#include <stdio.h>

#define MAX 12
#define EMPTY -1
#define DELETED -2

typedef struct {
    int data[MAX];
    int last;
} Dictionary;

void initDict(Dictionary *D) {
    int i;
    for(i = 0; i < MAX; i++) {
        D->data[i] = EMPTY;
    }
    D->last = -1;
}

int Hash(int elem) {
    return elem % MAX;
}

void insertElem(Dictionary *D, int elem) {
    int hashV = Hash(elem);
    int i, j;
    for(i = hashV, j = 0; D->data[i] > -1 && j < MAX; i = (i + 1) % MAX, j++) {}
    D->last++;
    D->data[i] = elem;
}

void deleteElem(Dictionary *D, int elem) {
    int hashV = Hash(elem);
    int i, j;
    for(i = hashV, j = 0; j < MAX && D->data[i] != elem; i = (i + 1) % MAX, j++) {}
    if(j < MAX) {
        D->last--;
        D->data[i] = DELETED;
    }
}

void insertElemVar1(Dictionary *D, int elem) { // Variation 1 insert
    int hashV = Hash(elem);
    if(D->data[hashV] == EMPTY || D->data[hashV] == DELETED) {
        D->data[hashV] = elem;
    } else if(D->last < MAX - 1) {
        D->last++;
        D->data[D->last] = elem;
    }
}

void deleteElemVar1(Dictionary *D, int elem) { // Variation 1 insert
    int hashV = Hash(elem);
    int i;
    if(D->data[hashV] == elem) {
        D->data[hashV] = DELETED;
    } else {
        for(i = MAX * 0.8; i <= D->last && elem != D->data[i]; i++) {}
        if(i <= D->last) {
            D->data[i] = D->data[D->last];
            --D->last;
        }
    }
}

void display(Dictionary D) {
    int i;
    printf("%-10s %-10s\n", "INDEX", "DATA");
    for(i = 0; i < MAX; i++){
        printf("%-10d %-10d\n", i, D.data[i]);
    }
}

int main()
{

    Dictionary A;
    initDict(&A);

    insertElemVar1(&A, 29);
    insertElemVar1(&A, 12);
    insertElemVar1(&A, 30);
    insertElemVar1(&A, 58);
    // delete(&A, 30);
    insertElemVar1(&A, 48);


    display(A);

    return 0;
}
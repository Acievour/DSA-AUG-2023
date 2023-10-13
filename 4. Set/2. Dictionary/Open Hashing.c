#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct node {
    int data;
    struct node *link;
} SType, *ptr;

typedef ptr Dictionary[MAX];

typedef int Set[MAX];

int hash(int value) {
    return value % MAX;
}

void initDict(Dictionary D) {
    int i;
    for(i = 0; i < MAX; i++) {
        D[i] = NULL;
    }
}

void PopDict(Dictionary D, Set A) {
    int i, hashV;
    ptr *trav;

    for(i = 0; i < MAX; i++) {
        hashV = hash(A[i]);
        for(trav = &D[hashV]; *trav != NULL && A[i] != (*trav)->data; trav = &(*trav)->link) {}
        if(*trav == NULL) {
            *trav = (ptr)malloc(sizeof(SType));
            if(*trav != NULL) {
                (*trav)->data = A[i];
                (*trav)->link = NULL;
            }
        }
    }
}
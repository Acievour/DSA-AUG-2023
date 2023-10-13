#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int data[MAX];
    int count;
} Set;

void initSet(Set *S) {
    S->count = 0;
}

void insertSorted(Set *S, int elem) {
    int i, j;
    for(i = 0; i < S->count && S->data[i] < elem; i++) {
        if(S->data[i] != elem) {
            for(j = i; j < S->count; j++) {
                S->data[j + 1] = S->data[j];
                S->data[i] = elem;
            }
        }
    }
}

Set Union(Set A, Set B) {
    Set C;
    int x = 0, y = 0;
    initSet(&C);
    while(x < A.count && b < B.count) {
        if(A.data[x] < B.data[b]) {
            C.data[C.count] = A.data[x];
            x++;
        } else {
            if(A.data[x] == B.data[y]) {
                x++;
            }
            C.data[C.count] = B.data[y];
            y++;
        }
        C.count++;
    }
    if(y < B.count) {
        A = B;
        x = y;
    }
    while(x < A.count) {
        C.data[C.count] = A.data[x];
        x++;
        C.count++;
    }
    return C;
}

Set Intersection(Set A, Set B) {
    Set C;
    int x, y;
    initSet(&C);
    for(x = 0; x < A.count; x++) {
        for(y = 0; y < B.count && A.data[x] > B.data[y]; y++) {}
        if(y < B.count && A.data[x] == B.data[y]) {
            C.data[C.count] = A.data[x];
            C.count++;
        }
    }
    return C;
}

Set Difference(Set A, Set B) {
    Set C;
    int x, y;
    initSet(&C);
    for(x = 0; x < A.count; x++) {
        for(y = 0; y < B.count && A.data[x] < B.data[y]; y++) {}
        if(A.data[x] != B.data[y]) {
            C.data[C.count] = A.data[x];
            C.count++;
        }
    }
}
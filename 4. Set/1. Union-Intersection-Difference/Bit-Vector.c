#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef int Set[MAX];

Set *UnionV1(Set A, Set B) {
    Set *retval = (Set*)malloc(sizeof(Set));
    int i;
    for(i = 0; i < MAX; i++) {
        (*retval)[i] = A[i] || B[i];
    }
    return retval;
}

Set *UnionV2(Set A, Set B) {
    Set *C;
    C = NULL;
    int i;
    C = (Set*)calloc(1, sizeof(Set));
    if(C != NULL) {
        for(i = 0; i < MAX; i++) {
            (*C)[i] = A[i] || B[i];
        }
    }
    return C;
}

Set *IntersectionV1(Set A, Set B) {
    Set *retval = (Set*)malloc(sizeof(Set));
    int i;
    for(i = 0; i < MAX; i++) {
        (*retval)[i] = A[i] && B[i];
    }
    return retval;
}

Set *IntersectionV2(Set A, Set B) {
    Set *C;
    int i;
    C = NULL;
    C = (Set*)malloc(sizeof(Set));
    if(C != NULL) {
        for(i = 0; i < MAX; i++) {
            (*C)[i] = A[i] && B[i];
        }
    }
    return C;
}

Set *DifferenceV1(Set A, Set B) {
    Set *retval = (Set*)malloc(sizeof(Set));
    int i;
    for(i = 0; i < MAX; i++) {
        (*retval)[i] = A[i] &~ B[i];
    }
    return retval;
}

void insert(Set A, int elem) {
    if(elem < MAX && elem > -1) {
        A[elem] |= 1;
    }
}

void delete(Set A, int elem) {
    if(elem < MAX && elem > -1) {
        A[elem] &= 0;
    }
}

void displaySet(Set S) {
    int i;
    printf("{ ");
    for(i = 0; i < MAX; i++) {
        if(S[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("}");
    printf("\n");
}
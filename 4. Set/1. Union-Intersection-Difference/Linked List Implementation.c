#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *link;
} *Set;

void initSet(Set *S) {
    *S = NULL;
}

Set Union(Set A, Set B) {
    Set C, *trav;
    initSet(&C);
    trav = &C;

    while(A != NULL && B != NULL) {
        *trav = (Set)malloc(sizeof(struct node));
        if(*trav != NULL) {
            if(A->data < B->data) {
                (*trav)->data = A->data;
                A = A->link;
            } else {
                if(A->data == B->data) {
                    A = A->link;
                }
                (*trav)->data = B->data;
                B = B->link;
            }
            trav = &(*trav)->link;
        }
    }

    if(A == NULL && B != NULL) {
        A = B;
    }

    while(A != NULL) {
        (*trav) = (Set)malloc(sizeof(struct node));
        if(*trav != NULL) {
            (*trav)->data = A->data;
            trav = &(*trav)->link;
            A = A->link;
        }
    }

    *trav = NULL;
    return C;
}

Set Intersection(Set A, Set B) {
    Set *trav, C, temp;
    initSet(&C);
    trav = &C;
    for(; A != NULL; A = A->link) {
        for(temp = B; temp != NULL && A->data > temp->data; temp = temp->link) {}
        if(temp != NULL && A->data == temp->link) {
            *trav = (Set)malloc(sizeof(struct node));
            if(*trav != NULL) {
                (*trav)->data = A->data;
                trav = &(*trav)->link;
            }
        }
    }

    *trav = NULL;
    return C;
}
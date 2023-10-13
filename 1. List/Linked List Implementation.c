#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *link;
} *List;

void initList(List *L) {
    *L = NULL;
}

void insertFirst(List *L, int elem) {
    List temp = (List)malloc(sizeof(struct node));
    if(temp != NULL) {
        temp->data = elem;
        temp->link = *L;
        *L = temp;
    }
}

void insertLast(List *L, int elem) {
    List temp = (List)malloc(sizeof(struct node));
    if(temp != NULL) {
        List *trav;
        for(trav = L; *trav != NULL; trav = &(*trav)->link) {}
        temp->data = elem;
        temp->link = *trav;
        *trav = temp;
    }
}

void deleteElem(List *L, int elem) {
    List temp = (List)malloc(sizeof(struct node));
    if(temp != NULL) {
        List *trav;
        for(trav = L; *trav != NULL && (*trav)->data != elem; trav = &(*trav)->link) {}
        if(*trav != NULL) {
            temp = *trav;
            *trav = temp->link;
            free(temp);
        }
    }
}

void deleteAllOccur(List *L, int elem) { // this has error
    List *trav, temp;
    for(trav = L; *trav != NULL; trav = &(*trav)->link) {
        if((*trav)->data == elem) {
            temp = *trav;
            *trav = (*trav)->link;
            free(temp);
        }
    }
}

void deleteFirstOccur(List *L, int elem) {
    List temp = (List)malloc(sizeof(struct node));
    if(temp != NULL) {
        List *trav;
        for(trav = L; *trav != NULL && (*trav)->data != elem; trav = &(*trav)->link) {}
        if(*trav != NULL) {
            temp = *trav;
            *trav = temp->link;
            free(temp);
        }
    }
}

void displayList(List L) {
    List trav;
    for(trav = L; trav != NULL; trav = trav->link) {
        printf("%d ", trav->data);
    }
}

int main() {
    List A;
    initList(&A);

    insertFirst(&A, 10);
    insertFirst(&A, 27);
    insertFirst(&A, 27);
    insertFirst(&A, 76);
    insertFirst(&A, 33);
    insertFirst(&A, 27);
    insertFirst(&A, 27);


    printf("\n");
    displayList(A);

    insertLast(&A, 56);

    printf("\n");
    displayList(A);

    deleteAllOccur(&A, 27);

    printf("\n");
    displayList(A);

    return 0;
}
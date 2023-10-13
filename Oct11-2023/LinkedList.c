#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node *link;
} *LIST;

typedef enum {TRUE, FALSE} Boolean;

void initList(LIST *L) {
    *L = NULL;
}

void insertFirst(LIST *L, char elem) {
    LIST temp = (LIST)malloc(sizeof(struct node));
    if(temp != NULL) {
        temp->data = elem;
        temp->link = *L;
        *L = temp;
    }
}

void insertLast(LIST *L, char elem) {
    LIST *trav, temp = (LIST)malloc(sizeof(struct node));
    if(temp != NULL) {
        for(trav = L; *trav != NULL; trav = &(*trav)->link){}
        temp->data = elem;
        temp->link = *trav;
        *trav = temp;
    }
}

void deleteElem(LIST *L, char elem) {
    LIST *trav, temp = (LIST)malloc(sizeof(struct node));
    if(temp != NULL) {
        for(trav = L; *trav != NULL && (*trav)->data != elem; trav = &(*trav)->link){}
        if(*trav != NULL) {
            temp = *trav;
            *trav = temp->link;
            free(temp);
        }
    }
}

void deleteAllOccur(LIST *L, char elem) {
    LIST *trav, temp;
    for(trav = L; *trav != NULL; trav = &(*trav)->link) {
        if((*trav)->data == elem) {
            temp = *trav;
            *trav = (*trav)->link;
            free(temp);
        }
    }
}

void deleteFirstOccur(LIST *L, char elem) {
    LIST *trav, temp;
    for(trav = L; *trav != NULL && (*trav)->data != elem; trav = &(*trav)->link) {}
    if(*trav != NULL) {
        temp = *trav;
        *trav = temp->link;
        free(temp);
    }
}

void displayList(LIST L) {
    LIST trav;

    for(trav = L; trav != NULL; trav = trav->link) {
        printf("%c ", trav->data);
    }
}

Boolean findElem(LIST L, char elem) {
    LIST trav;
    for(trav = L; trav != NULL && trav->data != elem; trav = trav->link) {}
    return (trav != NULL) ? TRUE : FALSE;
}

int main() {
    LIST new;
    initList(&new);

    insertFirst(&new, 'A');
    insertFirst(&new, 'B');
    insertFirst(&new, 'Z');

    printf("\n");
    displayList(new);

    insertLast(&new, 'B');
    insertLast(&new, 'C');
    insertLast(&new, 'T');

    printf("\n");
    displayList(new);

    deleteElem(&new, 'Z');

    printf("\n");
    displayList(new);

    return 0;
}
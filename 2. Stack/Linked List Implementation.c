#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *link;
} SType, *Stack;

void initStack(Stack *S) {
    *S = NULL;
}

void push(Stack *S, int elem) { // basically is insertLast
    Stack temp = (Stack)malloc(sizeof(SType));
    if(temp != NULL) {
        temp->data = elem;
        temp->link = *S;
        *S = temp;
    }
}

void pop(Stack *S, int elem) { // basically is deleteFirst
    Stack temp;
    if(*S != NULL) {
        temp = *S;
        *S = temp->link;
        free(temp);
    }
}

void insertBottom(Stack *S, int elem) {
    Stack temp, newstack = NULL;

    while(*S != NULL) {
        temp = *S;
        *S = temp->link;
        temp->link = newstack;
        newstack = temp;
    } 

    temp = (Stack)malloc(sizeof(SType));

    if(temp != NULL) {
        temp->data = elem;
        temp->link = *S;
        *S = temp;

        while(newstack != NULL) {
            temp = newstack;
            newstack = temp->link;
            temp->link = *S;
            *S = temp;
        }
    }
}

void deleteElem(Stack *S, int elem) {
    Stack temp, newstack = NULL;

    while(*S != NULL && S->elem < elem) {
        temp = *S;
        *S = temp->link;
        temp->link = newstack;
        newstack = temp;
    }

    if(*S != NULL && S->elem == elem) {
        temp = *S;
        *S = temp->link;
        free(temp);
    }

    while(newstack != NULL) {
        temp = newstack;
        newstack = temp->link;
        temp->link = *S;
        *S = temp;
    }
}
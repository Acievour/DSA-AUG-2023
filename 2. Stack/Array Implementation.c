#include <stdio.h>

#define MAX 10

typedef struct {
    int data[MAX];
    int top;
} Stack;

void initStack(Stack *S) {
    S->top = -1;
}

int isEmpty(Stack S) {
    return S.top == -1;
}

int isFull(Stack S) {
    return S.top == MAX - 1;
}

void pop(Stack *S) {
    if(!isEmpty(*S)) {
        S->top--;
    }
}

void push(Stack *S, int elem) {
    if(!isFull(*S)) {
        S->top++;
        S->data[S->top] = elem;
    }
}

void insertBottomV1(Stack *S, int elem) { // using functions
    if(!isFull(*S)) {
        if(!isEmpty(*S)) {
            push(S, elem);
        } else {
            Stack temp;
            initStack(&temp);

            while(!isEmpty(*S)) {
                push(&temp, S->data[S->top]);
                pop(S);
            }

            push(S, elem);

            while(!isEmpty(temp)) {
                push(S, temp.data[temp.top]);
                pop(&temp);
            }
        }
    }
}

void insertBottomV2(Stack *S, int elem) { // without using functions
    if(S->top != MAX - 1) {
        if(S->top != -1) {
            S->top++;
            S->data[S->top] = elem;
        } else {
            Stack temp;
            temp.top = -1;

            while(S->top != -1) {
                temp.top++;
                temp.data[temp.top] = S->data[S->top];
                --S->top;
            }

            S->top++;
            S->data[S->top] = elem;

            while(temp.top != -1) {
                S->top++;
                S->data[S->top] = temp.data[temp.top];
                --temp.top;
            }
        }
    }
}

void deleteElem(Stack *S, int elem) {
    Stack temp;
    temp.top = -1;

    if(S->top != -1) {
        while(S->top != -1 && S->data[S->top] < elem) {
            temp.top++;
            temp.data[temp.top] = S->data[S->top];
            S->top--;
        }

        if(S->top != -1 && S->data[S->top] == data) {
            S->top--;
        }

        while(temp.top != -1) {
            S->top++;
            S->data[S->top] = temp.data[temp.top];
            temp.top--;
        }
    }
}
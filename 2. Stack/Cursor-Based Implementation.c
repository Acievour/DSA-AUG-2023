#include <stdio.h>

#define MAX 10

typedef struct {
    int data;
    int link;
} HeapSpace;

typedef struct {
    HeapSpace nodes[MAX];
    int avail;
} VirtualSpace;

typedef int Stack;

void initStack(VirtualSpace *VH, Stack *S) {
    int i;
    *S = -1;
    for(i = MAX - 1; i >= 0; i--) {
        VH->nodes[i] = i - 1;
    }
    VH->avail = MAX - 1;
}

void push(VirtualSpace *VH, Stack *S, int elem) {
    Stack temp;
    if(VH->avail != -1) {
        temp = VH->avail;
        VH->avail = VH->nodes[temp].link;
        VH->nodes[temp].data = data;
        VH->nodes[temp].link = *S;
        *S = temp;
    }
}

void pop(VirtualSpace *VH, Stack *S) {
    Stack temp;
    if(*S != -1) {
        temp = *S;
        *S = VH->nodes[temp].link;
        VH->nodes[temp].link = VH->avail;
        VH->avail = temp;
    }
}

void insertBottom(VirtualSpace *VH, Stack *S, int elem) {
    Stack temp, newstack = -1;
    if(VH->avail != -1) {
        while(*S != -1) {
            temp = *S;
            *S = VH->nodes[temp].link;
            VH->nodes[temp].link = newstack;
            newstack = temp;
        }

        temp = VH->avail;
        VH->avail = VH->nodes[temp].link;
        VH->nodes[temp].data = elem;
        VH->nodes[temp].link = *S;
        *S = temp;

        while(newstack != -1) {
            temp = newstack;
            newstack = VH->nodes[temp].link;
            VH->nodes[temp].link = *S;
            *S = temp;
        }
    }
}

void deleteElem(VirtualSpace *VH, Stack *S, int elem) {
    Stack temp, newstack = -1;

    while(*S != -1 && VH->nodes[*S].data < data) {
        temp = *S;
        *S = VH->nodes[temp].link;
        VH->nodes[temp].link = newstack;
        newstack = temp;
    }

    if(*S != -1 && VH->nodes[*S].data = elem) {
        temp = *S;
        *S = VH->nodes[temp].link;
        VH->nodes[temp].link = VH->avail;
        VH->avail = temp;
    }

    while(newstack != -1) {
        temp = newstack;
        newstack = VH->nodes[temp].link;
        VH->nodes[temp].link = *S;
        *S = temp;
    }
}
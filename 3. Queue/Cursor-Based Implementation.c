#include <stdio.h>

#define MAX 10

typedef struct {
    int data;
    int link;
} SType, Nodetype[MAX];

typedef struct {
    Nodetype nodes;
    int avail;
} VirtualSpace;

typedef struct {
    int front;
    int rear;
} Queue;

void initQueue(Queue *Q) {
    Q->front = -1;
    Q->rear = -1;
}

void enqueue(VirtualSpace *VH, Queue *Q, int elem) {
    int temp = VH->avail;
    if(temp != -1) {
        VH->avail = VH->nodes[temp].link;
        VH->nodes[temp].data = elem;
        VH->nodes[temp].link = -1;

        (Q->rear == -1) ? Q->front = temp : Q->rear->link = temp;
        
        Q->rear = temp;
    }
}

void dequeue(VirtualSpace *VH, Queue *Q) {
    int temp = Q->front;
    if(temp != -1) {
        Q->front = VH->nodes[temp].link;
        VH->nodes[temp].link = VH->avail;
        VH->avail = temp;
        if(Q->front == -1) {
            Q->rear = -1;
        }
    }
}
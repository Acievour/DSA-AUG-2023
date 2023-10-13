#include <stdio.h>

#define MAX 10

typedef struct {
    int data[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue *Q) {
    Q->front = 0;
    Q->rear = -1;
}

int isEmpty(Queue Q) {
    return (Q.rear + 1) % MAX == Q.front;
}

int isFull(Queue Q) {
    return (Q.rear + 2) % MAX == Q.front;
}

void enqueue(Queue *Q, int elem) {
    if(!isFull(*Q)) {
        Q->rear = (Q->rear + 1) % MAX;
        Q->data[Q->rear] = elem;
    }
}

void dequeue(Queue *Q) {
    if(!isEmpty(*Q)) {
        Q->front = (Q->front + 1) % MAX;
    }
}

void displayQueue(Queue Q) {
    while(!isEmpty(Q)) {
        printf("%d ", Q.data[Q.front]);
        dequeue(&Q);
    }
}
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *link;
} Nodetype, *List;

typedef struct {
    List front;
    List rear;
} Queue;

void initQueue(Queue *Q) {
    Q->front = NULL;
    Q->rear = NULL;
}

void enqueue(Queue *Q, int elem) {
    List temp = (List)malloc(sizeof(Nodetype));
    if(temp != NULL) {
        temp->data = elem;
        temp->link = NULL;

        (Q->rear == NULL) ? Q->front = temp : Q->rear->link = temp;
        
        Q->rear = temp;
    }
}

void dequeue(Queue *Q, int elem) {
    List temp = (List)malloc(sizeof(Nodetype));
    if(temp != NULL) {
        temp = Q->front;
        Q->front = temp->link;
        free(temp);
        if(Q->front == NULL) {
            Q->rear = NULL;
        }
    }
}
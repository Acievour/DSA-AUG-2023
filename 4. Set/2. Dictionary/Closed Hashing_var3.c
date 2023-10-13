#include <stdio.h>

#define MAX 12
#define EMPTY -1
#define DELETED -2

typedef struct {
    int data;
    int next;
} node, HSpace[MAX];

typedef struct {
    HSpace table;
    int avail;
} Dictionary;

int Hash(int elem) {
    return elem % MAX;
}

void insertElem(Dictionary *D, int elem) { // Vartiation 3
    int hashV = Hash(elem);
    int temp;
    if(D->table[hashV].data == EMPTY || D->table[hashV].data == DELETED) {
        D->table[hashV].data = elem;
    } else {
        temp = D->avail;
        if(temp != -1) {
            D->avail = D->table[temp].next;
            D->table[temp].data = elem;
            D->table[temp].next = D->table[hashV].next;
            D->table[hashV].next = temp;
        }
    }
}

void deleteElem(Dictionary *D, int elem) { // Vartiation 3
    int hashV = Hash(elem);
    int temp, *trav;
    if(D->table[hashV].data == elem) {
        D->table[hashV].data = DELETED;
    } else {
        for(trav = &D->table[hashV].next; *trav != -1 && elem != D->table[*trav].data; trav = &D->table[*trav].next) {}
        if(*trav != -1) {
            temp = *trav;
            *trav = D->table[temp].next;
            D->table[temp].next = D->avail;
            D->avail = temp;
        }
    }
}
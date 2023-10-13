#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int data;
    int link;
} SType, HeapSpace[MAX];

typedef struct {
    HeapSpace nodes;
    int avail;
} VirtualSpace;

typedef int Set;

Set Union(VirtualSpace *VH,Set A, Set B) {
    Set C, *trav;
    C = -1;
    trav = &C;

    while(A != -1 && B != -1) {
        *trav = VH->avail;
        if(*trav != -1) {
            VH->avail = VH->nodes[*trav].link;
            if(VH->nodes[A].data < VH->nodes[B].data) {
                VH->nodes[*trav].data = VH->nodes[A].data;
                A = VH->nodes[A].link;
            } else {
                if(VH->nodes[A].data == VH->nodes[B].data) {
                    A = VH->nodes[A].link;
                }
                VH->nodes[*trav].data = VH->nodes[B].data;
                B = VH->nodes[B].link;
            }
            trav = &VH->nodes[B].link;
        }
    }

    if(A == -1 && B != -1) {
        A = B;
    }

    while(A != -1) {
        *trav = VH->avail;
        if(*trav != -1) {
            VH->avail = VH->nodes[*trav].link;
            VH->nodes[*trav].data = VH->nodes[A].data;
            trav = &VH->nodes[*trav].link;
            A = VH->nodes[A].link;
        }
    }

    *trav = -1;
    return C;
}

Set Intersection(VirtualSpace *VH, Set A, Set B) {
    Set C, *travA, travB;
    C = -1;
    travA = &C;

    for(; A != -1; A = VH->nodes[A].link) {
        for(travB = B; travB != -1 && VH->nodes[A].data > VH->nodes[travB].data; travB = VH->nodes[travB].link) {}
        if(travB != -1 && VH->nodes[A].data == VH->nodes[travB].data) {
            *travA = VH->avail;
            if(*travA != -1) {
                VH->avail = VH->nodes[*travA].link;
                VH->nodes[*travA].data = VH->nodes[A].data;
                travA = &VH->nodes[*travA].link;
            }
        }
    }

    *travA = -1;
    return C;
}
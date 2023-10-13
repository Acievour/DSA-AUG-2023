#include <stdio.h>

#define MAX 10

typedef char Set;

Set Union(Set A, Set B) {
    return A | B;
}

Set Intersection(Set A, Set B) {
    return A & B;
}

Set Difference(Set A, Set B) {
    return A &~ B;
}

void insert(Set *S, int elem) {
    if(elem <= (sizeof(*S)*8)) {
        *S = *S | (1 << elem);
    }
}

void delete(Set *S, int elem) {
    if(i <= (sizeof(*S)*8)) {
        *S = (*S) &~ (1 << elem);
    }
}

Set *setToBitVector(CompWord val) {
    Set *S;
    int bit, i;
    unsigned int max;
    bit = (sizeof(val) << 3) - 1;
    S = NULL;
    S = (Set*)malloc(sizeof(Set));
    if(S != NULL) {
        max = 1 << bit;
        for(i = MAX - 1; i >= 0; i--, max >>= 1) {
            (*S)[i] = (val & max) ? 1 : 0;
        }
    }
    return S;
}

int numOfBit(CompWord val) {
    int sum, bit;
    unsigned int max;
    bit = (sizeof(val) << 3) - 1;
    for(sum = 0; max = 1 << bit; max > 0; max >>= 1) {
        sum += (val & max) ? 1 : 0;
    }
    return sum;
}
#include <stdio.h>

typedef struct {
    char FN[24]; // first name
    char MI;     // middle initial
    char LN[16]; // last name
} nametype;

typedef struct {
    nametype name;
    int ID;
    char course[8]; // BSCS, BSIS, BSIT
    int yrLevel;
} studtype;

void displayHeader();
void displayStudent(studtype S);
void readFile();

void main() {

    displayHeader();

    return 0;
}

void displayHeader() {
    printf("\n\n");
    printf("%-10s", "ID No.");
    printf("%-16s", "LastName");
    printf("%-24s", "FirstName");
    printf("%-3s", "MI");
    printf("%-8s", "Course");
    printf("%5s", "Year");
    printf("\n");
    printf("%-10s", "======");
    printf("%-16s", "========");
    printf("%-24s", "=========");
    printf("%-3s", "==");
    printf("%-8s", "======");
    printf("%5s", "====");
}
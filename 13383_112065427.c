#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Global Memory Placeholder */
#define SIZE 10
int * tables[SIZE];
int * temp[SIZE];

/* Strategy: Each tables has a header serves as member ctr */
void task_clear();
void task_print();
void task_sLeft();
void task_sRight();

void task_swap(int a, int b);
void aux_malloc(int target, int len);
void task_place(int target, int len);
void task_all(int card, int len);


int main(void) {
    // 1. Clear All
    task_clear();

    // 2. Parsing user input
    char task[15];
    while(scanf("%s", task) != EOF) {

        if (!strcmp(task, "exit")) return(0); //Break from main
        else if (!strcmp(task, "clear"))
            task_clear();
        else if(!strcmp(task, "print"))
            task_print();
        else if (!strcmp(task, "shiftleft")) task_sLeft();
        else if (!strcmp(task, "shiftright"))task_sRight();

        else if (!strcmp(task, "all")) {
            task_clear();
            int card, len;
            scanf(" %d %d", &card, &len);
            task_all(card, len);
        }

        else if (!strcmp(task, "place")) {
            int target, len;
            scanf(" %d %d", &target, &len);
            task_place(target, len);
        }

        else if (!strcmp(task, "swap")) {
            int a, b;
            scanf(" %d %d", &a, &b);
            task_swap(a, b);
        }
    }

    return 0;
}

// ==> Global Func No Argument

void task_clear() {
    for(int i = 0; i < SIZE; i++) {
        free(tables[i]);
        tables[i] = NULL; //Neutralize
    }
}

void task_print() {
    for(int i = 0; i < SIZE; i++) {
        if (tables[i] == NULL) printf("No Card\n");
        else {
            printf("%d:", i);
            int mem = tables[i][0];
            for (int j = 1; j <= mem; j++)
                printf(" %d", tables[i][j]);
            printf("\n");
        }
    }
}

void task_sLeft() {
    //Copy Original Tables
    for(int i = 0; i < SIZE; i++) temp[i] = tables[i];
    //Overwrite by shift left(+1) 9<-0 0<-1
    for(int i = 0; i < 9; i++) tables[i] = temp[i+1];
    //Append
    tables[9] = temp[0];
}

void task_sRight() {
    //Copy Original Tables
    for(int i = 0; i < SIZE; i++) temp[i] = tables[i];
    //Overwrite by shift right(-1)  0->1
    for(int i = 1; i < 10; i++) tables[i] = temp[i-1];
    //Append
    tables[0] = temp[9];
}

//==> Specific Func with Arguments

void task_swap(int a, int b) { //Parse int from User
    int * temp = tables[a];
    tables[a] = tables[b];
    tables[b] = temp;
}

void aux_malloc(int target, int len) { //Construct the memory
    if (tables[target] != NULL) free(tables[target]); //Release First
    tables[target] = (int *) malloc( (len+1) * sizeof(int));
    tables[target][0] = len;
}

void task_place(int target, int len) {
    //Reserve Space First
    aux_malloc(target, len);
    //Parse the user input seq
    for(int i = 1; i <= len; i++) { //Start from 1, 0 is mem ctr
        scanf(" %d", &tables[target][i]);
    }
}

void task_all(int card, int len) {
    //Populate for all tables
    for(int i = 0; i < SIZE; i++) {
        //Reserve Space First
        aux_malloc(i, len);
        //Inject
        for(int j = 1; j <= len; j++) tables[i][j] = card;
    }
}




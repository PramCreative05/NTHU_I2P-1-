#include <stdio.h>
#include <string.h>
#include <stdlib.h> //This is for null

/* Provide the global memory address placeholder */
#define SIZE 10
int * tables[SIZE]; // Array of the address of each memory allocation

/* Release all the memory allocation across tables */
void task_clear(){
    for(int i = 0; i < SIZE; i++){
        free(tables[i]);
        tables[i] = NULL;
    }
}

/* Print all cards in each tables */
void task_print(){
    for(int i = 0; i < SIZE; i++){
        if(tables[i]==NULL){
            printf("%d: No card\n", i);
        }
        else{

            printf("%d:", i);
            int member = tables[i][0];
            for(int j = 1; j <= member; j++)
                printf(" %d", tables[i][j]);
            printf("\n");
        }
    }
}

// ==> All functions below need argument:

/* swap the table placement takes int as the indicator */
void task_swap(int a, int b){
    int * temp =  tables[a];
    tables[a] = tables[b];
    tables[b] = temp;
}

/* Reset memory and recreate */
void aux_malloc(int target, int len){
    if(tables[target] != NULL) free(tables[target]); //If it is preoccupied; Release and recreate
    //Reserve additional 1 place for len storage, so can be retrieved when printing
    tables[target] = (int *) malloc ((len + 1) * sizeof(int));
    tables[target][0] = len;
}

/* Populate a table with given set of seq */
void task_place(int target, int len){
    aux_malloc(target, len);
    for(int i = 1; i <= len; i++)
        scanf(" %d", &tables[target][i]);
}

/* Populate all table with same member with given len */
void task_all(int card, int len){
    for(int i = 0; i < SIZE; i++){
        aux_malloc(i, len);
        for(int j = 1; j <= len; j++)
            tables[i][j] = card;
    }
}

/* Driver function, get user input, parse and compare, call */
int main(void){
    char task[10]; //Holder for the user input

    //Remember %s only scan until white space
    while(scanf("%s", task) != EOF){
        //strcmp return 0 if equal
        // Case 1: exit
        if(!strcmp(task, "exit"))
            return(0);

        // Case 2: clear
        else if(!strcmp(task, "clear"))
            task_clear();

        // Case 3: print
        else if(!strcmp(task, "print"))
            task_print();

        // Case with argument
        // Case 4: all
        else if(!strcmp(task, "all")){
            int card, len;
            scanf(" %d %d", &card, &len);
            task_all(card, len);
        }

        // Case 5: place
        else if(!strcmp(task, "place")){
            int target, len;
            scanf(" %d %d", &target, &len);
            task_place(target, len);
        }

        // Case 6: swap
        else if(!strcmp(task, "swap")){
            int a, b;
            scanf(" %d %d", &a, &b);
            task_swap(a, b);
        }
    }
    return(0);
}


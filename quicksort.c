#include <stdio.h>

void swap(int *, int *);
int hoare_split(int *, int, int);
void quicksort(int *, int, int);


int main(void){
    int size;
    scanf("%d", &size);

    int array[size];

    for(int i = 0; i < size; i++){
        scanf("%d", &array[i]);
    }

    quicksort(array, 0, size-1);

    for(int i = 0; i < size; i++)
        printf("%d", array[i]);
    printf("\n");
    return(0);
}

void swap(int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


int hoare_split(int * a, int low, int high){
    int e = a[low];
    int i = low - 1, j = high + 1;

    for(;;){
        do{
            i++;
        }while(a[i] < e); //Put lesser on the left

        do{
            j--;
        }while(a[j] > e); //Put greater on the right

        if(i >= j) return j; //Exit condition

        swap(&a[i], &a[j]);
    }
}

void quicksort(int * a, int low, int high){
    if(low == high) return; //Termination
    int middle;
    middle = hoare_split(a, low, high);
    quicksort(a,low, middle);
    quicksort(a,middle+1,high);
}


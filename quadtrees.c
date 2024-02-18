#include <stdio.h>
#include <math.h>

//init = ctr, matrix, found

//get size
//subTitan
//diverged
//main

int found[10000];
int ctr = 0;
int matrix[128][128] = {0};

int getSize(int bigger){
    int p = 0;
    while(pow(2, p) < bigger) p++;
    return pow(2, p);
}

int subTitan(int size, int row, int col){
    for(int i = row; i < row+size; i++){
        for(int j = col; j < col+size; j++){
            if(matrix[i][j] != 1) return 0;
        }
    }
    return 1;
}

void diverged(int size, int row, int col, int address){
    int status = subTitan(size, row, col);

    if(status){
        found[ctr] = address;
        ctr++;
    }
    else{ //Divide if not valid
        if(size != 1){ //As long as not the smallest block
            int border = size / 2;
            diverged(border, row, col, address*10);
            diverged(border, row, col+border, address*10+1);
            diverged(border, row+border, col, address*10+2);
            diverged(border, row+border, col+border, address*10+3);
        }
    }
    return;
}

int main(void){
    int rows, cols;
    scanf("%d %d", &rows, &cols);

    int start = (rows >= cols) ? getSize(rows) : getSize(cols);

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            scanf(" %d", &matrix[i][j]);
        }
    }

    diverged(start, 0,0,1);
    printf("%d\n", ctr);
    for(int i = 0; i < ctr; i++) printf("%d\n", found[i]);
    return 0;
}

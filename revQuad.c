#include <stdio.h>

//init =  matrix

//populate(5: check the code, row, col, size, index)
//main

int matrix[128][128] = {0};

void populate(char code[10], int size, int row, int col, int index){
    if(code[index] == '\0'){
        for(int i = row; i < row + size; i++){
            for(int j = col; j < col + size; j++){
                matrix[i][j] = 1;
            }
        }
        return;
    }

    int border = size/2;
    if(code[index] == '0') populate(code, border, row, col, index+1);
    if(code[index] == '1') populate(code, border, row, col+border, index+1);
    if(code[index] == '2') populate(code, border, row+border, col, index+1);
    if(code[index] == '3') populate(code, border, row+border, col+border, index+1);
}

int main(void){
    char address[10000][10];
    int rows, cols;

    int iter;
    scanf("%d", &iter);
    for(int i = 0; i < iter; i++) scanf("%s", &address[i]);
    scanf("%d %d", &rows, &cols);

    int size = 1;
    while(size < rows || size < cols) size*=2;

    for(int i = 0; i < iter; i++) populate(address[i], size, 0, 0, 1);

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(j != cols-1) printf("%d ", matrix[i][j]);
            else printf("%d", matrix[i][j]);
        }
        if(i != rows-1) printf("\n");
    }
}

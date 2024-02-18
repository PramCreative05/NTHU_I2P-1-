/*
11
112
113
1211
1212
1213
123
130
131
1320
1321
1322
8 8

1
1
4 4
*/

#include <stdio.h>

int matrix[129][129];

void populate(char code[10], int row, int col, int size, int index){
    if(code[index] == '\0'){ //Reach the sub-coordinate
        for(int i = row; i < row + size; i++){
            for(int j = col; j < col + size; j++){
                matrix[i][j] = 1;
            }
        }
        return;
    }

    int border = size/2;
    if(code[index]=='0') populate(code, row,        col,        border, index+1);//Up Left
    if(code[index]=='1') populate(code, row,        col+border, border, index+1);//Up Right
    if(code[index]=='2') populate(code, row+border, col,        border, index+1);//Btm Left
    if(code[index]=='3') populate(code, row+border, col+border, border, index+1);//Btm Right
}

int main(void){
    int rows, cols, iter;
    char address[100000][10];

    scanf("%d", &iter);
    for(int i = 0; i < iter; i++) scanf("%s", &address[i]);

    scanf("%d %d", &rows, &cols);
    int size = 1;
    while(size < rows || size < cols) size*=2; //Power to 2

    //Initialized
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            matrix[i][j] = 0;
        }
    }

    for(int i = 0; i < iter; i++) populate(address[i], 0, 0, size, 1); //Ignore the header

    //Print final result
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(j != cols - 1) printf("%d ", matrix[i][j]);
            else printf("%d", matrix[i][j]);
        }
        if(i != rows-1) printf("\n");
    }

    return 0;
}

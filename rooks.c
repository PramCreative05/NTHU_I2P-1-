#include <stdio.h>
#include <string.h>
/*
1. Global
2. Debug
3. isSafe
4. track: driver
5. main
*/

#define N 10

int board[N][N];
int n, m, size, sol;

void printBoard(){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
}

int safe(int row, int col, int mode){
    int i, j;

    //1. left: col wise
    for(int i = 0; i < size; i++)
        if(board[row][i]) return 0;

    //2. down: row wise
    for(int i = 0; i < size; i++)
        if(board[i][col]) return 0;

    //3. Upper left --
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--){
        if(board[i][j]){
            if(board[i][j] == -1 && mode == 1){
                continue;
            }else{
                return 0;
            }
        }
    }

    //4. lower left +-
    for(int i = row, j = col; i < size && j >= 0; i++, j--){
        if(board[i][j]){
            if(board[i][j] == -1 && mode == 1){
                continue;
            }else{
                return 0;
            }
        }
    }

    return 1;
}

void track(int col, int numQ, int numR){
    //1. Basic
    if(col == size){
        sol++;
        return;
    }

    //2. Row iter
    for(int i = 0; i < size; i++){
        if(numQ < n){
            if(safe(i, col, 0)){
                board[i][col] = 1;
                track(col+1, numQ+1, numR);
                board[i][col] = 0;
            }
        }
        if(numR < m){
            if(safe(i, col, 1)){
                board[i][col] = -1;
                track(col+1, numQ, numR+1);
                board[i][col] = 0;
            }
        }
    }
}

int main(void){
    while(scanf("%d %d", &n, &m) != EOF){
        size = n + m;
        memset(board, 0, sizeof(board));
        track(0,0,0);
        printf("%d", sol);
        sol = 0;
    }
    return 0;
}

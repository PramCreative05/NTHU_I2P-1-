#include <stdio.h>

int isSafe(int row, int col, int N, int board[N][N]){
    int i, j;
    //1. Check row left
    for(i = 0; i < col; i++){
        if(board[i][row]){
            if(board[i][row] == -1){
                continue;
            }else{
                return 0;
            }
        }
    }

    //2. Check upper left
    for(i = row, j = col; i >= 0 && j >= 0; i--, j--){
        if(board[i][j]){
            if(board[i][j] == -1){
                continue;
            }else{
                return 0;
            }
        }
    }

    //3. Check lower left
    for(i = row, j = col; i < N && j >= 0; i++, j--){
        if(board[i][j]){
            if(board[i][j] == -1){
                continue;
            }else{
                return 0;
            }
        }
    }
}

int trackQueen(int col, int N, int board[N][N]){
    if(col>=N)
        return 1;

    int result = 0;

    for(int i = 0; i < N; i++){
        if(isSafe(i, col, N, board) && board[i][col] != -1){
            board[i][col] = 1;
            result += trackQueen(col + 1, N, board);
            board[i][col] = 0;
        }
    }

    return result;
}

int main(void){
    int N;
    scanf("%d", &N);

    int board[N][N];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int exc = 0;
            scanf("%1d", exc);
            if(exc == 1){
                board[i][j] == -1;
            }else{
                board[i][j] == exc;
            }
        }
    }

    int sol = trackQueen(0, N, board);
    printf("%d\n", sol);
    return 0;
}



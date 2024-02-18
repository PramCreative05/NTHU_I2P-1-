#include <stdio.h>
#include <string.h>
#define N 10

int n, m, size, sol;
int board[N][N]; // chessboard

void printBoard() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/* Checking the left, upper left, lower left diagonal for queens */
int isSafe(int row, int col, int mode) {
//    printf("Now Checking: %d %d\n", row, col);
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return 0;

    // Check the down for static row
    for (i = 0; i < row; i++)
        if (board[i][col])
            return 0;

    // 2. Check upper left diagonal
    for(i = row, j = col; i >= 0 && j >= 0; i--, j--){
        if(board[i][j]){
            if(board[i][j] == -1 && mode == 1){
                continue;
            }else{
                return 0;
            }
        }
    }

    // 3. Check lower left diagonal
    for(i = row, j = col; i < size && j >= 0; i++, j--){
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




/* this function checks position for each col */
void trackQueen(int col, int numQ, int numR) {
    // Exit gate if the col iteration exceeds
    if (col == size){
//        printf("+1 Reached! \n \n");
        sol++;
        return;
    }

    for (int i = 0; i < size; i++) {
        if(numQ < n){
            if (isSafe(i, col, 0)) {
                // Place the queen if it is safe and not preoccupied
                board[i][col] = 1;
//                printf("Current: \n");
//                printBoard();

                // Recursive moment, entering a new column, check all, if failed return 0
                trackQueen(col + 1, numQ + 1, numR);

                // Backtracking undo the queen
                board[i][col] = 0;
//                printf("Back: \n");
//                printBoard();
            }

        }

        if(numR < m){
            if (isSafe(i, col, 1)){
                // Place the rooks if it is safe and not preoccupied
                board[i][col] = -1;
//                printf("CurrentR: \n");
//                printBoard();

                // Recursive moment, entering a new column, check all, if failed return 0
                trackQueen(col + 1, numQ, numR+1);

                // Backtracking undo the rooks
                board[i][col] = 0;
//                printf("BackR: \n");
//                printBoard();
            }
        }
    }


}

int main(void) {
    while(scanf("%d %d", &n, &m) != EOF){
        size = n + m;
        memset(board, 0, sizeof(board));

        trackQueen(0, 0, 0);

        printf("%d\n", sol);
        sol = 0;
    }


    return 0;
}

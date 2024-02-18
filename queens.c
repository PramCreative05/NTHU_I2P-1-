#include <stdio.h>

#define N 4

int board[N][N];

void printBoard(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j< N; j++){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void printLoc(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j< N; j++){
            if(board[i][j] == 1)
                printf("%d", j);
        } // Print the location (col) of queens in each row
    }
    printf("\n");
}

int isSafe(int row, int col){
    int i, j;

    //1. Check left
    for(i = 0; i < col; i++){
        if(board[row][i])
            return 0;
    }

    //2. Check upper+left
    for(i = row, j = col; i >= 0 && j >= 0; i--, j--){
        if(board[i][j])
            return 0;
    }

    //3. Check lower-left
    for(i = row, j = col; i < N && j >= 0; i++, j--){
        if(board[i][j])
            return 0;
    }

    //If all true
    return 1;
}

int trackQueen(int col){
    //1. Exit Gate for finishing all columns
    if(col>=N)
        return 1;

    int result = 0;
    //2. Iterate through all row
    for(int i = 0; i < N; i++){
        //2.a Check if the place is safe from previous (left)queen
        if(isSafe(i, col)){
            //if safe, place the queen
            board[i][col] = 1;

            printf("Col:%d i:%d | Current:\n", col, i);
            printBoard();

            //If you reach this stage, means it already put the queen
            //Proceed to next col
            result = trackQueen(col + 1);

            if(result == 1)
                return 1;

            //if not returning to 0; then it couldn't find safe place
            //Undo the decision and back tracking
            board[i][col] = 0;
            printf("Col:%d i:%d | Backtracking:\n", col, i);
            printBoard();
        }
    }

    return result;
    //Exit Gate if result is not updated for all row exhausted
}

int main(void){
    if(trackQueen(0) == 0)
        printf("Solution not found\n");
    printLoc();
    return 0;
}

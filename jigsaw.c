#include <stdio.h>

/*
1. Global
2. compare
3. jogsaw
4. main

*/
#define SIZE 3
char A[SIZE][SIZE];
char B[SIZE][SIZE];

int max, sol;

int vs(){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(A[i][j] != B[i][j]) return 0;
        }
    }
    return 1;
}

void jig(int row, int col, int move){
    //1. Limit
    if(move > max) return;

    //2. compare
    if(vs()){
        sol++;
        return;
    }

    //3. div4

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for(int i = 0; i < 4; i++){
        int X = row + dx[i];
        int Y = col + dy[i];

        if(X >= 0 && X < SIZE && Y >= 0 && Y < SIZE){
            char temp = A[row][col];

            A[row][col] = A[X][Y];
            A[X][Y] = temp;

            jig(X, Y, move+1);

            A[X][Y] = A[row][col];
            A[row][col] = temp;
        }
    }
}

int main(void){
    int task;
    scanf("%d", &task);

    while(task--){
        int row, col;

        sol = 0;
        scanf("%d", &max);

        for(int i = 0; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++){
                scanf(" %c", &A[i][j]);
                if(A[i][j] == 'x'){
                    row = i;
                    col = j;
                }
            }
        }

        for(int i = 0; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++){
                scanf(" %c", &B[i][j]);
            }
        }

        jig(row, col, 0);

        sol ? printf("Yes\n") : printf("No\n");
    }

    return 0;
}

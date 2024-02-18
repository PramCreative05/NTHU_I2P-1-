#include <stdio.h>
#include <string.h>

#define SIZE 3

char A[SIZE][SIZE];
char B[SIZE][SIZE];
int maxMoves, sol;

int compare(){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(A[i][j] != B[i][j])
                return 0;
        }
    }
    return 1;
}

void jigsaw(int row, int col, int moves){
    /* Handler 1: Check moves within limit */
    if(moves > maxMoves)
        return;

    /* Handler 2: Compare target vs current */
    if(compare()){
        sol++;
        return;
    }

    /* Computation: Iterate through all 4 possible Moves recursively */
    //Left, Right, Up, Down
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for(int i = 0; i < 4; i++){
        int X = row + dx[i];
        int Y = col + dy[i];

        //Check legal
        if(X >= 0 && X <= SIZE && Y >= 0 && Y < SIZE){
            //Preserve original
            char temp = A[row][col];

            //Swap
            A[row][col] = A[X][Y];
            A[X][Y] = temp; //to produce new variants based on the iterations

            //Inject to the recursive
            jigsaw(X, Y, moves+1);

            //UnSwap if solution illegal
            A[X][Y] = A[row][col];
            A[row][col] = temp;
        }
    }
}

int main(){
    int task;
    scanf("%d", &task);

    while(task--){
        int row, col;

        //re-initiate global var
        sol = 0;
        scanf("%d", &maxMoves);

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

        jigsaw(row, col, 0);

        if(sol){
            //printf("Possible solution is %d\n", sol);
            printf("Yes\n");
        }else{
            printf("No\n");
        }

    }
}

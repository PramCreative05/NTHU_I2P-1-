/*
10 11
....###
....#.#
..###.#
..#....
#####..
..#.#..
..###..
*/

#include <stdio.h>

//Original idea by: Lindsey
char rotate(long long N) {
    int msb = 0; //Most Significant Bit
    while (1LL << (msb + 1) <= N) {
        msb++;
    }

    char direction = 'u';

    N = N ^ (N >> 1); // Grey Encoding
    while (msb >= 0) {
        if (N & (1LL << msb)) {
            switch (direction) {
                case 'u': direction = 'r';
                    break;
                case 'r': direction = 'd';
                    break;
                case 'd': direction = 'l';
                    break;
                case 'l': direction = 'u';
                    break;
            }
        }
        msb--;
    }

    return direction;
}

int main(void) {
    long long N;
    int len;

    scanf("%d %lld", &len, &N);
    N--;

    char mem[len];

    char direction = rotate(N);
    //printf("direction %c\n", direction);

    for (int i = 0; i < len; i++){
        mem[i] = rotate(N+i);
        //printf("%c",rotateFunc(n+i));
    }

    int minX=0, minY=0, maxX=0, maxY=0, currX=0, currY=0;

    for (int i = 0; i < len; i++){
        switch(mem[i]){
            case 'u':
                currY+=2;
                break;
            case 'd':
                currY-=2;
                break;
            case 'l':
                currX-=2;
                break;
            case 'r':
                currX+=2;
                break;
        }

        if (currY > maxY)
            maxY = currY;
        if (currY < minY)
            minY = currY;
        if (currX > maxX)
            maxX = currX;
        if (currX < minX)
            minX = currX;
    }
    //printf("%d %d", maxX-minX+1, maxY-minY+1);

    int boardRow = maxY-minY+1;
    int boardCol = maxX-minX+1;

    char board[boardRow][boardCol];
    for (int i=0; i < boardRow; i++){
        for (int j = 0; j < boardCol; j++){
            board[i][j]='.';
        }
    }

    int col = -minX;
    int row = maxY;
    //printf("\n%d %d\n", row, col);

    //Filling the Array
    for (int i = 0; i < len; i++){
        board[row][col]='#';
        switch(mem[i]){
            case 'u':
                board[row-1][col]='#';
                board[row-2][col]='#';
                row-=2;
                break;
            case 'd':
                board[row+1][col]='#';
                board[row+2][col]='#';
                row+=2;
                break;
            case 'l':
                board[row][col-1]='#';
                board[row][col-2]='#';
                col-=2;
                break;
            case 'r':
                board[row][col+1]='#';
                board[row][col+2]='#';
                col+=2;
                break;
        }
    }

    //Print Result
    for (int i = 0; i < boardRow; i++){
        for (int j = 0; j < boardCol; j++){
            printf("%c", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}

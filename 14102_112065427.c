#include <stdio.h>

int main(void){
    //Please check the max value of the calculation
    //Check data type with printf and scanf compability
    int n,m,k;
    scanf("%d %d %d", &n, &m, &k);

    long int res[n][m][k];
    long int maze[n][m][k];

    for(int x = 0; x < n; x++){
        for(int y = 0; y < m; y++){
            for(int z = 0; z < k; z++){
                scanf(" %ld", &maze[x][y][z]);
                if(maze[x][y][z] == -1) res[x][y][z] = -1;
                else res[x][y][z] = 1000000;
            }
        }
    }

    for(int x = 0; x < n; x++){
        for(int y = 0; y < m; y++){
            for(int z = 0; z < k; z++){
                //Handle 1: res appear -1
                if(res[x][y][z] == -1) continue;

                //Handle 2: starting position
                if(x == 0 && y == 0 && z == 0) res[x][y][z] = maze[x][y][z];

                //Main Logic:

                //Compare Left
                if(x > 0 && res[x][y][z] > (maze[x][y][z] + res[x-1][y][z]) && res[x-1][y][z] != -1)
                    res[x][y][z] = maze[x][y][z] + res[x-1][y][z];

                //Compare Down
                if(y > 0 && res[x][y][z] > (maze[x][y][z] + res[x][y-1][z]) && res[x][y-1][z] != -1)
                    res[x][y][z] = maze[x][y][z] + res[x][y-1][z];

                //Compare Below
                if(z > 0 && res[x][y][z] > (maze[x][y][z] + res[x][y][z-1]) && res[x][y][z-1] != -1)
                    res[x][y][z] = maze[x][y][z] + res[x][y][z-1] ;
            }
        }
    }

    printf("%ld\n", res[n-1][m-1][k-1]);

    return(0);
}

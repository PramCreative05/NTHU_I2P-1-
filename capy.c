#include <stdio.h>

int ans = 0;
char maze[500][500];

void step(int x, int y, int counter){
    if(maze[x][y] == '#')
        return;
    if(maze[x][y] == 'M')
        ans += counter;

    maze[x][y] = '#';
    step(x + 1, y, counter+1);
    step(x - 1, y, counter+1);
    step(x, y + 1, counter+1);
    step(x, y - 1, counter+1);
    maze[x][y] = '.';
}

int main(void){
    int h, w;
    int x, y;
    scanf("%d %d", &h, &w);

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            scanf(" %c", &maze[i][j]);
            if(maze[i][j] == 'S'){
                x = i;
                y = j;
            }
        }
    }

    step(x, y, 0);
    printf("%d\n", ans*2);

    return 0;
}

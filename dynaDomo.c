/*
4 3
000
000
000
000

25

4 3
000
000
001
000

12

*/

#include <stdio.h>

int main(void){
    int h, w;
    scanf("%d %d", &h, &w);

    int arr[h][w];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            scanf("%1d", &arr[i][j]);
        }
    }

    long long int ways[h][w];

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(j == 0 && i == 0) ways[i][j] = 1;
            else if(j == 0 && arr[i][0]) ways[i][j] = ways[i-1][0]; //atas
            else if(i == 0 && arr[0][j]) ways[i][j] = ways[0][j-1]; //kiri
            else if(arr[i][j] == 0){
                ways[i][j] = 0;
                if(arr[i-1][j-1] == 0) ways[i][j] += ways[i-1][j-1];
                if(arr[i][j-1] == 0) ways[i][j] += ways[i][j-1];
                if(arr[i-1][j] == 0) ways[i][j] += ways[i-1][j];
            }
            else ways[i][j] = 0;
        }
    }

    printf("%lld", ways[h-1][w-1]);
    return;
}

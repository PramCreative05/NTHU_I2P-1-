/*
5
3
1 2 3 4 5
2 3 4 5 6
3 4 5 6 7
4 5 6 7 8
5 6 7 8 9

    5    6    7
    6    7    8
    7    8    9
*/

#include <stdio.h>
int size_i, size_k;
int findMax(int i, int j, int img[size_i][size_i], int size_i, int size_k);

int main(void){

    scanf("%d", &size_i);
    scanf("%d", &size_k);

    int img[size_i][size_i];
    for(int i = 0; i<size_i; i++){
        for(int j = 0; j<size_i; j++){
            scanf("%d", &img[i][j]);
        }
    }

    int max[size_i - (size_k - 1)][size_i - (size_k - 1)];
    for(int i = 0; i < (size_i - (size_k - 1)); i++){
        for(int j = 0; j < (size_i - (size_k - 1)); j++){
            max[i][j] = findMax(i, j, img, size_i, size_k);
        }
    }

    for(int i = 0; i<size_k; i++){
        for(int j = 0; j<size_k; j++){
            printf("%4d ", max[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int findMax(int i, int j, int img[size_i][size_i], int size_i, int size_k){
    int max = 0;

    printf("starting: %d %d\n", i, j);

    for(int y = 0; y<size_k; y++){
        for(int x = 0; x<size_k; x++){
            if(img[i+y][j+x] > max){
                max = img[i+y][j+x];
            }
            printf("|val:%d max: %d coor:%d,%d| ", img[i+y][j+x], max, i+y, j+x);
        }
        printf("finishing: %d \n", y);
    }

    return max;
}

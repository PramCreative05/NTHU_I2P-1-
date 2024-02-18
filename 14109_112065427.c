/*
11
7
1
1
5
7
6
6
5
1
5
5

result: 1
Frequency counting and select the odd number
*/

#include <stdio.h>

int main(void){
    int iter;
    scanf("%d", &iter);
    int result = 0;

    for(int i = 0; i < iter; i++){
        int number;
        scanf("%d", &number);
        result ^= number;
    }

    printf("%d\n", result);
    return(0);
}

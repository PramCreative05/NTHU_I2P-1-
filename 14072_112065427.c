#include <stdio.h>

double eval(double a, double b, int sign){
    switch(sign){
        case 0: return a + b;
        case 1: return a - b;
        case 2: return a * b;
        case 3: if (b != 0) return (a / b);
    }
}

int select(int arr[4]){
    for(int a = 0; a < 4; a++){
        for(int b = 0; b < 4; b++){
            if(a == b) continue;
            for(int c = 0; c < 4; c++){
                if(a == c || b == c) continue;
                for(int d = 0; d < 4; d++){
                    if(a == d || b == d || c == d) continue;

                    for(int i = 0; i < 4; i++){
                        for(int j = 0; j < 4; j++){
                            for(int k = 0; k < 4; k++){
                                double sum;

                                sum = eval(eval(eval(arr[a], arr[b], i), arr[c], j), arr[d], k);
                                if(sum == 24) return 1;

                                sum = eval(eval(arr[a], eval(arr[b], arr[c], j), i), arr[d], k);
                                if(sum == 24) return 1;

                                sum = eval(eval(arr[a], arr[b], i), eval(arr[c], arr[d], k), j);
                                if(sum == 24) return 1;

                                sum = eval(arr[a], eval(eval(arr[b], arr[c], j), arr[d], k) , i);
                                if(sum == 24) return 1;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int main(void){
    int iter;
    scanf("%d", &iter);

    int arr[4];
    for(int i = 0; i < iter; i++){
        for(int j = 0; j < 4; j++){
            scanf(" %d", &arr[j]);
        }
        select(arr) == 1 ? printf("Safe\n") : printf("Disqualified\n");
    }
    return 0;
}


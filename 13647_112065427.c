#include <stdio.h>

int g0 = 0;
int g1 = 0;

int revFib(int n);

int main(void){
    int n = 0;
    scanf("%d %d %d", &g0, &g1, &n) != EOF;
    printf("%d\n", revFib(n));
    return 0;
}

int revFib(int n){
    if(n == 0){
        return g0;
    }else if (n == 1){
        return g1;
    }else{
        return revFib(n-2) - revFib(n-1);
    }
}


#include <stdio.h>

double power(double n, int p){
    if(p == 0)
        return 1;

    if(p % 2 == 0){
        double halfPower = power(n , p/2);
        return halfPower * halfPower;
    }else{
        return n * power(n, p-1);
    }
}

int main(void){
    printf("power of 10 over 2 = %lf\n", power(2, 10));
    return 0;
}

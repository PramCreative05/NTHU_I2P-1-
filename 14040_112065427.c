#include <stdio.h>
int gcd( int x, int y);

int main(void){
    int x, y;
    scanf("%d %d", &x, &y);

    printf("%d\n", gcd(x, y));
    return 0;
}
int gcd( int x, int y){
    if(y % x == 0 ) return x;
    if( y > x){
        return gcd(x, y%x);
    }else{
        return gcd(y, x%y);
    }
}

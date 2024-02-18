#include <stdio.h>

void toBin(int dec){
    if(dec>1){
        toBin(dec/2);
    }
    printf("%d", dec % 2);
}

int main(void){
    int dec;
    scanf("%d", &dec);
    toBin(dec);
    return 0;
}

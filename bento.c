#include <stdio.h>
#include <string.h>

int main(void){
    char set[21];
    scanf(" %s", set);

    int len = strlen(set);
    int lim = 1 << len; // 2^N

    // 1. Generate Mask
    int mask[lim];
    int cnt = 0;

    //Outer pattern row
    for(int i = 0; i < lim; i++){
        //Inner pattern col
        for(int j = 0x1; j <= 0x8; j*= 0x2){
            mask[cnt++] = j << (sizeof(int) * i); //Shift col pattern based on row
            if(cnt >= lim) break; //Handler
        }
        if(cnt >= lim) break; //Handler
    }

    // 2. Generate all subset
    for(int i = 0; i < lim; i++){
        for(int j = 0; j < len; j++){
            if((mask[j] & i) != 0) printf("%c", set[j]); //print correspondent
        }
        if(i > 0) printf("\n");
    }

    return 0;
}

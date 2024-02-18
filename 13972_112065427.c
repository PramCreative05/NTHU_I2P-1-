/*
      /\
     /  \
    /-  -\
   /      \
  /-      -\
 /          \
/------------\
     |  |
     |__|
*/


#include <stdio.h>

int main(void){
    int i, j, x = 0;

    //Input Tree Parameter
    int height = 55; //better height = (9n+3)) //

    //Input const
    double ratio = 2.0/7.0; // tH/cH

    //Tree Baseline
    int cHeight = height/(1.0+ratio);
    int wide = cHeight*2;
    int tHeight = height - cHeight;
    int core = (wide-2)/2;

//    //Parameter Debugger
//    printf("*cHeight:%d\n*tHeight:%d\n*wide:%d\n*core:%d\n", cHeight, tHeight,wide,core);
//
//    //j col Debugger
//    printf(" ");
//    for(int z = 0; z<wide;z++){
//        printf("%d", x);
//        x++;
//        if(x == 9){
//            x = 0;
//        }
//    }
//    printf("\n");


    //Print Crown
    for(i=0;i<cHeight;i++){
        for(j=0;j<wide;j++){
            if(j == (core-i)){
                printf("/");
                //odd layer
                if(i%2 == 0 && i !=0){
                    int blank = (i-1)*2;
                    if(i == cHeight-1){
                        //bottom
                        for(int k =0;k<(blank+2);k++){
                            printf("-");
                        }
                    }else{
                        printf("-");
                        for(int k = 0; k<blank;k++){
                            printf(" ");
                        }
                        printf("-");
                    }
                    j = j + (i*2);
                }
            }else{
                if(j == (core+1)+i){
                    printf("\\");
                    break;
                }else{
                    printf(" ");
                }
            }
        }
        printf("\n");
    }

    //print trunk
    for(i=0;i<tHeight;i++){
        for(j=0;j<wide;j++){
            if((j == core - 1) || (j == core + 2)){
                printf("|");
                if(i == tHeight-1 && j == core - 1){
                    printf("__");
                    j = j+2;
                }

            }else{
                if(j > core + 2){
                    break;
                }else{
                    printf(" ");
                }
            }
        }
//        if(i<tHeight-1){
//            printf("\n");
//        }
        printf("\n");
    }
    return 0;
}

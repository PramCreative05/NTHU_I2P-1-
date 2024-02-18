/*
 ^   ^
(=-w-=)
  " "
*/

#include <stdio.h>

int main(void){
    char faces[3][10] = {" ^   ^",
                     "(=-w-=)", "  \" \""};
    int i = 0;
    for(i=0; i<3; i++){
        printf("%s\n", faces[i]);
    }
    return 0;
}

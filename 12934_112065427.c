#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
  char in[100];
  scanf("%s", in);

  char res[100] = "";
  for(int i = strlen(in) - 1; i >= 0; i--){

    switch(in[i]){
      case '0':{
        strcat(res, "0");
        break;
      }
      case '1':{
        strcat(res, "1");
        break;
      }
      case '6':{
        strcat(res, "9");
        break;
      }
      case '8':{
        strcat(res, "8");
        break;
      }
      case '9':{
        strcat(res, "6");
        break;
      }
      default:{
        printf("No\n");
        return 0;
      }
    }

  }

  int flag = 1;
  for(int i = 0; i < strlen(res); i++){
    if(flag == 1 && res[i] == '0'){
      continue;
    }
    else{
      flag = 0;
      printf("%c", res[i]);
    }
  }

  printf("\n");

  return 0;
}

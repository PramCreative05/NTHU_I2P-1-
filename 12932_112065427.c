/*

5 6
\\//\\
/\\\\\
//\\\\
\\\\\/
\\////
6
1
2
3
4
5
6

Position: 4
Stuck QQ
Stuck QQ
Stuck QQ
Right!
Right!
*/

#include <stdio.h>

int main(void) {
  int n, m;    // n row, m col starts 1 ~ size array
  scanf("%d %d", &n, &m);

  char arr[n][m+1];  //terminal value
  for (int i = 0; i < n; i++) {
    scanf("%s", arr[i]);
  }

  /*======DEBUGGER FOR PRINTING INPUT ARRAY========
  for (int i = 0; i < n; i++) {
    int m = 0;
    while(arr[i][m] != '\0') {
      printf("%c", arr[i][m]);
      m++;
    }
    printf("\n");
  }
  =====================^^^^^^^====================*/

  int q = 0;
  scanf(" %d", &q);

  int y = 0;
  for(int i = 0; i < q; i++) {
    scanf("%d", &y);

    int isNotBreak = 1;
    int p = y - 1;
    //for loop row maze
    for (int j = 0; j < n; j++) {
      // printf("[i:%d p:%d New: %c]\n", j, p, arr[j][p]);
      if(arr[j][p] == '\\'){
        // printf("entering this \\ \n");
        if(p == m-1){
          printf("Right!\n");
          isNotBreak = 0;
          break;
        }
        else if(arr[j][p+1] == '\\'){
          // printf("%c%c", arr[j][p], arr[j][p+1]);
          p++;
        }
        else{
          printf("Stuck QQ\n");
          isNotBreak = 0;
          break;
        }
      }
      else if(arr[j][p] == '/')
      {
        // printf("entering this /\n");
        if(p == 0){
          printf("Left!\n");
          isNotBreak = 0;
          break;
        }
        else if(arr[j][p-1] == '/'){
          // printf("%c%c", arr[j][p], arr[j][p-1]);
          p--;
        }
        else{
          printf("Stuck QQ\n");
          isNotBreak = 0;
          break;
        }
      }
    }
    if(isNotBreak){
      if(p>(m-1)){
        printf("Right!\n");
      }else if(p<0){
        printf("Left!\n");
      }else{
        printf("Position: %d\n", p+1);
      }
    }

  }
  return 0;
}

#include <stdio.h>

//N (1 ≤ N ≤ 10^4) and R (2 ≤ R ≤ 10)
int main(void) {
  long long int N = 0;
  int R = 0;

  scanf("%lld %d", &N, &R);

  //storage
  int arr[R][(N/2)+1];
  int row = 0;

  long long int i = 0;
  long long int starter = 1;

  for(int i = 0; i< R; i++){
    arr[i][0] = 0;
  }

  while(i++ < N){
    //Updating head
    if(row == 0 && i > 1){
      // printf("^head^\n");
      starter = starter + (2*(R-1));
      row++;
    }

    //Filling Column
    if(i <= starter + (R-1)){
      arr[row][++arr[row][0]] = i;
      // printf("DOWN: %lld col: %d row： %d\n", starter, arr[row][0], row);
      if(row<(R-1)) row++;
    }

    //Filling Diagonal
    if(i > starter + (R-1) && i <= starter + (2*(R-1))){
      row--;
      arr[row][++arr[row][0]] = i;
      // printf("DIA: %lld col: %d row： %d\n", starter, arr[row][0], row);
    }

    // printf("%lld\n", i);
    // printf("-\n");
  }

  //Printing Result
  for(int i = 0; i < R; i++){
    for(int j = 1; j <= arr[i][0]; j++){
      if(i == 0 && j == 1){
        printf("%d", arr[i][j]);  //Handling Execption
      }else{
        printf(" %d", arr[i][j]);
      }
    }
  }
  printf("\n");

  return 0;
}

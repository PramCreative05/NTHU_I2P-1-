/*
2
5
0 1 4 4 2
1 0 4 3 3
2 2 3 0 2
2 4 1 2 2
1 4 0 1 3
4 3
3 3

  24
  27

1
3
1 2 3
4 5 6
7 8 9
*/

// I NEED DS AND ALGORITHM

#include <stdio.h>

//Global variable

int size = 0;
int check(int X, int Y);

int main(void) {
  int tests = 0;
  scanf("%d", &tests);
  scanf("%d", &size);

  int img[size][size];
  unsigned long long mem[size][size]; //memory for result and center (flag, x, y)
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      scanf("%d", &img[i][j]);
      mem[i][j] = 0;
    }
  }

  //Find all possible row
  unsigned long long int rowEach[size];
  for(int i = 0; i < size; i++) {
    unsigned long long int row = 0;
    for(int j = 0; j < size; j++){
        row += img[i][j];  //moving Y
    }
    rowEach[i] = row;
    // printf("row:%d => sum:%llu \n", i, rowEach[i]);
  }

  //Find all possible column
  unsigned long long int colEach[size];
  for(int i = 0; i < size; i++) {
    unsigned long long int col = 0;
    for(int j = 0; j < size; j++){
      col += img[j][i];  //moving X
    }
    colEach[i] = col;
    // printf("col:%d => sum:%llu \n", i, colEach[i]);
  }

  //Find all possible downhill++  _|
  unsigned long long int downEach[size][size];
  for(int Y = 0, X = 0; Y < size; Y++) {        //for row = 0
    unsigned long long result = 0;
    int i;
    for(i = -size; i < size; i++) {
      if((X+i >= 0 && X+i < size) && (Y+i >= 0 && Y+i < size)) {
        result += img[X+i][Y+i];
      }
      if(X+i == size-1 || Y+i == size-1) break;
    }
    downEach[X+i][Y+i] = result;
    // printf("base coor: %d,%d => sum:%llu \n", X+i, Y+i, result);
  }
  for(int Y = 0, X = 1; X < size; X++) {        //for col = 0 X from 1
    unsigned long long result = 0;
    int i;
    for(i = -size; i < size; i++) {
      if((X+i >= 0 && X+i < size) && (Y+i >= 0 && Y+i < size)) {
        result += img[X+i][Y+i];
      }
      if(X+i == size-1 || Y+i == size-1) break;
    }
    downEach[X+i][Y+i] = result;
    // printf("base coor: %d,%d => sum:%llu \n", X+i, Y+i, result);
  }

  //Find all possible uphill++  |_
  unsigned long long int upEach[size][size];
  for(int Y = 0, X = 0; Y < size; Y++) {        //for row = 0
    unsigned long long result = 0;
    int i;
    for(i = -size; i < size; i++) {
      if((X+i >= 0 && X+i < size) && (Y-i >= 0 && Y-i < size)) {
        result += img[X+i][Y-i];
      }
      if(X+i == size-1 || Y-i == 0) break;
    }
    upEach[X+i][Y-i] = result;
    //printf("base coor: %d,%d => sum:%llu \n", X+i, Y-i, result);
  }
  for(int Y = size-1, X = 1; X < size; X++) {        //for col = size-1 X from 1
    unsigned long long result = 0;
    int i;
    for(i = -size; i < size; i++) {
      if((X+i >= 0 && X+i < size) && (Y-i >= 0 && Y-i < size)) {
        result += img[X+i][Y-i];
      }
      if(X+i == size-1 || Y-i == 0) break;
    }
    upEach[X+i][Y-i] = result;
    //printf("base coor: %d,%d => sum:%llu \n", X+i, Y-i, result);
  }

  /*
  //Verify Database
  for(int i = 0; i < size; i++) {
    printf("row:%d => sum:%llu \n", i, rowEach[i]);
  }
  for(int i = 0; i < size; i++) {
    printf("col:%d => sum:%llu \n", i, colEach[i]);
  }
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
      printf("%llu ", downEach[i][j]);
    }
    printf("\n");
  }
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
      printf("%llu ", upEach[i][j]);
    }
    printf("\n");
  }
  */

  //Calling: finding related x,y,up,down

  for(int i = 0; i < tests; i++) {
    unsigned long long bright = 0;
    int x, y;
    scanf("%d %d", &x, &y);
    if(check(x, y)){
      //check mem for any counted value
      if(mem[x][y] == 0){
        //row and down
        bright += rowEach[x] + colEach[y];
        // printf("row: %llu and col: %llu \n", rowEach[x], colEach[y]);

        //down++
        int dX = x;
        int dY = y;
        while(dX < size-1 && dY < size-1) {  //-1 because d++
          dX++;
          dY++;
        }
        bright += downEach[dX][dY];
        // printf("%d %d down++: %llu \n", dX, dY, downEach[dX][dY]);

        //up+-
        int uX = x;
        int uY = y;
        while(uX < size-1 && uY > 0) {
          uX++;
          uY--;
        }
        bright += upEach[uX][uY];
        // printf("%d %d up+-: %llu \n ", uX, uY, upEach[uX][uY]);

        //redundant axis
        bright -= (img[x][y])*3;

        //Getting result
        mem[x][y] = bright;
        printf("%llu\n", bright);
      }else{
        printf("%llu\n", mem[x][y]);
      }


    }
  }

  return 0;
}


int check(int X, int Y) {
  return (X >= 0 && X < size && Y >= 0 && Y < size);
}

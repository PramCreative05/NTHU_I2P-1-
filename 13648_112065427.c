/*
1. matrix size
2. max iteration
3. initial position

10
10
5 5

j x j D p i b p m G
G t v w e o g n r Q
I i y Y c V J D g h
b Z L O s H w S y C
H I g q R V o Y e R
z n F D C O t Y z I
I A j y o y i P R x
f N q u M k I L a d
C G M F q R M w T Y
L g I b H t U x R n

OVHsceoeoeo

*/

#include <stdio.h>

int main(void) {
  int size = 0;
  int max_iter = 0;

  int x = 0;
  int y = 0;

  scanf("%d", &size);
  scanf("%d", &max_iter);
  scanf("%d %d", &x, &y);

  char matrix[size][size];

  for(int  i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
      scanf(" %c", &matrix[i][j]);
      // ^^ Please add space before if you meet with formatting problem
    }
  }

  printf("%c", matrix[x][y]);
  int MODE = 0; // 0 => smallest; 1 => largest
  for(int T = 0; T < max_iter; T++){  //GENERAL LIMITER: ITERATION
    // Assign the preinit max/min based on mode (z = 122 A =41)
    char temp;
    int tempX = 0;
    int tempY = 0;
    if(MODE){
      //true = largest
      temp = 'A';
    }else{
      //false => smallest
      temp = 'z';
    }

    // 1. To check whether the initial (x,y) is out of bound
    if((x >= 0 && x < size) && ( y >= 0 && y < size)){
      // printf("Entering the program:\n");

      // 2. To loop the locale/neighbour
      for(int i = -1; i < 2 ; i++){
        for(int j = -1; j < 2; j++){
          if(i == 0 && j == 0){ //Checking the locale
            continue;
          }
          else
          {
            // printf("Now is x: %d, y: %d\n", x + i, y + j);
            // 3. Finding smallest or largest
            if((x + i < 0 || x + i >= size) || (y + j < 0 || y + j >= size)){
              // printf("Cannot be counted\n");
              continue;
            }
            else
            {
              // printf("Can be counted\n");
              // Check max or min mode
              if(MODE){  //True = largest
                if(matrix[x + i][y + j] >= temp) // >= because choose the largest index
                {
                  temp = matrix[x + i][y + j];
                  tempX = x+i;
                  tempY = y+j;
                  // printf("Updating the new temp with : %c\n", temp);
                }
                else
                {
                  // printf("%c is not bigger than %c\n", matrix[x + i][y + j], temp);
                  continue;
                }
              }else{  //False = smallest
                if(matrix[x + i][y + j] <= temp)
                {
                  temp = matrix[x + i][y + j];
                  tempX = x+i;
                  tempY = y+j;
                  // printf("Updating the new temp with : %c\n", temp);
                }
                else
                {
                  // printf("%c is not smaller than %c\n", matrix[x + i][y + j], temp);
                  continue;
                }
              }
            }
          }
        }
      }  //Closure for locale loop

      // 4. Determine the case logic for updating index & mode

      //['a', 'f', 'k', 'p', 'E', 'J', 'O', 'T'] => left
      if(temp == 'a' || temp == 'f' || temp == 'k' || temp == 'p' ||
        temp == 'E' || temp == 'J' || temp == 'O' || temp == 'T'){
        y--;
        printf("%c", matrix[x][y]);
      }
      //['b', 'g', 'l', 'q', 'D', 'I', 'N', 'S'] =>  right
      else if(temp == 'b' || temp == 'g' || temp == 'l' || temp == 'q' ||
        temp == 'D' || temp == 'I' || temp == 'N' || temp == 'S'){
        y++;
        printf("%c", matrix[x][y]);
      }
      //['c', 'h', 'm', 'r', 'C', 'H', 'M', 'R'] => up
      else if(temp == 'c' || temp == 'h' || temp == 'm' || temp == 'r' ||
        temp == 'C' || temp == 'H' || temp == 'M' || temp == 'R'){
        x--;
        printf("%c", matrix[x][y]);
      }
      //['d', 'i', 'n', 's', 'B', 'G', 'L', 'Q'] => down
      else if(temp == 'd' || temp == 'i' || temp == 'n' || temp == 's' ||
        temp == 'B' || temp == 'G' || temp == 'L' || temp == 'Q'){
        x++;
        printf("%c", matrix[x][y]);
      }
      //['e', 'j', 'o', 't', 'A', 'F', 'K', 'P'] => to the temp; flip mode
      else if(temp == 'e' || temp == 'j' || temp == 'o' || temp == 't' ||
        temp == 'A' || temp == 'F' || temp == 'K' || temp == 'P'){
        if(MODE){
          MODE = 0;
        }else{
          MODE = 1;
        }
        x = tempX;
        y = tempY;
        printf("%c", matrix[x][y]);
      }
      // to the temp index
      else{
        x = tempX;
        y = tempY;
        printf("%c", matrix[x][y]);
      }
    }
    else
    {
      printf("Out of Bound\n");
      break;
    }

  }
  return 0;
}

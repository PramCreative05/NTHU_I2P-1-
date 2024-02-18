/*

2
9
255 0 0 0 255 0 0 0 255
254 255 0 0 255 0 0 255 0
0 0 255 0 255 0 255 0 0
0 0 0 255 255 255 0 0 0
255 255 255 255 255 255 255 255 255
0 0 0 255 255 255 0 0 0
0 0 255 0 255 0 255 0 0
0 255 0 0 255 0 0 255 0
255 0 0 0 255 0 0 0 255

0 255 0 0 0 255 0 0 254
0 0 255 0 0 255 0 0 255
0 0 0 255 0 255 0 255 0
0 0 0 0 255 255 255 0 0
255 255 255 255 255 255 255 255 255
0 0 0 0 255 255 255 0 0
0 0 0 255 0 255 0 255 0
0 0 255 0 0 255 0 0 255
0 255 0 0 0 255 0 0 0

number of star
1
1


255 000 000 000 255 000 000 000 255
254 255 000 000 255 000 000 255 000
000 000 255 000 255 000 255 000 000
000 000 000 255 255 255 000 000 000
255 255 255 255 255 255 255 255 255
000 000 000 255 255 255 000 000 000
000 000 255 000 255 000 255 000 000
000 255 000 000 255 000 000 255 000
255 000 000 000 255 000 000 000 255
*/

#include <stdio.h>

//If array size is variable, cannot init;
int matrix[2049][2049]; //OJ = 2048
int main(void) {

  int tests = 0;
  int size = 0;

  scanf("%d", &tests);
  scanf("%d", &size);
  int border = size - 1;

  while(tests--) { //Iterate till Que End
    // [Step 1]: Set Up Counter Parser
    int row[2049]= {0};
    int col[2049] = {0};
    int downhill[4099] = {0};
    int uphill[4099] = {0};

    // [Step 2]: Set Up Matrix and Parsing
    for(int i = 0;  i < size; i++){
      for(int j = 0; j < size; j++){
        scanf("%d", &matrix[i][j]);
        // [Step 2.a]: Parsing; If == 255; +1; if all true; sum=size
        if(matrix[i][j] == 255){
          row[i]+=1;
          col[j]+=1;
          downhill[i-j+border]+=1; //Left-Bottom = 4
          uphill[i+j]+=1; //Right-Bottom = 4
        }
      }
    }

    unsigned long long int result = 0;
    // [Step 3]: Checking whether for each point has valid axis
    for(int i = 0; i < size; i++){
      for(int j = 0; j < size; j++){
        //For row and col, because square matrix, the sum of all member = size
        //But for diagonal we need to find each diagonal member first


        // [Step 3.a]: Finding diagonal member for each i,j
        int member_down = 0;
        int member_up = 0;

        if(i-j > 0){  //Downhill Flip the limit
          member_down = size - (i - j); // Below the downhill i-j>0  so - the size
        }
        else{
          member_down = size + (i - j); //Above the downhill i-j<0 so + the size
        }

        if(i+j >= size){  //Uphill Flip the limit
          member_up = 2*size - (i+j+1); //below uphill i+j>=size so - the max
        }
        else{
          member_up = i+j+1; //Above uphill i+j<size so + all
        }


        // [Step 4: Validate all axis exist]
        if(row[i] == size && col[j] == size && downhill[i-j+border] == member_down
          && uphill[i+j] == member_up){
          result++;
        }

      }
    }//Closure for each matrix

    // [Step 5]: Printing Result
    printf("%lld\n", result);

  }//Closure after que finish
  return 0;
}

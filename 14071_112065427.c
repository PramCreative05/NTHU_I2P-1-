/*
8 8
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 1 1 1 1
0 0 0 0 1 1 1 1
0 0 0 1 1 1 1 1
0 0 1 1 1 1 1 1
0 0 1 1 1 1 0 0
0 0 1 1 1 0 0 0

8 8
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 0

8 8
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1

4 4
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1

4 4
1 1 1 0
1 1 1 1
1 1 1 1
0 1 1 1

4 4
1 1 1 1
1 1 1 1
1 1 1 1
0 1 1 1


11
112
113
1211
1212
1213
123
130
131
1320
1321
1322

3 3
1 1 1
1 1 1
1 1 1

6
10
110
112
120
121
130
*/

#include <stdio.h>
#include <math.h>

int ctr = 0;
int found[10000];
int matrix[128][128] = {0};

int getSize(int larger_dim){
    int p = 0;
    while(pow(2,p) < larger_dim) p++;
    return pow(2,p);
}

int subTitan(int size, int row, int col){
    //printf("Checking? row: %d col: %d size:%d\n", row, col, size);
    for(int i = row; i < row + size; i++){
        for(int j = col; j < col +size; j++){
            if(matrix[i][j] != 1)
                return 0;
        }
    }
    //printf("OK!\n");
    return 1;
}

void diverged(int size, int row, int col, int address){
    int status = subTitan(size,row, col);

    if(status){
        found[ctr] = address;
        ctr++;
    }
    else{
        if(size != 1){
            int border =  size/2;
            diverged(border, row,        col,        address*10);
            diverged(border, row,        col+border, address*10+1); //Col first
            diverged(border, row+border, col,        address*10+2); //Then Row
            diverged(border, row+border, col+border, address*10+3);
        }
    }
    return;
}

int main(void){
    int rows, cols;
    scanf("%d %d", &rows, &cols);

    int start = rows >= cols ? getSize(rows) : getSize(cols);

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            scanf(" %d", &matrix[i][j]);
        }
    }

    //printf("Start Progress with size = %d\n", start);
    diverged(start, 0, 0, 1);
    printf("%d\n", ctr);
    for(int i = 0; i < ctr; i++) printf("%d\n", found[i]);
    return 0;
}



/*
#include <stdio.h>

#define MAX_SIZE 8
int matrix[MAX_SIZE][MAX_SIZE];

// Function to check if the sub-quadtree block is eligible
int isEligible(int level, int row, int col) {
    int size = 1 << level;
    for (int i = row; i < row + size; i++) {
        for (int j = col; j < col + size; j++) {
          // printf("aa %d %d %d %d\n", col, size, i, j);
            if (matrix[i][j] != 1 ) {
                // mem--; // Not eligible if any element is not 1
                return 0;
            }
        }
    }

    for (int i = row; i < row + size; i++) {
        for (int j = col; j < col + size; j++) {
          matrix[i][j] = 2;
        }
    }
    return 1;
}

// Function to count eligible sub-quadtree blocks
int countEligibleBlocks(int level, int row, int col, int max) {
    // if (level >= MAX_SIZE) {
    //     return 0; // Reached the maximum level
    // }
    if(level < 0){
      return 0;
    }

    int count = 0;
    int size = 1 << level;

    int result = 0;
    for (int i = row; i < max; i += size) {
        for (int j = col; j < max; j += size) {

            if (isEligible(level, i , j)) {
                count++;
            }

        }
    }

    // Recursive call for the next level
    count += countEligibleBlocks(level - 1, row, col, max);
    // count += countEligibleBlocks(level - 1, row + size, col, max);
    // count += countEligibleBlocks(level - 1, row, col + size, max);
    // count += countEligibleBlocks(level - 1, row + size, col + size, max);

    return count;
}

int main() {
    // Input matrix
    int rows, cols;
    scanf("%d %d", &rows, &cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Count eligible sub-quadtree blocks
    int result = countEligibleBlocks(3, 0, 0, rows);

    // Print the result
    printf("%d\n", result);

    return 0;
}
*/

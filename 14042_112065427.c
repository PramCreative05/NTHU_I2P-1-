/*
5 5
#####
#S..#
###.#
#M..#
#####

5 5
#####
#S..#
#.#.#
#M#M#
#####

5 5
#####
#.S.#
#.#.#
#M#M#
#####

9 17
#################
#.#...#........M#
#.###.#.###.###.#
#S..#...#.#...#.#
#.#.#####.#####.#
#.#.....#.....#.#
###.###.###.#.#.#
#M..#.......#...#
#################
*/

#include <stdio.h>

int rows;
int cols;

int min_steps = 0;
int steps = 0;

void checkMaze(int rows, int cols, int visited[rows][cols]){
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      printf("%d ", visited[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int isSafe(int x, int y, int rows, int cols, int maze[rows][cols], int visited[rows][cols]){
  if(x >= 0 && x < rows && y >= 0 && y < cols && maze[x][y] != 0 && visited[x][y] == 0 && maze[x][y] != 2)
    return 1;
  else
    return 0;
}

int findMeat(int x, int y, int rows, int cols, int maze[rows][cols], int visited[rows][cols]){
  int meats = 0;

  if(maze[x][y] == 3){
    printf("!!Meat Found!!\n");
    min_steps += steps*2;
    printf("Current steps %d; journey: %d\n", steps, min_steps);
    return 1;
  }

  if(maze[x][y] == 2){
    steps = 0;
  }



  int dx[] = {0, 0, 1, -1};
  int dy[] = {1, -1, 0, 0};

  for (int i = 0; i < 4; i++) {
      int new_x = x + dx[i];
      int new_y = y + dy[i];

      if (isSafe(new_x, new_y, rows, cols, maze, visited)) {
          visited[new_x][new_y] = 1;
          steps += 1;

          //printf("Move:\n");
          //checkMaze(rows, cols, visited);

          meats += findMeat(new_x, new_y, rows, cols, maze, visited);
          //visited[new_x][new_y] = 0;
          steps -= 1;

          //printf("Back:\n");
          //checkMaze(rows, cols, visited);
      }
  }

  return meats;
}


int main() {
  scanf("%d %d", &rows, &cols);

  int maze[rows][cols];
  int visited[rows][cols];

  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      maze[i][j] = 8;
      visited[i][j] = 0;
    }
  }

  for (int i = 0; i < rows; i++) {
      for(int j = 0; j < cols; j++){
        char com;
        scanf(" %c", &com);
        if(com == '#'){
          maze[i][j] = 0;
        }else if(com == '.'){
          maze[i][j] = 1;
        }else if(com == 'S'){
          maze[i][j] = 2;
        }else if(com == 'M'){
          maze[i][j] = 3;
        }
      }
  }

  int start_x, start_y;
  for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
          if (maze[i][j] == 2) {
              start_x = i;
              start_y = j;
              break;
          }
      }
  }


//  for(int i = 0; i < rows; i++){
//    for(int j = 0; j < cols; j++){
//      printf("%d ", maze[i][j]);
//    }
//    printf("\n");
//  }

  //printf("start:%d %d\n", start_x, start_y);

  int meats = findMeat(start_x, start_y, rows, cols, maze, visited);
  //printf("found: %d\n", meats);
  printf("%d\n", min_steps);



  return 0;
}

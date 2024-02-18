#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
  char unzip[1001];
  int ok = 0;

  while(scanf("%s", unzip) != EOF){      //Ctrl+D or Ctrl+Z for win
    int i= 0;                            //local index
    int flag = 1;
    char zip[1000000]  = "";

    // printf("=========NEW LINE: %s====\n", unzip);
    while(unzip[i] != '\0' && flag){
      // printf("new loop with i=%d\n", i);

      //========Validation=====
      char rep[4];
      char content[1] = "";
      int loc = i;
      int rep_index = 0;

      // printf("# Starting new pair with i=%d\n", i);
      for(int j = 0; j< 4; j++){
        // printf("What's now: [%c and j = %d] \n", unzip[loc+j], j);

        if(isdigit(unzip[loc+j]) || ( (isalpha(unzip[loc+j]) || unzip[loc+j] == '\'' ) && j>0) ){  // Let's make it general parser; be careful of parenthesis
          if(isdigit(unzip[loc+j]))
          {
            if(rep_index == 0 && unzip[loc+j] == '0'){  //Exception for 0 lead
              printf("Domo cannot crack this computer\n");
              flag = 0;
              ok = 0;
              break;
            }

            if(j == 3 & unzip[loc+j] != '0'){  //Exception for max int >100
              printf("Domo cannot crack this computer\n");
              flag = 0;
              ok = 0;
              break;
            }

            rep[rep_index] =  unzip[loc+j];
            // printf("finish parsing digit: %c\n", rep[rep_index]);
            // Valid: update i++;
            i++;
            rep_index++;
          }
          else
          {  // Checking for alphabet
            if(isalpha(unzip[loc+j])){
              content[0] = unzip[loc+j];
              // printf("finish parsing alpha: %c\n", content[0]);
              ok = 1;
              i++;
              break;
            }
            else if(unzip[loc+j] == '\''){  // Checking for single quote
              if(unzip[loc+(j+2)] == '\''){
                if(isdigit(unzip[loc+(j+1)]))
                {
                  content[0] = unzip[loc+(j+1)];
                  // printf("finish parsing alpha quote: %c\n", content[0]);
                  ok = 1;
                  i += 3;
                  break;
                }
                else
                {
                  printf("Domo cannot crack this computer\n");  //Exception for quote not digit
                  flag = 0;
                  ok = 0;
                  break;
                }

              }
              else{
                printf("Domo cannot crack this computer\n");  //Exception for fail single quote
                flag = 0;
                ok = 0;
                break;
              }

            }
          }
        }
        else
        {
          printf("Domo cannot crack this computer\n");  //Exception for wrong syntax
          flag = 0;
          ok = 0;
          break;  //break from the for loop aka active pair
        }
      }

      if(ok == 1){ //change with stringcat THE MULTIPLY FUNCTION HERE
        /*
        printf("=> Finihed a pair with val = ");
        for(int i = 0; i < rep_index; i++){
          printf("%c", rep[i]);

        }
        printf("%c\n", content[0]);
        */

        int times = 0;
        // converting string to number
        for (int i = 0; i < rep_index; i++) {
            times = times * 10 + (rep[i] - 48);
        }
        // printf("$$ time = %d\n", times);

        for(int i = 0; i < times; i++){
          strncat(zip, content, 1);
        }

      }

    }  //----------------------------Closure for scanning 1 line
    //Write the final mulitple pairs here
    if(ok == 1) printf("%s\n", zip);

  }  //Closure for per line


  return 0;
}

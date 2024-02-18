#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "function.h"

//implement split string function, return 2d char array to store result, set correct number of splitted strings
char **split(char* string, char* pattern, int* splittedStrings);
//free memory space
void free_(char **result, int splittedStrings);

char **split(char* string, char* pattern, int* splittedStrings){

    //1. Establish parameter
    char** result = NULL;

    int len = strlen(string);
    int demLen = strlen(pattern);


    //2. Traverse
    int i_subStr = 0;
    for(int i = 0; i <= len){ //Until the end of the ori string
        int subStrLen = i - i_subStr; //len Adjustment for each potential scan;

        if(strncmp(&string[i], pattern, demLen) == 0 || i == len){//found the same pattern as dem or finish
            if(subStrLen > 0){
                if(i != '\0') string[i] = '\0'; //Replace the head of the delimiter with terminator to print s

                result = realloc(result, ((*splittedStrings + 1) * sizeof(char *))); //add one char address
                result[*splittedStrings] = &string[i_subStr]; //Save the head of the first subStr
                (*splittedStrings)++; //Deref and add 1 more
            }
            i_subStr = i += demLen;
        }
        else{
            i++; //Move by 1
        }
    }



    return result;
}


//free memory space
void free_(char **result, int splittedStrings){
   free(result); //free the address colection
}


/*
13996 - Squidward Musical

The notes that patrick writes contains a lot of palindromes and Spongebob suspects that this is the key to copying
Squidward's beautiful music but just to be sure, he wants to count how many palindromes are in the string.

Palindromes is a set of words that are read the same when written forwards and backwards,
however for this problem, palindromes that have 2 characters or less do not count.

For example the string elellal contains only 3 palindromes:
- ele
- lel
- lal

'll' does not count as a palindrome because it only has 2 characters.
Count how many palindromes are in a given string from patrick's notes.
Note: duplicate palindromes still count!

For example the string elele contains 4 palindromes:
- ele
- lel
- ele
- elele

Input: elellal
A single string with length l (1 <= l <= 1000).

Output: 3
The number of Palindromes in the string followed by a newline character "\n".
*/

#include <stdio.h>
#include <string.h>

int counter = 0;

//Palindrome Checker
void palindrome(char *str){
    int start = 0;
    int end = strlen(str) - 1;

    while(start < end){
        if(str[start++] != str[end--]){
            return;
        }
    }
    counter++;
    return;
}

int main(void){
    char input[1001];
    scanf("%s", input);

    int end = strlen(input);
    int i, j;

    for(i = 0; i<end-2; i++){               //updating starting index of input
        char temp[1001] = "";               //creating temp memory so we can get all the comb
        for (j = i; j < end; j++){          //Updating the temp want to be checked
            strncat(temp, &input[j], 1);    //appending letter to the checker
            if(strlen(temp)>= 3){           //fulfilling palindrome length rule
                palindrome(temp);           //Checking the current temp
            }
        }
    }
    printf("%d\n", counter);
    return 0;
}



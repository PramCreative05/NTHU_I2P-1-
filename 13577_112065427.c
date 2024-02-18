/*
To encrypt the string by changing lowercase to uppercase and reversing each alphabet.
That is,
  'a' first becomes 'A' and then becomes 'Z'.

  'b' first becomes 'B' and then becomes 'Y'.

  'c' first becomes 'C' and then becomes 'X'.
  ...

  'y' first becomes 'Y' and then becomes 'B'.

  'z' first becomes 'Z' and then becomes 'A'.

Input
Input contains only a line.
A 5 character word.
It is guarantee that the word contains only lower case alphabet.

Output
The encrypted word.

remember to print \n at the end of output.
*/

#include <stdio.h>

int main(void){
    // A-Z: DEC 65-90
    // a-z: DEC 97-122
    // enc = ori - (7+2*i); 0<=i<26
    // i = -(97-input)

    char ori[6];
    scanf("%s", ori);
    int i, ctr, enc =0;

    while(ori[ctr] != '\0'){
        i = -(97-ori[ctr]);
        enc = ori[ctr] - (7 + 2*i);
        ori[ctr] = enc;
        //printf("%c\n", ori[ctr]);
        ctr++;
    }
    printf("%s\n", ori);

    return 0;
}

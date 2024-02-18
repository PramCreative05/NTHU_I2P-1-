/*
Given a 6-digit binary, help her to encrypt the password to a character.

The first digit is a signed bit, as per the rules :

If the signed bit is 1, make it lowercase
If the signed bit is 0, make it uppercase
The last 5 digits determine the number. Convert the number to a character, as:

Number 1 is ‘a’
Number 2 is ‘b’
Number 3 is ‘c’
and so on … until 26 as ‘z’
All of them are based on alphabetic order.

Explanation of sample input :

010010 split into 0 and 10010
The signed bit is 0, which means it’s uppercase
10010 is 18, which is R in alphabetical order.

Follow-up: Can you do it without if-else?
Follow-up 2: How will you solve it if the character is assigned in the reverse order? Maybe it'll appear in your lab next Monday!

Input
Input is 6 digit binary representation number (contain 1 or 0)
You can safely asume that the number is in the range 1 <= X <= 26
You might see the sample input if the description is not clear enough

Output
Output the encrypted character
Don't forget to print the new line

||Sample
Input: 010010 = 18 uppercase => (1,26) base alphabet
Output: R

*/

#include <stdio.h>

int main(void){
    int bin;                            // 6 digits binary
    scanf("%d", &bin);

    // 1 => lowercase; 0 => uppercase
    // A-Z: DEC 65-90
    // minus 32 for lower case
    // a-z: DEC 97-122

    // ===========TESTED NO IF ELSE============
    int cap;
    int last;
    int base = 1;

    int ascii = 65;     // start with A uppercase
    int n_ascii;
    int r_ascii;

    cap = bin/100000;
    ascii = ascii + cap*32; // lower or uppercase
//    printf("1 lower => 32 : %d\n", ascii); // debug capitalization

    // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    int counter = 0;
    int order = 0;

    // Ref: Binary conversion algorithm: https://www.javatpoint.com/binary-to-decimal-number-in-c

    while(bin>0 && counter < 5)         //only getting the last 5 digit => 2^4
    {
        last = bin % 10;                //for getting the last digit
        order = order + (last*base);    //adding the processed last digit with updated base
        bin = bin/10;                   //forwarding the binary aka toss the last digit
        base = base *2;                 //updating the base as soon as tossing the last digit
        counter++;
//        printf("%d\n", base);         //debug: based update should be max 4
    }

//    printf("%d", ascii+(order-1));    //debug: ascii position

    n_ascii = ascii + (order-1);          //non-reverse
    r_ascii = ascii + (26-order);         //reverse


    printf("%c\n", n_ascii);
    printf("%c", r_ascii);

    return 0;
}

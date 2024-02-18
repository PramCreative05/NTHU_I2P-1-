/*
Your program should first read an integer number indicating how many tracking codes you plan on entering.
Next, for each successive tracking code your program should read in the integer length of code
followed by a space and then the type of code ('i' for integer, 'd' for decimal, or 'c' for character).

Finally your program should print the total amount of space required to store all of the tracking codes (in bytes).
If the user enters an incorrect type for any tracking number,
the program should print 'Invalid tracking code type' and exit.

Examples
Input:
3
10 i
7 c
12 d
Output:
143 bytes
*/

#include <stdio.h>

int memCal(int, char[1]);

int main(void){
    int iter;
    scanf("%d", &iter);

    int total = 0;
    int mem;
    char units[1];

    for(int i = 0; i<iter;i++){
        scanf("%d %c", &mem, units);
        total = total + memCal(mem, units);
    }

    if(total<1000){
        printf("%d bytes", total);
    }else{
        printf("Invalid tracking code type");
    }

    return 0;
}

int memCal(int mem, char units[1]){
    char unit = units[0];
    if(unit == 'i'){
        return sizeof(int) * mem;
    }
    else if(unit == 'd'){
        return sizeof(double) * mem;
    }
    else if(unit == 'c'){
        return sizeof(char) * mem;
    }
    else{
        return 1000;
    }
}

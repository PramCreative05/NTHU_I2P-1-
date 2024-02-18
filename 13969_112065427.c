/*
Given input X which describes the total days, convert X to the number of years and seconds.

Note :
1 year is 365 days
1 day is 24 hours
1 hour is 3600 seconds
Input
Input contains 1 integer X
0 < X < 231

Output
Output 3 numbers,
number of years in double datatype, years in float datatype, and seconds, separated by space.
The year should be in 6th decimal place format.
Don’t forget to print a new line '\n' after the end of the output.

Example:
Input
2000000000
Output
5479452.054795 5479452.000000 172800000000000

//COMPILER ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

*/

#include <stdio.h>

int main(void){
    long long int days;
    scanf("%ld", &days);

    double d_y = days/365.0;
    float f_y=  days/365.0;
    long long int sec = days*24*3600;

    printf("%.6lf %.6f %16ld\n", d_y, f_y, sec);
    return 0;
}

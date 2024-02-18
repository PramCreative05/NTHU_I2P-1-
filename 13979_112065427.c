/*
13979 - we stack boxes
Status  |  Limits
Description
There are n  boxes with length of l each.
Jake wanted to stack the boxes into a tall tall tower.
Help him calculate the height of the tower h.

Input
Two integers n and l  seperated by a blank
(1 < n, l < 1000)

Output
The height h. (No need to use '\n')
*/

#include <stdio.h>

int main(void){
    int n, l, h = 0;
    scanf("%d %d", &n, &l);

    h = n*l;
    printf("%d", h);

    return 0;
}

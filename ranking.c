/*
The order in which names are displayed in the output should be the same as the order given in the input.
The ranking starts at 1 (meaning this student has the highest score), 2 for the second highest grade etc...
Note that no name has more than 50 characters and there are no more than 30 students.

Input
3 number of student
14
2
20
Remi
Yan
Maria

Output
Remi rank is 2
Yan rank is 3
Maria rank is 1
*/

#include <stdio.h>

int main(void){
    int num;
    scanf("%d", &num);

    char name[num-1][51];
    int scr[num-1];
    int cop[num-1];

    int i, j, k=0;
    int swap;

    //Saving name
    for(i=0;i<num;i++){
        scanf("%s", name[i]);
    }

    //Saving score
    for(i=0;i<num;i++){
        scanf("%d", &scr[i]);
        cop[i] = scr[i];
    }

    for(j=0;j<num;j++){
        for(i=0;i<num;i++){
            if(cop[i]<cop[i+1]){
                swap = cop[i+1];
                cop[i+1] = cop[i];
                cop[i] = swap;
            }
        }
    }

    for(i=0;i<num;i++){
        j=0;
        printf("%s rank is ", name[i]);
        while(scr[i] != cop[j]){
            j++;
        }
        printf("%d\n", j+1);
    }


    return 0;
}

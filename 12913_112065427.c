/*
12913 - Big number addition

Description
In the most of arithmetic addition case, we can simply use int or long long to store the two integers
and compute the answer by the operater '+' in C. If we have two big integers that can not be stored into the varibles mentioned below,
we should make use of arrays to complete the addition task.

Given two big number A, B, please compute A + B.

Input
First line contains an integer which denotes the length of  A. The following one line contains the big integer A.
Third line contains an integer which denotes the length of  B. The following one line contains the big integer B.
(1 ≤  number of digits of A, B ≤ 100, both A and B are intergers ≥ 0)

25
1111111111111111111111111
25
1111111111111111111111111

Output
An integer which denotes the answer of A + B.
2222222222222222222222222

Note that you don't need to print '\n' at the end of the output
*/

#include <stdio.h>

void add(int keeper, int flwr, char main[], char sub[]){
    char result[keeper+1];//preparing for spillover and string
    int carry = 0;
    int sum;

    int end1 = keeper-1;
    int end2 = flwr-1;

    int i;

    for (i = end1; i >= 0; i--) {
        int below;

        if(end2>=0){
            below = sub[end2] - '0';
        }else{
            below = 0;
        }

        sum = (main[i] - '0') + (below) + carry;
        result[i+1] = (sum % 10) + '0';
        carry = sum / 10;
        end2--;
        //printf("%d: %c\n", i, result[i+1]);
    }

    //exception for first digit spillover
    if(carry){
        //printf("i:%d %d\n",i,carry);
        result[0] = carry + '0';
    }else{
        result[0] = 0 + '0';
    }

    result[keeper+1] = '\0';    //because keeper position is reserved for last digit

    int index = 0;
    int flag = 1;
    while(index < keeper+1){
        if(flag == 1 && result[index] == '0' && index < keeper){    //Printing the last zero only

        }else{
            printf("%d", result[index]-'0');
            flag = 0;
        }
        index++;
    }
}

int main(void){
    int num1_d, num2_d;

    scanf("%d", &num1_d);
    char num1[num1_d+1];    //add 1 because want to save string
    scanf("%s", num1);

    scanf("%d", &num2_d);
    char num2[num2_d+1];    //add 1 because want to save string
    scanf("%s", num2);

    int keeper;
    int flwr;

    if(num1_d>num2_d){
        keeper = num1_d;
        flwr = num2_d;
        add(keeper, flwr, num1, num2);
    }else{
        keeper = num2_d;
        flwr = num1_d;
        add(keeper, flwr, num2, num1);
    }
    return 0;
}






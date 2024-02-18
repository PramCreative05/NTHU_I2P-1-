#include <stdio.h>
#include <stdlib.h>

int prefix(char* stat, int* position){
    char op = stat[(*position)++];
    if(op >= '0' && op <= '9'){
        return op - '0';
    }else{
        int operand1 = prefix(stat, position);
        int operand2 = prefix(stat, position);
        switch(op){
            case '+':
                return operand1 + operand2;
            case '-':
                return operand1 - operand2;
            case '*':
                return operand1 * operand2;
            case '/':
                return operand1 / operand2;
            default:
                printf("Invalid Syntax");
                exit(EXIT_FAILURE);
        }
    }
}

int main(void){
    char stat[100];
    scanf("%s", stat);
    int position = 0;
    int result = prefix(stat, &position);
    printf("Result: %d\n", result);
    return 0;
}

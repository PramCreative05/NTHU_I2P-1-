#include <stdio.h>
#include <string.h>

char str[1000001];
char res[1000001];
int K;

int main(void) {
    //1. Get the input
    scanf("%s %d", str, &K);
    int len = strlen(str);

    //2. Init
    res[0] = str[0];    //Add first digit to res
    int cursor_str = 1;
    int cursor_res = 0;

    //3. Traverse
    while(K) {
        if(res[cursor_res] <= str[cursor_str]) {
            //Larger => Move Next
            res[++cursor_res] = str[cursor_str++];
        }
        else {
            //Smaller => Cancel
            res[cursor_res] = '\0'; //Block when K > len
            cursor_res--;           //Undo the decision
            K--;                    //let the counter run
        }
    }

    //4. If K digits already omitted, copy the rest
    while( cursor_str < len ){
       res[++cursor_res] = str[cursor_str++];
    }

    //5. Remove leading zero
    sscanf(res, "%*[0]%s", res);
    printf("%s\n", res);

    return 0;

}

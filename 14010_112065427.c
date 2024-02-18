/*
5 2

1
1 3 1
1 2 4 2 1
1 3 5 7 5 3 1
1 2 4 8 16 8 4 2 1
*/

#include <stdio.h>

int main()
{
    int s, k;
    long long int start;
    int mem, m;
    scanf("%d %d", &s, &k);

    for(int i = 1; i<=s; i++){
        start = 1;
        mem = i + (i-1);
        m = 1;
        if(i%2 != 0){
            //printf("[%d] Odd: ", i);

            for(int j = 1; j<=i; j++, m++){
                printf("%lld", start);
                if(j != i && m<mem) printf(" ");
                if(j != i) start = start * k;
            }

            for(int j = 1; j<i; j++, m++){
                if(j == 1) printf(" ");
                start = start / k;
                printf("%lld", start);
                if(i-j != 1) printf(" ");
            }

        }else{
            //printf("[%d] Eve: ", i);

            for(int j = 1; j<=i; j++){
                printf("%lld ", start);
                if(j != i) start = start + k;
            }

            for(int j = 1; j<i; j++){
                start = start - k;
                printf("%lld", start);
                if(i-j != 1) printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}

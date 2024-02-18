#include <stdio.h>

#define MOD 1000000007

long long towerVar(int n){//Input the n=height
    long long int a[n+1], b[n+1]; //Start with 1, end included

    a[1] = 1;
    b[1] = 1;

    /*Input the permutation formula, Save the cumulative result*/
    for(int i = 2; i <= n; i++){
        a[i] = (2 * a[i-1] + b[i-1]) % MOD; //a => Without Border
        b[i] = (4 * b[i-1] + a[i-1]) % MOD; //b => With Border
    }

    return (a[n] + b[n]) % MOD;
}

int main(void){
    int q, n; //q = testcase

    scanf("%d", &q);

    while(q--){
        scanf("%d", &n);
        printf("%lld\n", towerVar(n));
    }
    return(0);
}

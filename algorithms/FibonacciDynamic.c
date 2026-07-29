#include <stdio.h>

int memo[100];

int fibonacci(int n){
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;

    if(memo[n] != -1){
        return memo[n];
    }

    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);

    return memo[n];
}

int main(){
    int n;

    printf("Enter teh number of terms: ");

    scanf("%d", &n);

    for(int i = 0; i < 100; i++){
        memo[i] = -1;
    }

    for(int i = 0; i < n; i++){
        printf("%d", fibonacci(i));
    }

    printf("\n");

    return 0;
}
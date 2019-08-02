#include <stdio.h>
#include <stdlib.h>

int fib(int n);

int main(void)
{
    // could thread a 'memoisation' table through each call
    // instead of initialising in fib.
    printf("%d\n", fib(5));
    printf("%d\n", fib(9));
}

int fibR(int, int*);

// memoization
int fib(int n) {
    int *memo = calloc(n+1, sizeof(int));
    return fibR(n, memo);
}

int fibR(int n, int *memo) {
    if (memo[n] != 0) return memo[n];
    if (n <= 2) return 1;
    memo[n] = fibR(n-1, memo) + fibR(n-2, memo);
    return memo[n];
}




















int fibL(int n)
{
    int *arr = malloc(sizeof(int) * (n+1));
    // memset could be used i.e. memset(arr, sizeof(int) * (n+1), 1)
    for (int i = 0; i <= n; i++) arr[i] = -1;
    return fibR(n, arr);
}

// assume n passed in is positive
int fibRL(int n, int *memo)
{
    if (memo[n] != -1) return memo[n];
    if (n == 1) return 1;
    if (n == 2) return 1;
    memo[n] = (fibR (n - 1, memo) + fibR (n - 2, memo));
    return memo[n];
}

#include <stdio.h>

/* compute the fibonacci numbers 1 1 2 3 5 8 ... */
long long fib(unsigned int n) {
    if(n <= 2) {
        return 1;
    }

    return fib(n-2) + fib(n-1);
}


int main()
{
    int i;

    for(i = 1; i<1000; i++) {
        printf("%d:\t%ld\n", i, fib(i));
    }
}
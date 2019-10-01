#include <stdio.h>

// f(n) = 1 + 1/(1 + f(n-1))

int digits(unsigned long long n)
{
    int digits = 0;
    while (n >= 1) {
        digits++;
        n /= 10LL;
    }
    return digits;
}

int main()
{
    unsigned long long numerator = 3LL;  // f(1) = 3/2
    unsigned long long denominator = 2LL; // f(1) = 3/2
    unsigned long long numerator_tmp;

    int i;
    int count = 0;
    for (i = 1; i <= 1000; i++) {
        numerator_tmp = numerator;
        numerator = 2LL * denominator + numerator;
        denominator = denominator + numerator_tmp;

        if (digits(numerator) > digits(denominator)) {
            printf("i = %llu: %llu/%llu\n", i, numerator, denominator);
            count++;
        }
    }

    printf("%d fractions a/b, where a has more digits than b\n", count);

    return 0;
}

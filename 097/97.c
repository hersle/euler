#include <stdio.h>

int main()
{
    long long digits = 1;
    int i;
    for (i = 0; i < 7830457; i++)
        digits = (2 * digits) % 10000000000;
    digits = (28433 * digits) % 10000000000;
    digits = (digits + 1) % 10000000000;
    printf("%lld\n", digits);
    return 0;
}

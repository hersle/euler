#include <stdio.h>

int main()
{
    unsigned long long numerator_current = 3;
    unsigned long long numerator_previous = 2;
    unsigned long long numerator_tmp;
    int multiplier;
    int i = 2;
    while (i < 50) {
        i++;

        multiplier = i % 3 == 0 ? (i / 3) * 2 : 1;

        numerator_tmp = numerator_current;

        numerator_current = numerator_previous + multiplier * numerator_current;

        numerator_previous = numerator_tmp;

        printf("i = %lld: %lld\n", i, numerator_current);
        // ...
    }
}

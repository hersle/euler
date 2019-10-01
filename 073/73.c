#include <stdio.h>

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    int a, b, d;

    int a_min;
    int a_max;

    int count = 0;

    for (b = 2; b <= 12000; b++) {
        a_max = (b - 1) / 2;
        a_min = (b + 3) / 3;
        d = a_max - a_min + 1;
        printf("b = %d, a_min = %d, a_max = %d, d = %d\n", b, a_min, a_max, d);

        for (a = a_min; a <= a_max; a++) {
            // printf("gcd(%d, %d) = %d\n", b, a, gcd(b, a));
            if (gcd(b, a) == 1)
                count++;
        }
    }

    printf("count = %d\n", count);

    return 0;
}

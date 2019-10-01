#include <stdio.h>

int f(int n)
{
    return n < 10 ? (n * n) : ((n % 10) * (n % 10) + f(n / 10));
}

int main()
{
    int count = 0;
    int a, b;
    for (a = 1; a < 10000000; a++) {
        b = a;
        while (b != 1 && b != 89) b = f(b);
        if (b == 89) count++;
    }

    printf("%d\n", count);
}

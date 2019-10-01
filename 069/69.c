#include <stdio.h>

int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    /* 
     * For n / phi(n) to be maximized, n must be as high as possible, while
     * phi(n) must be as low as possible. For phi(n) to be low, n must be 
     * relatively prime with few numbers and must share many common factors 
     * with numbers lower than itself. Therefore, we make the largest value of
     * n <= 1 000 000 as possible that consists of as many different prime 
     * factors as possible, i.e. 2 * 3 * 5 * 7 * 11 * 13 * 17 = 510510
     */
    int n = 2 * 3 * 5 * 7 * 11 * 13 * 17;
    int totient = 0;
    int a;
    for (a = 1; a < n; a++)
        if (gcd(n, a) == 1)
            totient++;

    printf("%d / %d = %f\n", n, totient, (double) n / totient);

    return 0;
}

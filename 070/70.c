#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

/*
 * For n / phi(n) to be as low as possible, phi(n) must be as high as possible.
 * Therefore, n must be relatively prime with many primes and consist of few
 * different prime factors.
 *
 * n itself cannot be prime (consist of 1 prime factor), since phi(n) = n - 1 
 * would not be a permutation of n.
 *
 * Next, we check whether n can be a square of a prime. This has been checked 
 * and is not the case.
 * 
 * Next, we check whether n can be a product of two times. This is the case
 * and gives us the solution.
 * 
 * (We should probably have checked whether n could be an arbitrary power of a
 * prime too?).
 */

int are_permutations(int a, int b)
{
    int a_digits[7];
    int b_digits[7];

    int i = 0;
    while (a > 0 && b > 0) {
        a_digits[i] = a % 10;
        b_digits[i] = b % 10;
        a /= 10;
        b /= 10;
        i++;
    }

    if (a != 0 || b != 0)
        return 0;

    int k = i;

    int j;
    for (i = 0; i < k; i++) {
        for (j = 0; j < k; j++) {
            if (a_digits[i] == b_digits[j]) {
                b_digits[j] = -1;
                break;
            }
        }
        if (j == k)
            return 0;
    }

    return 1;
}

int main()
{
    int prime_min = 2;
    int prime_max = (10000000 - 1) / 2;

    int *prime = malloc((prime_max + 1) * sizeof(int));
    memset(prime, 1, (prime_max + 1) * sizeof(int));

    // sieve primes
    int a, b;
    for (a = 2; a <= prime_max; a++)
        for (b = 2; a * b <= prime_max; b++)
            prime[a * b] = 0;

    double f;
    double f_min = DBL_MAX;

    int n;
    int n_res;
    int totient;
    for (a = 2; a <= prime_max; a++) {
        if (!prime[a]) continue;
        for (b = a + 1; b <= 10000000 / a; b++) {
            if (!prime[b]) continue;
            n = a * b;
            totient = (a - 1) * (b - 1);
            if (are_permutations(n, totient)) {
                f = (double) n / totient;
                printf("%d / phi(%d) = %d / %d = %f\n", n, n, n, totient, f);
                if (f < f_min) {
                    f_min = f;
                    n_res = n;
                }
            }
        }
    }

    printf("f_min = %f, n_res = %d\n", f_min, n_res);
}

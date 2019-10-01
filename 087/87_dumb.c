#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int N = 1000;

int main()
{
    int prime_max = (int) sqrt((double) (N - 25));

    int a, b, c;
    int n_primes = 0;
    int *primes = malloc((prime_max + 1) * sizeof(int));

    /* sieve primes */
    printf("sieveing primes from 2 to %d\n", prime_max);
    for (a = 2; a <= prime_max; a++) primes[a] = 1;
    for (a = 2; a <= prime_max; a++) {
        if (primes[a]) {
            for (b = 2; a * b <= prime_max; b++) {
                primes[a * b] = 0;
            }
            primes[n_primes] = a;
            n_primes++;
        }
    }

    /*
    for (a = 0; a < n_primes; a++)
        printf("%d ", primes[a]);
    putchar('\n');
    */

    int p1, p2, p3;
    unsigned long long sum;
    int count = 0;

    for (a = 0; a < n_primes; a++) {
        p1 = primes[a];
        for (b = 0; b < n_primes; b++) {
            p2 = primes[b];
            for (c = 0; c < n_primes; c++) {
                p3 = primes[c];
                sum = p1 * p1 + p2 * p2 * p2 + p3 * p3 * p3 * p3;
                if (sum < N) {
                    printf("%d, %d, %d, %d\n", sum, p1, p2, p3);
                    count++;
                }
            }
        }
    }

    /*
    for (a = 0; a < N; a++) {
        i = a / (8 * sizeof(int));
        m = 1 << (a % (8 * sizeof(int)));
        printf("%d", (counted[i] & m) != 0);
    }
    printf("\n");
    */

    printf("count = %d\n", count);

    return 0;
}

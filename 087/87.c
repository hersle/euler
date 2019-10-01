#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const long long int N = 50000000;

int main()
{
    int prime_max = (int) sqrt((double) (N - 25));

    int a, b, c;
    int n_primes = 0;
    int *primes = malloc((prime_max + 1) * sizeof(int));

    /* sieve primes */
    for (a = 2; a <= prime_max; a++) primes[a] = 1;
    for (a = 2; a <= prime_max; a++) {
        if (primes[a]) {
            for (b = 2; a * b <= prime_max; b++)
                primes[a * b] = 0;
            primes[n_primes] = a;
            n_primes++;
        }
    }

    int *counted = malloc(N / 8 + sizeof(int));
    for (a = 0; a <= N / (8 * sizeof(int)); a++)
        counted[a] = 0;

    long long int  p1, p2, p3;
    long long int sum1, sum2, sum;
    int count = 0;
    int i, m;

    for (a = 0; a < n_primes; a++) {
        p1 = primes[a];
        sum1 = p1 * p1;
        for (b = 0; b < n_primes; b++) {
            p2 = primes[b];
            sum2 = sum1 + p2 * p2 * p2;
            if (sum2 >= N) break;
            for (c = 0; c < n_primes; c++) {
                p3 = primes[c];
                sum = sum2 + p3 * p3 * p3 * p3;
                if (sum >= N) {
                    break;  /* skip larger future sums */
                } else {
                    i = sum / (8 * sizeof(int));
                    m = 1 << ((unsigned int) sum % (8 * sizeof(int)));
                    if ((counted[i] & m) == 0) {
                        /* count sum if not already discovered */
                        counted[i] |= m;
                        count++;
                    }
                }
            }
        }
    }

    printf("%d\n", count);

    free(counted);
    free(primes);

    return 0;
}

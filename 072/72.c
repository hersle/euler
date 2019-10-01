#include <stdio.h>
#include <string.h>
#include <math.h>

/* 
 * For a denominator 2 <= b <= 1000000, phi(b) gives the number of numbers less
 * than or equal to b that is relatively prime with b, i.e. the number of 
 * fractions a / b where 1 <= a < b is an integer. 
 * 
 * Therefore, the answer is the sum of the totients for each denominator, i.e.
 * phi(2) + phi(3) + phi(4) + ... + phi(1000000).
 */

int main()
{
    int primes[1000001];
    memset(primes, 1, 1000001 * sizeof(int));

    int a, b;
    for (a = 2; a <= 1000000 / 2; a++)
        for (b = 2; a * b <= 1000000; b++)
            primes[a * b] = 0;

    int n_primes = 0;
    for (a = 2; a <= 1000000; a++) {
        if (primes[a]) {
            primes[n_primes] = a;
            n_primes++;
        }
    }

    int totient;
    long long totient_sum = 0;

    int d, i;
    int d_max;

    for (a = 2; a <= 1000000; a++) {
        printf("phi(%d)", a);

        b = a;
        totient = 1;
        d_max = (int) sqrt((double) a);

        for (i = 0; i < n_primes && b > 1; i++) {
            d = primes[i];
            if (d > d_max) {
                totient *= b - 1;
                break;
            }
            if (b % d == 0) {
                totient *= d - 1;
                b /= d;
            }
            while (b % d == 0) {
                totient *= d;
                b /= d;
            }
        }

        printf(" = %d\n", totient);
        totient_sum += (long long) totient;
    }

    printf("totient_sum = %lld\n", totient_sum);

    return 0;
}

#include <math.h>
#include <stdio.h>

int is_prime(int n)
{
    if (n < 2)
        return 0;
    if (n % 2 == 0)
        return n == 2;
    int d;
    int limit = sqrt(n);
    for (d = 3; d <= limit; d += 2) {
        if (n % d == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int i;
    int n = 1;
    int sidelen = 1;
    int primes = 0;
    float ratio;

    do {
        // Increase side length and move to first corner in next spiral
        sidelen += 2;
        n += 2;

        // Generate 4 numbers on the diagonals
        for (i = 0; i < 4; i++) {
            if (is_prime(n))
                primes++;
            n += sidelen - 1;  // move to next corner
        }

        ratio = (float) primes / (float) (sidelen + sidelen - 1);
    } while (ratio >= 0.10);

    printf("side length = %d\n", sidelen);
    return 0;
}

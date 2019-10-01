#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_square(long long n)
{
    long long rt = (long long) sqrt((double) n);
    return rt * rt == n;
}

int main()
{
    long long d;

    long long k;
    long long x;
    long long y;

    long long y_sq;

    long long the_d;
    long long x_max = 0;

    for (d = 2; d <= 1000; d++) {
        if (is_square(d)) continue;

        /* TODO: find a solution */
        /*
        x_sq = 1;
        is_sq = false;
        do {
            x_sq += d;
            if (is_square(x_sq)) {
                // printf("  x^2 = %d\n", x_sq);
                if ((x_sq - 1) % d == 0) {
                    y_sq = (x_sq - 1) / d;
                    is_sq = is_square(y_sq);
                }
            }
        } while (!is_sq);
        printf("d = % 4d: %d - %d * %d = %d\n", d, x_sq, d, y_sq, 1);
        */

        /*
        k = 1;
        while (true) {
            y_sq = 2 * k + k * k * d;
            // printf("1: y_sq = %d\n", y_sq);
            if (is_square(y_sq)) {
                x = 1 + k * d;
                break;
            }
            y_sq = -2 * k + k * k * d;
            // printf("2: y_sq = %d\n", y_sq);
            if (is_square(y_sq)) {
                x = -1 + k * d;
                break;
            }
            k++;
        }
        printf("d = % 4lld: %lld^2 - %lld * %lld = %lld\n", d, x, d, y_sq, 1);

        if (x > x_max) {
            x_max = x;
            the_d = d;
        }
        */

        y = 1;
        while (true) {
            y_sq = y * y;
            y++;
        }
    }

    printf("d = %d\n", the_d);

    return 0;
}

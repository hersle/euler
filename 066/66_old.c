#include <stdio.h>
#include <math.h>

int main()
{
    int d = 2;
    int d_sqrt;

    long long y;
    long long x;
    long long x_sq;

    while (1) {
        d_sqrt = (int) sqrt(d);
        if (d_sqrt * d_sqrt != d) {
            y = 1;
            while (1) {
                x_sq = (long long) (1 + d * y * y);
                x = (long long) (sqrt((double) x_sq));

                //printf("x = %lld, x² = %lld\n", x, x_sq);
                
                if (x * x == x_sq) {
                    printf("d = %4d: %lld² + %d * %lld² = 1\n", d, x, d, y);
                    break;
                }

                y++;
            }
        }

        d++;
    }

    return 0;
}

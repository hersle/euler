#include <stdio.h>
#include <math.h>

/* 
 * A number with n digits is also a n-th power of a gives
 * 1. a^n >= 10^(n-1)
 * 2. a^n < 10^n
 * 
 * (obviously impossible for a >= 10)
 *
 * a^n >= 10^(n-1)
 * lg(a^n) >= lg(10^(n-1))
 * n * lg(a) >= (n - 1) * lg(10)
 * n * lg(a) >= n - 1
 * n * lg(a) - n >= -1
 * n * (lg(a) - 1) >= -1
 * n <= -1 / (lg(a) - 1)  (flipped sign since lg(a) - 1) < 0 since a < 10
 * n <= 1 / (1 - lg(a))

 * a^n < 10^n
 * lg(a^n) < lg(10^n)
 * n * lg(a) < n * lg(10)
 * n * lg(a) < n
 * n * lg(a) - n < 0
 * n * (lg(a) - 1) < 0
 * n > 0  (since (lg(a) - 1) < 0 since a < 10)
 * n >= 1  (since n must be an integer)
 * 
 * 1. n <= 1 / (1 - lg(a))
 * 2. n >= 1
 */

int main()
{
    int count = 0;
    int n, a;
    for (a = 1; a < 10; a++)
        count += (int) (1.0 / (1.0 - log10(a)));
    printf("count = %d\n", count);
    return 0;
}

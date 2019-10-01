#include <stdio.h>

/*
 *       sqrt(n) - a_0
 * B_0 = -------------
 *            d_0
 * 
 *  1         d_0        d_0 * (sqrt(n) + a_0)     sqrt(n) + a_0
 * --- = ------------- = --------------------- = -----------------
 * B_0   sqrt(n) - a_0       n - a_0 * a_0         n - a_0 * a_0
 *                                                 -------------
 *                                                      d_0
 * 
 *       sqrt(n) + a_0   sqrt(n) + a_0 + k * d_1 - k * d_1
 *     = ------------- = ---------------------------------
 *            d_1                      d_1
 * 
 *           sqrt(n) + a_0 - k * d_1       sqrt(n) - (k * d_1 - a_0)
 *     = k + ----------------------- = k + -------------------------
 *                    d_1                             d_1
 * 
 *           sqrt(n) - a_1
 *     = k + -------------
 *                d_1
 * 
 *       sqrt(n) - a_1
 * B_1 = -------------
 *             d_1
 * 
 * a_1 > 0                  B_1 > 0
 * k * d_1 - a_0 > 0        sqrt(n) - a_1 > 0    (d_1 > 0 because B_0 > 0)
 * k * d_1 > a_0            sqrt(n) > a_1
 *     a_0                  n > a_1 * a_1        (can square since a_1 > 0)
 * k > ---
 *     d_1
 */

int get_period(int n, int a0, int d0, int p0)
{
    int d1 = (n - a0 * a0) / d0;

    if (d1 == 1) {
        return p0;
    }

    int k = a0 / d1 + 1;
    int a1 = k * d1 - a0;
    int p1;
    while (n > a1 * a1) {
        p1 = get_period(n, a1, d1, p0 + 1);
        if (p1 != 0) {
            printf("%d ", k);
            return p1;
        }
        k++;
        a1 = k * d1 - a0;
    }

    return 0;
}

int main()
{
    int count = 0;
    int n, a0, p;
    for (n = 1; n <= 10000; n++) {
        printf("n = %d: ", n, a0);
        for (a0 = 1; a0 * a0 < n; a0++) {
            p = get_period(n, a0, 1, 1);
            if (p != 0) {
                if (p % 2 == 1)
                    count++;
                printf("* (period = %d)", p);
                break;
            }
        }
        printf("\n");
    }

    printf("count = %d\n", count);
    return 0;
}

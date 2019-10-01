#include <stdio.h>

int main()
{
    /* a / b */
    
    int a, b, a_res, b_res;
    double d;
    double d_min = 1.0;
    for (b = 2; b <= 1000000; b++) {
        if (b % 7 != 0) {
            a = 3 * b / 7;
            d = (double) (3 * b - 7 * a) / (7 * b);
            if (d < d_min) {
                d_min = d;
                a_res = a;
                b_res = b;
            }
        }
    }

    /* fraction is irreducible */
    printf("a / b = %d / %d\n", a_res, b_res);

    return 0;
}   

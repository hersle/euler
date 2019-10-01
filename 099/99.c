#include <stdio.h>
#include <math.h>

int main()
{
    int line, line_max;
    int base, exponent;
    double prod, prod_max = 0.0;
    for (line = 1; line <= 1000; line++) {
        scanf(" %d,%d", &base, &exponent);
        prod = (double) exponent * log((double) base);
        if (prod > prod_max) {
            prod_max = prod;
            line_max = line;
        }
    }
    printf("%d\n", line_max);
    return 0;
}

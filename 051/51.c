#include <stdio.h>
#include <math.h>

// assumes n > 2
int is_prime(int n)
{
    if (n % 2 == 0)
        return n == 2;
    int d;
    int d_max = (int) (sqrt(n)) + 1;
    for (d = 3; d <= d_max; d += 2)
        if (n % d == 0)
            return 0;
    return 1;
}

int get_family_size(int n)
{
    int digit;
    int tenpow;
    int tenpow_sum = 0;
    for (tenpow = 1; n / tenpow > 0; tenpow *= 10) {
        digit = (n / tenpow) % 10;
        if (digit == 9) {
            tenpow_sum += tenpow;
        }
    }

    int family_size = 0;

    if (tenpow_sum != 0) {
        int i_max = digit == 9 ? 8 : 9;

        printf("n = %d, prime family: ", n);

        int i;
        for (i = 0; i <= i_max; i++) {
            if (is_prime(n)) {
                printf("%d ", n);
                family_size++;
            }
            n -= tenpow_sum;
        }
        printf("\n");
    }

    return family_size;
}

int main()
{
    int n;
    for (n = 1; get_family_size(n) != 8; n += 2);
}

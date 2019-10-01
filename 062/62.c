#include <stdio.h>
#include <string.h>

// assumes a and b have equally many digits
int is_permutation(unsigned long long a, unsigned long long b)
{
    int len = 0;
    unsigned long long div = 1;
    while (div < a) {
        len++;
        div *= 10LL;
    }

    int i;
    int a_digit;
    int b_digit;
    int b_digits_matched[len];
    memset(b_digits_matched, 0, len * sizeof(int));
    while (a > 0) {
        a_digit = a % 10LL;
        div = 1LL;
        for (i = len - 1; i >= 0; i--) {
            if (!b_digits_matched[i]) {
                b_digit = (b / div) % 10LL;
                if (a_digit == b_digit) {
                    b_digits_matched[i] = 1;
                    break;
                }
            }
            div *= 10LL;
        }

        if (i == -1)
            return 0;

        a /= 10LL;
    }

    return 1;
}

int main()
{
    // TODO: build cache of cubes

    unsigned long long n = 1;
    unsigned long long n_min = 1;
    unsigned long long cube;
    unsigned long long cube_max = 10;
    unsigned long long n2;
    unsigned long long cube2;
    unsigned long long n_permutations = 0;
    while (n_permutations != 5) {
        cube = n * n * n;
        if (cube >= cube_max) {
            // TODO: update cache
            n_min = n;
            cube_max *= 10LL;
        }

        printf("n = %lld, cube = %lld, cube_max = %lld\n", n, cube, cube_max);

        // TODO: loop through cache instead
        n2 = n_min;
        cube2 = n2 * n2 * n2;
        n_permutations = 0;
        while (cube2 < cube_max) {
            if (is_permutation(cube, cube2))
                n_permutations++;
            n2++;
            cube2 = n2 * n2 * n2;
        }

        n++;
    }

    printf("cube = %lld\n", cube);
    return 0;
}

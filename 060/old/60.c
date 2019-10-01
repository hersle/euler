#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int is_prime(long long n)
{
    // n is always odd and >= 3
    int d;
    int sqrt_n = sqrt(n);
    for (d = 3; d <= sqrt_n; d += 2) {
        if (n % d == 0)
            return 0;
    }
    return 1;
}

long long concat(int a, int b)
{
    int div;
    for (div = 10; b / div >= 1; div *= 10);
    return (long long) (a * div + b);
}

int sum_set(int *set)
{
    int sum = 0;
    int i;
    for (i = 0; i < 5; i++) {
        sum += set[i];
    }
    return sum;
}

void print_set(int *set)
{
    int i;
    for (i = 0; i < 5; i++) {
        printf("%d ", set[i]);
    }
    printf("\n");
}

int main()
{
    // TODO: if prime does not fit in any set, create a new set

    int n_sets = 0;
    int *sets = NULL;
    int *set;

    int n = 3;
    int i;
    int j;
    while (1) {
        if (is_prime(n)) {
            printf("prime: %d\n", n);
            for (i = 0; i < n_sets; i++) {
                set = &sets[5 * i];
                for (j = 0; j < 5 && set[j] != 0; j++) {
                    if (!is_prime(concat(n, set[j])))
                        break;
                    if (!is_prime(concat(set[j], n)))
                        break;
                }
                if (set[j] == 0) {
                    // Add prime to set
                    set[j] = n;
                    printf("added to set: ");
                    print_set(set);
                    if (j == 4) {
                        print_set(set);
                        printf("%d\n", sum_set(set));
                        return 0;
                    }
                }
            }
            // Create new set
            sets = realloc(sets, 5 * (n_sets + 1) * sizeof(int));
            set = &sets[5 * n_sets];
            set[0] = n;
            set[1] = 0;
            set[2] = 0;
            set[3] = 0;
            set[4] = 0;
            n_sets++;
            printf("created new set: ");
            print_set(set);
        }
        n += 2;
    }
    return 0;
}

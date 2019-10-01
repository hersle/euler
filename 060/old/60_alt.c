#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// TODO: prime cache lookup with binary search
// TODO: find set with one of the splits and add other split to the set

int is_prime(int n)
{
    if (n < 2)
        return 0;
    if (n % 2 == 0)
        return n == 2;
    int d;
    int sqrt_n = sqrt(n);
    for (d = 3; d <= sqrt_n; d += 2) {
        if (n % d == 0)
            return 0;
    }
    return 1;
}

int concat(int a, int b)
{
    int div;
    for (div = 10; b / div >= 1; div *= 10);
    return a * div + b;
}

void print_set(int *set)
{
    int i;
    for (i = 0; i < 4; i++) {
        printf("%d ", set[i]);
    }
    printf("\n");
}

// Return whether or not the set contains the target
int set_contains(int *set, int target)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (set[i] == target)
            return 1;
    }
    return 0;
}

// Return pointer to set with target
int *find_set(int *sets, int n_sets, int target)
{
    int i;
    int j;
    int *set;
    for (i = 0; i < n_sets; i++) {
        set = &sets[4 * i];
        if (set_contains(set, target))
            return set;
    }
    return NULL;
}

void add_to_set(int *set, int n)
{
    printf("trying to add %d to set: ", n);
    print_set(set);
    int i;
    for (i = 0; i < 4; i++) {
        if (!is_prime(concat(n, set[i])) || !is_prime(concat(set[i], n))) {
            return;
        } else if (set[i] == 0) {
            set[i] = n;
            printf("added to set: ");
            print_set(set);
            return;
        }
    }
}

int main()
{
    int n_sets = 0;
    int *sets = NULL;
    int *set;

    int n = 0;
    int div;
    int split1;
    int split2;
    int reverse;
    int i;
    int j;
    int k;
    while (1) {
        if (is_prime(n)) {
            printf("prime: %d\n", n);
            for (div = 10; n / div >= 1; div *= 10) {
                split1 = n / div;
                split2 = n % div;
                reverse = concat(split2, split1);
                if (is_prime(split1) && is_prime(split2) && is_prime(reverse)) {
                    printf("split1 = %d, split2 = %d\n", split1, split2);
                    // TODO: do for split1
                    for (i = 0; i < n_sets; i++) {
                        set = &sets[i * 4];
                        for (j = 0; j < 4 && set[j] != 0; j++) {
                            if (set[j] == split1) {
                                //print_set(set);
                                // TODO: try adding split2 to set
                                // TODO: duplicate when adding
                                for (k = 0; k < 4; k++) {
                                    if (set[k] == 0) {
                                        // TODO: add split2 to set
                                        // TODO: duplicate
                                        /*
                                        set[k] = split2;
                                        printf("added %d to set ", split2);
                                        print_set(set);
                                        break;
                                        */
                                        sets = realloc(sets, (n_sets + 1) * 4 * sizeof(int));
                                    } else if (!is_prime(concat(split2, set[k]))) {
                                        break;
                                    } else if (!is_prime(concat(set[k], split2))) {
                                        break;
                                    }
                                }
                                break;
                            }
                        }
                    }
                    // TODO: do the same for split2

                    // TODO: make new set with split1 and split2
                    sets = realloc(sets, (n_sets + 1) * 4 * sizeof(int));
                    set = &sets[n_sets * 4];
                    set[0] = split1;
                    set[1] = split2;
                    set[2] = 0;
                    set[3] = 0;
                    n_sets++;
                    printf("created new set: ");
                    print_set(set);
                }
            }
        }
        n++;
    }

    return 0;
}

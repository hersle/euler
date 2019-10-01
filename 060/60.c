#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define SETLEN 5

// TODO: could add prime cache

int sets[100000][SETLEN + 1];
int n_sets = 0;

bool is_prime(int n)
{
    if (n < 2) 
        return false;
    if (n % 2 == 0) 
        return n == 2;
    int d;
    int d_max = (int) (sqrt(n)) + 1;
    for (d = 3; d <= d_max; d++) {
        if (n % d == 0)
            return false;
    }
    return true;
}

int concat(int a, int b)
{
    int m = 1;
    while (b / m > 0) 
        m *= 10;
    return a * m + b;
}

void print_set(int setno)
{
    printf("{ ");
    int i;
    for (i = 1; i < sets[setno][0]; i++)
        printf("%d, ", sets[setno][i]);
    printf("%d }", sets[setno][i]);
}

int set_sum(int setno)
{
    int i;
    int sum = 0;
    for (i = 1; i <= sets[setno][0]; i++)
        sum += sets[setno][i];
    return sum;
}

int main()
{
    int s1s2 = 3;
    int s1, s2;
    int div;
    int s2s1;
    bool skip;
    int setno;
    int *set;
    int i;
    bool contains_s1;
    bool contains_s2;
    while (true) {
        if (is_prime(s1s2)) {
            s1 = s1s2;
            s2 = 0;
            div = 1;
            while (s1 >= 10) {
                skip = s1 % 10 == 0;
                s2 += (s1 % 10) * div;
                s1 /= 10;
                div *= 10;

                if (skip)  // s2 cannot start with 0 (illegal number)
                    continue;
                if (!is_prime(s1) || !is_prime(s2))  // both splits must be prime
                    continue;
                s2s1 = concat(s2, s1);
                if (!is_prime(s2s1))  // reverse concatenation must be prime
                    continue;

                printf("%d -> %d %d -> %d\n", s1s2, s1, s2, s2s1);

                // add new set with s1 and s2
                sets[n_sets][0] = 2;
                sets[n_sets][1] = s1;
                sets[n_sets][2] = s2;
                n_sets++;

                // add s2 to sets with s1 in which s2 concatenates 
                // to make primes with all elements
                for (setno = 0; setno < n_sets; setno++) {
                    set = sets[setno];
                    contains_s1 = false;
                    contains_s2 = false;
                    for (i = 1; i <= set[0]; i++) {
                        if (set[i] == s1) {
                            contains_s1 = true;
                        }
                        if (set[i] == s2) {
                            contains_s2 = true;
                            break;
                        }
                    }

                    if (!contains_s1 || contains_s2)  // must contain s1 and not s2
                        continue;

                    // s2 must make primes with all members in set
                    for (i = 1; i <= set[0]; i++) {
                        if (!is_prime(concat(s2, set[i])))
                            break;
                        if (!is_prime(concat(set[i], s2)))
                            break;
                    }
                    if (i != set[0] + 1)
                        continue;

                    printf("add %d to ", s2);
                    print_set(setno);

                    // duplicate set and add s2
                    memcpy(sets[n_sets], set, (set[0] + 1) * sizeof(int));
                    set = sets[n_sets];
                    set[++set[0]] = s2;
                    n_sets++;

                    printf(" -> ");
                    print_set(n_sets - 1);
                    printf("\n");

                    // if a set with SETLEN elements has been made, 
                    // print the sum of its elements and return
                    if (set[0] == SETLEN) {
                        printf("sum of numbers in ");
                        print_set(n_sets - 1);
                        printf(": %d\n", set_sum(n_sets - 1));
                        return 0;
                    }
                }
            }
        }
        s1s2 += 2;  // skip even numbers
    }

    return 0;
}

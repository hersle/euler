#include <stdio.h>

/* A set is a sequence of bits, where bit #n denotes whether n is in the set */

int set_contains(int set, int n)
{
    return (set & (1 << n)) != 0;
}

int different_sets_contain(int set_a, int set_b, int n1, int n2)
{
    return (set_contains(set_a, n1) && set_contains(set_b, n2)) ||
           (set_contains(set_a, n2) && set_contains(set_b, n1));
}

int are_legal_sets(int set_a, int set_b)
{
    int n;
    int a_len = 0;
    int b_len = 0;
    for (n = 0; n < 10; n++) {
        if (set_contains(set_a, n)) a_len++;
        if (set_contains(set_b, n)) b_len++;
    }

    /* Any set that contains 6 or 9 does in practice contain both 6 and 9 */
    if (set_contains(set_a, 6)) set_a |= (1 << 9);
    if (set_contains(set_a, 9)) set_a |= (1 << 6);
    if (set_contains(set_b, 6)) set_b |= (1 << 9);
    if (set_contains(set_b, 9)) set_b |= (1 << 6);

    return a_len == 6 && b_len == 6 &&
           different_sets_contain(set_a, set_b, 0, 1) && 
           different_sets_contain(set_a, set_b, 0, 4) && 
           different_sets_contain(set_a, set_b, 0, 9) && 
           different_sets_contain(set_a, set_b, 1, 6) && 
           different_sets_contain(set_a, set_b, 2, 5) && 
           different_sets_contain(set_a, set_b, 3, 6) && 
           different_sets_contain(set_a, set_b, 4, 9) && 
           different_sets_contain(set_a, set_b, 6, 4) && 
           different_sets_contain(set_a, set_b, 8, 1);
}

void print_sets(int set_a, int set_b)
{
    int n;
    for (n = 0; n < 10; n++)
        if (set_contains(set_a, n)) printf("%d ", n);
    printf("and ");
    for (n = 0; n < 10; n++)
        if (set_contains(set_b, n)) printf("%d ", n);
    putchar('\n');
}

int main()
{
    int set_a, set_b;
    int legal_sets = 0;
    for (set_a = 0; set_a < 1024; set_a++) {
        for (set_b = set_a + 1; set_b < 1024; set_b++) {
            if (are_legal_sets(set_a, set_b)) {
                print_sets(set_a, set_b);
                legal_sets++;
            }
        }
    }
    printf("%d legal sets\n", legal_sets);
    return 0;
}

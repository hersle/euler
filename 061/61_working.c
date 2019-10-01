#include <stdio.h>

#define SETLEN 6  // must be in range [1, 6]

// Minimum and maximum values for n

// Minimum and maximum values for n so that P_n gives 4-digit numbers for all 
// n between the minimum and maximum values, including the minimum and maximum 
// value (easily determined by solving P_n >= 1000 and P_n < 10000 for all n in
// range [3, 8] by hand)
#define p3_n_min 45
#define p3_n_max 140
#define p4_n_min 32
#define p4_n_max 99
#define p5_n_min 26
#define p5_n_max 81
#define p6_n_min 23
#define p6_n_max 70
#define p7_n_min 21
#define p7_n_max 63
#define p8_n_min 19
#define p8_n_max 58

int p3(int n) { return n * (n + 1) / 2; }
int p4(int n) { return n * n; }
int p5(int n) { return n * (3 * n - 1) / 2; }
int p6(int n) { return n * (2 * n - 1); }
int p7(int n) { return n * (5 * n - 3) / 2; }
int p8(int n) { return n * (3 * n - 2); }

int p3s[p3_n_max - p3_n_min + 1];
int p4s[p4_n_max - p4_n_min + 1];
int p5s[p5_n_max - p5_n_min + 1];
int p6s[p6_n_max - p6_n_min + 1];
int p7s[p7_n_max - p7_n_min + 1];
int p8s[p8_n_max - p8_n_min + 1];

int ps_len[6]    = {p3_n_max - p3_n_min + 1, p4_n_max - p4_n_min + 1, p5_n_max - p5_n_min + 1,
                    p6_n_max - p6_n_min + 1, p7_n_max - p7_n_min + 1, p8_n_max - p8_n_min + 1};
int *ps_array[6] = {p3s, p4s, p5s, p6s, p7s, p8s};

void gen(int p(int n), int *ps, int n_min, int n_max)
{
    int i, n;
    for (i = 0, n = n_min; i < n_max - n_min + 1; i++, n++) {
        ps[i] = p(n);
    }
}

int check_set(int set[SETLEN])
{
    int i;
    for (i = 0; i < SETLEN - 1; i++) {
        if (set[i] % 100 != set[i+1] / 100)
            return 0;
    }
    if (set[SETLEN-1] % 100 != set[0] / 100)
        return 0;
    return 1;
}

int set_sum(int set[SETLEN])
{
    int i;
    int sum = 0;
    for (i = 0; i < SETLEN; i++) {
        sum += set[i];
    }
    return sum;
}

void search(int set[SETLEN], int filled[SETLEN], int setlen)
{
    int i;
    if (setlen == SETLEN) {
        for (i = 0; i < SETLEN; i++) {
            printf("%d ", set[i]);
        }
        printf("\n");
        printf("sum: %d\n", set_sum(set));
        return;
    }

    int j;
    for (i = 0; i < SETLEN; i++) {
        if (!filled[i]) {
            filled[i] = 1;
            for (j = 0; j < ps_len[i]; j++) {
                if (setlen == 0 || ps_array[i][j] / 100 == set[setlen-1] % 100) {
                    if (setlen == SETLEN - 1 && ps_array[i][j] % 100 != set[0] / 100)
                        continue;
                    set[setlen] = ps_array[i][j];
                    search(set, filled, setlen + 1);
                }
            }
            filled[i] = 0;
        }
    }


}

int main()
{
    gen(p3, p3s, p3_n_min, p3_n_max);
    gen(p4, p4s, p4_n_min, p4_n_max);
    gen(p5, p5s, p5_n_min, p5_n_max);
    gen(p6, p6s, p6_n_min, p6_n_max);
    gen(p7, p7s, p7_n_min, p7_n_max);
    gen(p8, p8s, p8_n_min, p8_n_max);

    int set[SETLEN];
    int filled[SETLEN] = {0, 0, 0};
    int setlen = 0;
    search(set, filled, setlen);

    /*
    int i, j;
    for (i = 0; i < 6; i++) {
        // ...
        for (j = 0; j < n_max[i] - n_min[i] + 1; j++) {
            printf("%d ", ps_array[i][j]);
        }
        printf("\n");
    }
    */

    /*
    int n;
    for (n = 19; n <= 500; n++) {
        printf("n = %6d ", n);
        printf("%6d ", triangle(n));
        printf("%6d ", square(n));
        printf("%6d ", pentagonal(n));
        printf("%6d ", hexagonal(n));
        printf("%6d ", heptagonal(n));
        printf("%6d ", octagonal(n));
        printf("\n");
    }
    */

    return 0;

    int i;
    for (i = 0; i < p3_n_max - p3_n_min + 1; i++)
        printf("%d\n", p3s[i]);

}

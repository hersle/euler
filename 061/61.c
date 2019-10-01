#include <stdio.h>

#define SETLEN 6  // must be in range [1, 6]

// Minimum and maximum values for n so that P_n gives 4-digit numbers for all 
// n between the minimum and maximum values, including the minimum and maximum 
// value (easily determined by solving P_n >= 1000 and P_n < 10000 for all n in
// range [3, 8] by hand)

#define P3_N_MIN 45
#define P3_N_MAX 140
#define P4_N_MIN 32
#define P4_N_MAX 99
#define P5_N_MIN 26
#define P5_N_MAX 81
#define P6_N_MIN 23
#define P6_N_MAX 70
#define P7_N_MIN 21
#define P7_N_MAX 63
#define P8_N_MIN 19
#define P8_N_MAX 58
#define P3_LEN P3_N_MAX - P3_N_MIN + 1
#define P4_LEN P4_N_MAX - P4_N_MIN + 1
#define P5_LEN P5_N_MAX - P5_N_MIN + 1
#define P6_LEN P6_N_MAX - P6_N_MIN + 1
#define P7_LEN P7_N_MAX - P7_N_MIN + 1
#define P8_LEN P8_N_MAX - P8_N_MIN + 1

int p_lens[6] = {P3_LEN, P4_LEN, P5_LEN, P6_LEN, P7_LEN, P8_LEN};
int p3[P3_LEN], p4[P4_LEN], p5[P5_LEN], p6[P6_LEN], p7[P7_LEN], p8[P8_LEN];
int *p_seqs[6] = {p3, p4, p5, p6, p7, p8};

void search(int set[SETLEN], int in_set[SETLEN], int setlen)
{
    int i;
    if (setlen == SETLEN) {
        int sum = 0;
        for (i = 0; i < SETLEN - 1; i++) {
            printf("%d + ", set[i]);
            sum += set[i];
        }
        sum += set[SETLEN-1];
        printf("%d = %d\n", set[SETLEN-1], sum);
        return;
    }

    int j;
    for (i = 0; i < SETLEN; i++) {
        if (!in_set[i]) {
            in_set[i] = 1;
            for (j = 0; j < p_lens[i]; j++) {
                if (setlen == 0 || (p_seqs[i][j] / 100 == set[setlen-1] % 100 && (setlen != SETLEN - 1 || p_seqs[i][j] % 100 == set[0] / 100))) {
                    set[setlen] = p_seqs[i][j];
                    search(set, in_set, setlen + 1);
                }
            }
            in_set[i] = 0;
        }
    }
}

int main()
{
    int i, n;
    for (i = 0, n = P3_N_MIN; n <= P3_N_MAX; i++, n++)
        p3[i] = n * (n + 1) / 2;
    for (i = 0, n = P4_N_MIN; n <= P4_N_MAX; i++, n++)
        p4[i] = n * n;
    for (i = 0, n = P5_N_MIN; n <= P5_N_MAX; i++, n++)
        p5[i] = n * (3 * n - 1) / 2;
    for (i = 0, n = P6_N_MIN; n <= P6_N_MAX; i++, n++)
        p6[i] = n * (2 * n - 1);
    for (i = 0, n = P7_N_MIN; n <= P7_N_MAX; i++, n++)
        p7[i] = n * (5 * n - 3) / 2;
    for (i = 0, n = P8_N_MIN; n <= P8_N_MAX; i++, n++)
        p8[i] = n * (3 * n - 2);

    int set[SETLEN];
    int in_set[SETLEN] = {0};
    int setlen = 0;
    search(set, in_set, setlen);

    return 0;

}

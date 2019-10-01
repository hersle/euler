#include <stdio.h>
#include <limits.h>

#define K_MAX 12000
#define PROD_EXCEEDED_IMMEDIATELY -1
#define NO_PRODSUM_EXISTS -2

int numbers[K_MAX];

void print_numbers(int k)
{
    int i;
    int sum = 0;
    int prod = 1;
    for (i = 0; i < k; i++) {
        printf("%d ", numbers[i]);
        sum += numbers[i];
        prod *= numbers[i];
    }
    printf("-> (%d, %d)\n", prod, sum);
}

int minprodsum(int prod, int sum, int n_last, int i, int k)
{
    if (prod > sum && sum != 0)
        return PROD_EXCEEDED_IMMEDIATELY;
    else if (i == k)
        return prod == sum ? prod : NO_PRODSUM_EXISTS;

    int n = i == k - 2 && prod == 1 ? 2 : n_last;

    int best = INT_MAX;
    int prod_new = prod * n;
    int sum_new = sum + n;
    numbers[i] = n;

    int res = minprodsum(prod_new, sum_new, n, i + 1, k);

    if (res == PROD_EXCEEDED_IMMEDIATELY)
        return PROD_EXCEEDED_IMMEDIATELY;

    while (res != PROD_EXCEEDED_IMMEDIATELY) {
        if (res >= 0 && res < best)
            best = res;
        n++;
        numbers[i] = n;
        prod_new = prod * n;
        sum_new = sum + n;
        res = minprodsum(prod_new, sum_new, n, i + 1, k);
    }

    return best;
}

int main()
{
    int results[K_MAX + 1];

    int k;
    for (k = 2; k <= K_MAX; k++) {
        results[k] = minprodsum(1, 0, 1, 0, k);
        printf("k = %d: %d\n", k, results[k]);
    }

    int len = K_MAX + 1;
    int i, j;

    /* Remove duplicate results */
    for (i = 2; i < len; i++) {
        for (j = i + 1; j < len; j++) {
            if (results[i] == results[j]) {
                results[j] = results[len-1];
                len--;
                j--;  /* re-check moved number */
            }
        }
    }

    int sum = 0;
    for (i = 2; i < len; i++) {
        printf("%d\n", results[i]);
        sum += results[i];
    }

    printf("sum = %d\n", sum);

    return 0;
}

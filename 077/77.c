#include <stdio.h>
#include <string.h>

#define N 71  /* solution is known after testing different values of N */

int n_primes = 0;
int primes[N];

int saved_for_sum_target[N][N] = {};
int counts_saved[N][N];

int count(int sum_target, int sum, int i)
{
    if (sum == sum_target)
        return 1;
    if (i == n_primes)
        return 0;
    if (saved_for_sum_target[sum][i] == sum_target)
        return counts_saved[sum][i];

    int k;
    int c = 0;

    for (k = 0; k <= (sum_target - sum) / primes[i]; k++)
        c += count(sum_target, sum + k * primes[i], i + 1);
    
    counts_saved[sum][i] = c;
    saved_for_sum_target[sum][i] = sum_target;
    return c;
}

int main()
{
    memset(primes, 1, N * sizeof(int));

    int a, b;
    for (a = 2; a < N; a++)
        if (primes[a]) {
            for (b = 2; a * b < N; b++)
                primes[a * b] = 0;
            primes[n_primes] = a;
            n_primes++;
        }

    int c = 0;
    int sum_target;
    for (sum_target = 1; sum_target <= N && c <= 5000; sum_target++) {
        c = count(sum_target, 0, 0);
        printf("sum_target = %d, count = %d\n", sum_target, c);
    }

    return 0;
}

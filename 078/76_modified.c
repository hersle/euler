#include <stdio.h>
#include <string.h>

#define N 100

int counts_saved[N][N];

int count(int sum, int n)
{
    if (sum == N)
        return 1;
    if (n == N)
        return 0;
    if (counts_saved[sum][n] != -1)
        return counts_saved[sum][n];

    int k;
    int c = 0;

    for (k = 0; k <= (N - sum) / n; k++)
        c += count(sum + k * n, n + 1);
    
    counts_saved[sum][n] = c;
    return c;
}

int main()
{
    memset(counts_saved, -1, N * N * sizeof(int));
    printf("count = %d\n", count(0, 1));
    return 0;
}

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

    int k;
    int c = 0;

    for (k = 0; k <= (N - sum) / n; k++)
        c += count(sum + k * n, n + 1);
    
    return c;
}

int main()
{
    printf("count = %d\n", count(0, 1));
    return 0;
}

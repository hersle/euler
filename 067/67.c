#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

int main()
{
    int row, col;
    int sums[100][100];

    for (row = 0; row < 100; row++)
        for (col = 0; col <= row; col++)
            scanf("%d", &sums[row][col]);

    for (row = 98; row >= 0; row--)
        for (col = 0; col <= row; col++)
            sums[row][col] += max(sums[row+1][col], sums[row+1][col+1]);

    printf("%d\n", sums[0][0]);

    return 0;
}

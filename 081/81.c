#include <stdio.h>
#include <limits.h>

#define MATRIX_WIDTH 80
#define MATRIX_HEIGHT 80

int matrix[MATRIX_HEIGHT][MATRIX_WIDTH];
int minsums[MATRIX_HEIGHT][MATRIX_WIDTH];

int min2(int a, int b)
{
    return a < b ? a : b;
}

int minsum(int x, int y)
{
    if (minsums[y][x] != -1)
        return minsums[y][x];
    if (x == 0 && y == 0)
        return matrix[0][0];

    int sum1 = x > 0 ? minsum(x - 1, y) : INT_MAX;
    int sum2 = y > 0 ? minsum(x, y - 1) : INT_MAX;

    int sum = matrix[y][x] + min2(sum1, sum2);
    minsums[y][x] = sum;
    return sum;
}

int main()
{
    int x, y;
    for (y = 0; y < MATRIX_HEIGHT; y++) {
        scanf("%d", &matrix[y][0]);
        minsums[y][0] = -1;
        for (x = 1; x < MATRIX_WIDTH; x++) {
            scanf(",%d", &matrix[y][x]);
            minsums[y][x] = -1;
        }
    }

    printf("%d\n", minsum(MATRIX_WIDTH - 1, MATRIX_HEIGHT - 1));

    return 0;
}

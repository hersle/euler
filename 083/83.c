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

int min4(int a, int b, int c, int d)
{
    return min2(a, min2(b, min2(c, d)));
}

int minsum(int x, int y, int sum)
{
    sum += matrix[y][x];

    if (sum >= minsums[y][x] || sum >= minsums[0][0])
        return INT_MAX;

    minsums[y][x] = sum;

    if (x == 0 && y == 0)
        return sum;

    int sum1 = x > 0 ? minsum(x - 1, y, sum) : INT_MAX;
    int sum2 = y > 0 ? minsum(x, y - 1, sum) : INT_MAX;
    int sum3 = x < MATRIX_WIDTH - 1 ? minsum(x + 1, y, sum) : INT_MAX;
    int sum4 = y < MATRIX_HEIGHT - 1 ? minsum(x, y + 1, sum) : INT_MAX;

    return min4(sum1, sum2, sum3, sum4);
}

int main()
{
    int x, y;
    for (y = 0; y < MATRIX_HEIGHT; y++) {
        scanf("%d", &matrix[y][0]);
        minsums[y][0] = INT_MAX;
        for (x = 1; x < MATRIX_WIDTH; x++) {
            scanf(",%d", &matrix[y][x]);
            minsums[y][x] = INT_MAX;
        }
        scanf("\n");
    }

    printf("%d\n", minsum(MATRIX_WIDTH - 1, MATRIX_HEIGHT - 1, 0));

    return 0;
}

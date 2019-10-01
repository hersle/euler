#include <stdio.h>
#include <limits.h>

#define MATRIX_WIDTH 80
#define MATRIX_HEIGHT 80

int matrix[MATRIX_HEIGHT][MATRIX_WIDTH];
int minsums[MATRIX_HEIGHT][MATRIX_WIDTH];

int sum_best = INT_MAX;

int min2(int a, int b)
{
    return a < b ? a : b;
}

int min3(int a, int b, int c)
{
    return min2(a, min2(b, c));
}

int minsum(int x, int y, int sum)
{
    sum += matrix[y][x];

    if (sum >= minsums[y][x] || sum >= sum_best)
        return INT_MAX;

    minsums[y][x] = sum;

    if (x == 0) {
        sum_best = min2(sum_best, sum);
        return sum;
    }

    int sum1 = x > 0 ? minsum(x - 1, y, sum) : INT_MAX;
    int sum2 = y > 0 ? minsum(x, y - 1, sum) : INT_MAX;
    int sum3 = y < MATRIX_HEIGHT - 1 ? minsum(x, y + 1, sum) : INT_MAX;

    return min3(sum1, sum2, sum3);
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

    /* ugly since using slightly modified version of solution for 83 */
    for (y = 0; y < MATRIX_HEIGHT; y++) 
        minsum(MATRIX_WIDTH - 1, y, 0);
    printf("%d\n", sum_best);

    return 0;
}

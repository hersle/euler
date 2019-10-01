#include <stdio.h>

#define SUM_MAX 1000

int saved_for_sum_target[SUM_MAX][SUM_MAX] = {};
int counts_saved[SUM_MAX][SUM_MAX];

int count(int sum_target, int sum, int pile_size)
{
    if (sum == sum_target)
        return 1;
    if (pile_size > sum_target)
        return 0;
    /* TODO: return saved */
    if (saved_for_sum_target[sum][pile_size] == sum_target)
        return counts_saved[sum][pile_size];

    int k;
    int c = 0;

    for (k = 0; k <= (sum_target - sum) / pile_size; k++)
        c += count(sum_target, sum + k * pile_size, pile_size + 1);
        c = c % 1000000;

    /* TODO: save */
    counts_saved[sum][pile_size] = c;
    saved_for_sum_target[sum][pile_size] = sum_target;
    return c;
}

int main()
{
    int c = 1;
    int sum_target;
    for (sum_target = 1; sum_target <= SUM_MAX && c != 0; sum_target++) {
        c = count(sum_target, 0, 1);
        printf("sum_target = %d, count = %d\n", sum_target, c);
    }
    return 0;
}

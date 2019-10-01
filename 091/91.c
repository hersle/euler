#include <stdio.h>

int is_right_triangle(int a_sq, int b_sq, int c_sq)
{
    return a_sq + b_sq == c_sq || a_sq + c_sq == b_sq || b_sq + c_sq == a_sq;
}

int main()
{
    int count = 0;
    int n1, n2, x1, y1, x2, y2, a_sq, b_sq, c_sq;
    for (n1 = 1; n1 < 51 * 51; n1++) {
        x1 = n1 % 51;
        y1 = n1 / 51;
        a_sq = x1 * x1 + y1 * y1;
        for (n2 = n1 + 1; n2 < 51 * 51; n2++) {
            x2 = n2 % 51;
            y2 = n2 / 51;
            b_sq = x2 * x2 + y2 * y2;
            c_sq = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
            if (is_right_triangle(a_sq, b_sq, c_sq)) {
                printf("(%d, %d) & (%d, %d)\n", x1, y1, x2, y2);
                count++;
            }
        }
    }
    printf("count = %d\n", count);
    return 0;
}

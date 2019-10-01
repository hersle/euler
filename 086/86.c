#include <stdio.h>
#include <math.h>

int main()
{
    int w, d, h;
    int dist_sq, dist_fl;
    int count = 0;

    for (w = 1; count < 1000000; w++) {
        for (d = 1; d <= w; d++) {
            for (h = d; h <= w; h++) {
                dist_sq = w * w + (h + d) * (h + d);
                dist_fl = (int) sqrt((double) dist_sq);
                if (dist_fl * dist_fl == dist_sq) count++;
            }
        }
        printf("%d\n", count);
    }

    printf("%d\n", w - 1);

    return 0;
}

#include <stdio.h>
#include <math.h>

int main()
{
    int w = 1;
    int h;
    while (1) {
        h = (int) ((-1.0 + sqrt(1.0 + 32000000.0 / ())) / 2);
    }



    int width = 1;
    int height = 1;

    int n_rectangles;

    while (1) {
        for (height = 1; height <= width; height++) {
            n_rectangles = (width + 1) * width / 2 * (height + 1) * height / 2;
            printf("%dx%d = %d: %d\n", width, height, width * height, n_rectangles);
            if (n_rectangles > 2100000)
                return 0;
        }
        width++;
    }
}

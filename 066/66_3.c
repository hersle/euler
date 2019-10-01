#include <stdio.h>
#include <math.h>

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	int D;
	int d;
	int x1, y1, x2, y2;
	int isqrt;

	for (D = 1; D <= 20; D++) {
		isqrt = (int) sqrt((double) D);
		if (isqrt * isqrt != D) {
			printf("d = %d\n", D);
			x1 = x2 = isqrt, y1 = y2 = 1;
			while (x1 < 1000000) {
				printf("sqrt(%d) = %lf\n", D, (double) x1 / y1);

				// printf("%d^2 + %d * %d^2 = %d\n", x1, D, y1, x1 * x1 - D * y1 * y1);
				// printf("x = %d, y = %d\n", x1, y1);
				x1 = isqrt * x2 + D * y2;
				y1 = x2 + isqrt * y2;
				d = gcd(x1, y1);
				x1 = x1 / d;
				y1 = y1 / d;
				x2 = x1;
				y2 = y1;
			}
			// printf("%d^2 + %d * %d^2 = %d\n", x1, D, y1, 1);
		}
	}

	return 0;
}

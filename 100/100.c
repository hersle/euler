#include <stdio.h>
#include <math.h>

#define EPS 1e-8

int main() {
	long long b;
	double n;
	long long nn;

	b = 1;
	while (1) {
		n = (1.0 + sqrt(1.0 + 8.0 * ((double) b * b - b))) / 2;
		if (fabs(n - floor(n)) < EPS) {
			nn = (long long) n;
			if (2 * b * (b - 1) == nn * (nn - 1)) {
				printf("n = %lf, b = %lld\n", n, b);
			}
		}
		b++;
	}

	return 0;
}

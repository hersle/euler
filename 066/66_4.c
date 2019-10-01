#include <stdio.h>
#include <math.h>

void func(unsigned long long n, unsigned long long a, unsigned long long b, unsigned long long c, unsigned long long *x, unsigned long long *y, unsigned long long N) {
	int i;
	i = (a + (unsigned long long) sqrt((double) b)) / c;
	if (n == N) {
		*x = i;
		*y = 1;
	} else {
		a = i * c - a;
		c = (b - a * a) / c;
		func(n + 1, a, b, c, x, y, N);
		*x = *x * i + *y;
		*y = (*x - *y) / i;
	}
}

int main() {
	unsigned long long D, N, x, y;

	for (D = 1; D <= 1000; D++) {
		if (((int) sqrt(D)) * ((int) sqrt(D)) == D)
			continue;
		N = 1;
		do {
			func(0, 0, D, 1, &x, &y, N);
			printf("%lld^2 + %lld * %lld^2 = %lld\n", x, D, y, x * x - D * y * y);
			N++;
		} while (x * x - D * y * y != 1);
		// printf("%lld^2 + %lld * %lld^2 = %lld\n", x, D, y, x * x - D * y * y);
	}

	return 0;
}

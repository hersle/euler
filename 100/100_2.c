#include <stdio.h>
#include <math.h>

long long isqrt(long long n) {
	return (long long) sqrt((double) n);
}

int main() {
	long long b, n;
	long long k1, k2;

	k1 = k2 = 1;
	do {
		if (k1 % 2 == 1) {
			b = (2 + isqrt(2 * (1 + k1 * k1))) / 4;
			n = (1 + isqrt(1 + 8 * (b * b - b))) / 2;
			printf("n = %lld, b = %lld\n", n, b);
		}
		k1 = k1 + 2 * k2;
		k2 = k1 - k2;
	} while (1);
}

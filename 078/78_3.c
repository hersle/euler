#include <stdio.h>

#define MOD 1000000
#define N 1000000

int p[N];

int pent(int n) {
	return n * (3 * n - 1) / 2;
}

int main() {
	int n, k, sign;

	p[0] = 1;
	for (n = 1; n < N; n++) {
		p[n] = 0;
		for (k = 1; pent(k) <= n; k = k > 0 ? -k : -k + 1) {
			sign = k * k % 2 == 1 ? +1 : -1;
			p[n] = (p[n] + sign * p[n-pent(k)] + MOD) % MOD;
		}
		if (p[n] == 0)
			break;
	}
	printf("p(%d) = %d\n", n, p[n]);

	return 0;
}

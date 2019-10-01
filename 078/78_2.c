#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define N 10000

int p[N][N];

int main() {
	size_t lo, hi;
	int n, m, k;

	for (m = 0; m < N; m++)
		p[0][m] = 1;

	for (n = 1; n < N; n += 1) {
		p[n][1] = 1;
		for (m = 2; m <= n; m++) {
			p[n][m] = 0;
			for (k = 1; k <= m; k++) {
				p[n][m] += 2 * k > n ? p[n-k][n-k] : p[n-k][k];
				p[n][m] %= 1000000;
			}
		}
		printf("p(%d) = %d\n", n, p[n][n]);
		if (p[n][n] == 0)
			break;
	}

	return 0;
}

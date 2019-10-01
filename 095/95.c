#include <stdio.h>
#include <string.h>
#include <limits.h>

int divsum[1000001];
int startn[1000001];

int main() {
	int n, d, n0, n1;
	int sum;
	int chainlen, maxlen;
	int chainmin, min;

	divsum[0] = divsum[1] = 0;
	for (n = 2; n <= 1000000; n++) {
		sum = 1;
		for (d = 2; d * d < n; d++) {
			if (n % d == 0) {
				sum += d + n / d;
			}
		}
		if (n % d == 0 && d < n)
			sum += d;
		divsum[n] = sum;
	}

	memset(startn, -1, 1000001 * sizeof(int));

	maxlen = 0;

	n = 0;
	while (n <= 1000000) {
		n0 = n;
		do {
			startn[n] = n0;
			n = divsum[n];
		} while (n <= 1000000 && startn[n] != n0);
		if (n <= 1000000) {
			n1 = n;
			chainlen = 1;
			chainmin = INT_MAX;
			do {
				if (n < chainmin)
					chainmin = n;
				chainlen++;
				n = divsum[n];
			} while (n != n1);

			if (chainlen > maxlen) {
				maxlen = chainlen;
				min = chainmin;
			} else if (chainlen == maxlen && chainmin < min) {
				min = chainmin;
			}
		}
		n = n0 + 1;
	}

	printf("%d\n", min);

	return 0;
}

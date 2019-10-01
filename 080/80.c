#include <stdio.h>
#include <string.h>

#define N 100
#define D 101

void printnum(int *n) {
	int i;
	for (i = 0; i < D; i++) {
		putchar('0' + n[i]);
	}
}

int skip(int n0) {
	return n0 == 1 || n0 == 4 || n0 == 9 || n0 == 16 || n0 == 25 || 
	       n0 == 36 || n0 == 49 || n0 == 64 || n0 == 81 || n0 == 100;
}

int main() {
	int n[2 * D - 1], rt[D], sq[2 * D - 1];
	int d0, d1, d2;
	int d, i, j, k;
	int toobig;
	int n0;
	int sum;

	sum = 0;
	memset(n, 0, (2 * D - 1) * sizeof(int));

	for (n0 = 1; n0 <= N; n0++) {
		if (skip(n0))
			continue;

		n[0] = (n0 / 100) % 10;
		n[1] = (n0 / 10) % 10;
		n[2] = (n0 / 1) % 10;

		memset(rt, 0, D * sizeof(int));


		for (i = 0; i < D; i++) {
			toobig = 1;
			for (d = 9; d >= 0 && toobig; d--) {
				rt[i] = d;

				// square
				memset(sq, 0, (2 * D - 1) * sizeof(int));
				for (j = 0; j < D; j++) {
					for (k = 0; k < D; k++) {
						sq[j+k] += rt[j] * rt[k];
					}
				}
				for (j = 2 * D - 2; j > 0; j--) {
					sq[j-1] += sq[j] / 10;
					sq[j] %= 10;
				}

				// compare square
				j = 0;
				while (j < 2 * D - 1 && sq[j] == n[j])
					j++;
				toobig = j < 2 * D - 1 && sq[j] > n[j];
			}
		}

		j = 0;
		while (rt[j] == 0)
			j++;
		for (i = j; i < j + 100; i++) {
			sum += rt[i];
		}

		printf("sqrt(%d) = ", n0);
		printnum(rt);
		putchar('\n');
	}
	
	printf("sum = %d\n", sum);

	return 0;
}

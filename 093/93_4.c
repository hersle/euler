#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>

int oper[3];

float vals[5][1000000];
int used[5][1000000];
int nvals[5];
int added[4000];

float evalexpr(float expr[4], int len) {
	int i;
	float sum, prod;

	sum = 0.0;
	prod = expr[0];
	for (i = 0; i < len - 1; i++) {
		if (oper[i] == 0) {
			sum += prod;
			prod = +expr[i+1];
		} else if (oper[i] == 1) {
			sum += prod;
			prod = -expr[i+1];
		} else if (oper[i] == 2) {
			prod *= expr[i+1];
		} else {
			prod /= expr[i+1];
		}
	}
	sum += prod;
	return sum;
}

void printexpr(float expr[4], int len) {
	int i;
	for (i = 0; i < len - 1; i++) {
		printf("%.1f %d ", expr[i], oper[i]);
	}
	printf("%.1f = %.1f\n", expr[i], evalexpr(expr, len));
}

void func(float expr[4], int n, int i, int u, int N) {
	int s, j;
	float val;

	if (n == N) {
		val = evalexpr(expr, i);
		if (fabsf(val - roundf(val)) <= 1e-6) {
			// printf("N = %d: ", N);
			// printexpr(expr, i);
			vals[N][nvals[N]] = val;
			used[N][nvals[N]] = u;
			nvals[N]++;
			// assert(nvals[N] < 1000000);
		}
		return;
	}

	for (s = 1; s < N && n + s <= N; s++) {
		for (j = 0; j < nvals[s]; j++) {
			if ((u & used[s][j]) == 0) {
				expr[i] = vals[s][j];
				func(expr, n + s, i + 1, u | used[s][j], N);
			}
		}
	}
}

void printvals(int N) {
	int i;
	for (i = 0; i < nvals[N]; i++) {
		printf("%.1f ", vals[N][i]);
	}
	printf("\n");
}

int main() {
	int N, i;
	int a, b, c, d;
	float expr[4];

	for (a = 0; a < 10; a++) {
		for (b = a + 1; b < 10; b++) {
			for (c = b + 1; c < 10; c++) {
				for (d = c + 1; d < 10; d++) {
					vals[1][0] = (float) a;
					vals[1][1] = (float) b;
					vals[1][2] = (float) c;
					vals[1][3] = (float) d;
					used[1][0] = 1;
					used[1][1] = 2;
					used[1][2] = 4;
					used[1][3] = 8;
					nvals[1] = 4;
					nvals[2] = nvals[3] = nvals[4] = 0;

					// printf("N = 2\n");
					for (oper[0] = 0; oper[0] < 4; oper[0]++) {
						func(expr, 0, 0, 0, 2);
					}
					// printf("N = 3\n");
					for (oper[0] = 0; oper[0] < 4; oper[0]++) {
						for (oper[1] = 0; oper[1] < 4; oper[1]++) {
							func(expr, 0, 0, 0, 3);
						}
					}
					// printf("N = 4\n");
					for (oper[0] = 0; oper[0] < 4; oper[0]++) {
						for (oper[1] = 0; oper[1] < 4; oper[1]++) {
							for (oper[2] = 0; oper[2] < 4; oper[2]++) {
								func(expr, 0, 0, 0, 4);
							}
						}
					}

					memset(added, 0, 4000 * sizeof(int));
					for (i = 0; i < nvals[4]; i++) {
						if (vals[4][i] < 4000.0f && vals[4][i] > 0.0f)
							added[(int) vals[4][i]] = 1;
					}
					i = 0;
					while(added[i+1])
						i++;
					printf("%d %d,%d,%d,%d\n", i, a, b, c, d);
				}
			}
		}
	}
	return 0;
}

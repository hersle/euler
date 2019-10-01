#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX 9
#define MAXVAL ((MAX)*(MAX-1)*(MAX-2)*(MAX-3))

int oper[3];
float vals[5][1000000];
int used[5][1000000];
int nvals[5];
int added[MAXVAL+1];

int isint(float f) {
	return fabsf(f - roundf(f)) < 1e-6;
}

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

void func(float expr[4], int n, int i, int u, int N) {
	int s, j;
	float val;

	for (s = 1; s < N && n + s <= N; s++) {
		for (j = 0; j < nvals[s]; j++) {
			if ((u & used[s][j]) == 0) {
				expr[i] = vals[s][j];
				if (n + s == N) {
					val = evalexpr(expr, i + 1);
					if (N < 4 || (isnormal(val) && val > 0.0f && isint(val))) {
						vals[N][nvals[N]] = val;
						used[N][nvals[N]] = u | used[s][j];
						nvals[N]++;
						if (N == 4) {
							added[(int) val] = 1;
						}
					}
				} else {
					for (oper[i] = 0; oper[i] < 4; oper[i]++) {
						func(expr, n + s, i + 1, u | used[s][j], N);
					}
				}
			}
		}
	}
}

int main() {
	int i, a, b, c, d;
	float expr[4];

	used[1][0] = (1 << 0);
	used[1][1] = (1 << 1);
	used[1][2] = (1 << 2);
	used[1][3] = (1 << 3);
	nvals[1] = 4;
	for (a = 0; a <= MAX; a++) {
		vals[1][0] = (float) a;
		for (b = a + 1; b <= MAX; b++) {
			vals[1][1] = (float) b;
			for (c = b + 1; c <= MAX; c++) {
				vals[1][2] = (float) c;
				for (d = c + 1; d <= MAX; d++) {
					vals[1][3] = (float) d;
					nvals[2] = nvals[3] = nvals[4] = 0;
					memset(added, 0, (MAXVAL + 1) * sizeof(int));

					func(expr, 0, 0, 0, 2);
					func(expr, 0, 0, 0, 3);
					func(expr, 0, 0, 0, 4);

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

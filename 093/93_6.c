#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>

struct frac {
	int a, b;  /* a / b */
};

int oper[3];
struct frac vals[5][1000000];
int used[5][1000000];
int nvals[5];
int added[4000];

int gcd(int a, int b) {
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	if (b > a)
		return gcd(b, a);
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

struct frac createfrac(int a, int b) {
	struct frac f;
	f.a = a;
	f.b = b;
	return f;
}

struct frac fracred(struct frac f) {
	int d;
	d = gcd(f.a, f.b);
	assert(d >= 1);
	return createfrac(f.a / d, f.b / d);
}

struct frac fracadd(struct frac f1, struct frac f2) {
	return fracred(createfrac(f1.a * f2.b + f2.a * f1.b, f1.b * f2.b));
}

struct frac fracsub(struct frac f1, struct frac f2) {
	return fracred(createfrac(f1.a * f2.b - f2.a * f1.b, f1.b * f2.b));
}

struct frac fracmult(struct frac f1, struct frac f2) {
	return fracred(createfrac(f1.a * f2.a, f1.b * f2.b));
}

struct frac fracdiv(struct frac f1, struct frac f2) {
	return fracred(createfrac(f1.a * f2.b, f2.a * f1.b));
}

int fracispos(struct frac f) {
	return (f.a > 0 && f.b > 0) || (f.a < 0 && f.b < 0);
}

int fracisint(struct frac f) {
	return f.a % f.b == 0;
}

struct frac evalexpr(struct frac expr[4], int len) {
	int i;
	struct frac sum, prod;

	sum = createfrac(0, 1);
	prod = expr[0];
	for (i = 0; i < len - 1; i++) {
		if (oper[i] == 0) {
			sum = fracadd(sum, prod);
			prod = expr[i+1];
		} else if (oper[i] == 1) {
			sum = fracadd(sum, prod);
			prod = fracmult(createfrac(-1, 1), expr[i+1]);
		} else if (oper[i] == 2) {
			prod = fracmult(prod, expr[i+1]);
		} else {
			prod = fracdiv(prod, expr[i+1]);
		}
	}
	sum = fracadd(sum, prod);
	return sum;
}

void func(struct frac expr[4], int n, int i, int u, int N) {
	int s, j;
	struct frac val;

	for (s = 1; s < N && n + s <= N; s++) {
		for (j = 0; j < nvals[s]; j++) {
			if ((u & used[s][j]) == 0) {
				expr[i] = vals[s][j];
				if (n + s == N) {
					val = evalexpr(expr, i + 1);
					vals[N][nvals[N]] = val;
					used[N][nvals[N]] = u | used[s][j];
					nvals[N]++;
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
	int i;
	int a, b, c, d;
	struct frac expr[4];

	used[1][0] = 1;
	used[1][1] = 2;
	used[1][2] = 4;
	used[1][3] = 8;
	nvals[1] = 4;
	for (a = 0; a < 10; a++) {
		vals[1][0] = createfrac(a, 1);
		for (b = a + 1; b < 10; b++) {
			vals[1][1] = createfrac(b, 1);
			for (c = b + 1; c < 10; c++) {
				vals[1][2] = createfrac(c, 1);
				for (d = c + 1; d < 10; d++) {
					printf("a, b, c, d = %d, %d, %d, %d\n", a, b, c, d);
					vals[1][3] = createfrac(d, 1);
					nvals[2] = nvals[3] = nvals[4] = 0;

					func(expr, 0, 0, 0, 2);
					func(expr, 0, 0, 0, 3);
					func(expr, 0, 0, 0, 4);

					memset(added, 0, 4000 * sizeof(int));
					for (i = 0; i < nvals[4]; i++) {
						if (fracispos(vals[4][i]) && fracisint(vals[4][i])) {
							assert(vals[4][i].b == 1);
							added[vals[4][i].a] = 1;
						}
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

#include <stdio.h>
#include <string.h>
#include <limits.h>

const int PLUS = -1;
const int MINUS = -2;
const int MULT = -3;
const int DIV = -4;

int nums[4];

int nvals[5];
int vals[5][100000];
int used[5][100000];

int len;
int expr[8];

int evalexpr(int l) {
	int i, sum, prod;

	sum = 0;
	prod = expr[0];
	for (i = 0; i + 1 < l; i += 2) {
		if (expr[i+1] == PLUS) {
			// printf("a\n");
			sum += prod;
			prod = expr[i+2];
		} else if (expr[i+1] == MINUS) {
			// printf("b\n");
			sum += prod;
			prod = -expr[i+2];
		} else if (expr[i+1] == MULT) {
			// printf("c\n");
			prod *= expr[i+2];
		} else {  // DIV
			// printf("d\n");
			if (expr[i+2] == 0 || prod % expr[i+2] != 0)
				return INT_MAX;
			prod /= expr[i+2];
		}
	}
	sum += prod;
	return sum;
}

void printexpr(int N, int l) {
	int i;
	for (i = 0; i < l; i++) {
		if (expr[i] == PLUS)
			printf(" + ");
		else if (expr[i] == MINUS)
			printf(" - ");
		else if (expr[i] == MULT)
			printf(" * ");
		else if (expr[i] == DIV)
			printf(" / ");
		else
			printf("%d", expr[i]);
	}
	printf(" = %d\n", evalexpr(l));
}

void indent(int i) {
	while (i-- > 0)
		printf("  ");
}

int nbitsset(int a) {
	int n;
	n = 0;
	while (a > 0) {
		if ((a & 1) == 1)
			n++;
		a = (a >> 1);
	}
	return n;
}

void func(int n, int i, int N, int u) {
	int s, j, oper;

	for (s = 1; s < N && n + s <= N; s++) {
		for (j = 0; j < nvals[s]; j++) {
			if ((u & used[s][j]) != 0)
				continue;
			expr[i] = vals[s][j];
			// indent(i); printf("%d\n", expr[i]);
			if (n + s < N) {
				for (oper = DIV; oper <= PLUS; oper++) {
					expr[i+1] = oper;
					// indent(i+1); printf("%d\n", expr[i+1]);
					func(n + s, i + 2, N, u | used[s][j]);
				}
			} else {
				if (nbitsset(u | used[s][j]) == N) {
					printf("%d\n", u | used[s][j]);
					printexpr(N, i + 1);
					vals[N][nvals[N]++] = evalexpr(i + 1);
				}
			}
		}
	}
}

int main() {
	int N, i;

	vals[1][0] = 1, vals[1][1] = 2, vals[1][2] = 3, vals[1][3] = 4;
	used[1][0] = (1 << 0);
	used[1][1] = (1 << 1);
	used[1][2] = (1 << 2);
	used[1][3] = (1 << 3);
	nvals[1] = 4;

	for (N = 1; N <= 4; N++) {
		func(0, 0, N, 0);
		printf("set %d: ", N);
		for (i = 0; i < nvals[N]; i++) {
			printf("%d ", vals[N][i]);
		}
		printf("\n");
	}

	return 0;
}

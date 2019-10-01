#include <stdio.h>
#include <math.h>

long long gcd(long long a, long long b)
{
	return b == 0 ? a : gcd(b, a % b); 
}

/*
int main()
{
	long long a, d, x1, y1, x0, y0, a0, div;

	for (d = 1; d <= 1000; d++) {
		x0 = 0;
		y0 = 1;
		a = (long long) sqrt((double) d);
		if (a * a == d) continue;
		printf("d = %lld\n", d);
		do {
			x1 = y0 * (d - a * a);
			y1 = 2 * a * y0 + x0;
			x0 = x1;
			y0 = y1;
			x1 = x1 + a * y1;
			div = gcd(x1, y1);
			x1 /= div;
			y1 /= div;
			printf("%lld / %lld = %f\n", x1, y1, (double) x1 / y1);
		} while (x1 * x1 - d * y1 * y1 != 1);
	}

	return 0;
}
*/

void func(int iters, double x, long long *t1, long long *b1)
{
	long long a = (long long) x;
	if (iters == 0) {
		*t1 = a;
		*b1 = 1;
	} else {
		long long t2, b2;
		func(iters - 1, 1.0 / (x - a), &t2, &b2);
		*t1 = a * t2 + b2;
		*b1 = t2;
	}
}

int main()
{
	long long n, iters, x, y, d, xsol, ysol;

	for (n = 182; n <= 1000; n++) {
		if (((int) sqrt((double) n)) * ((int) sqrt((double) n)) != n) {
			iters = 0;
			while (x * x - n * y * y != 1 && x * x - n * y * y != -1) {
				func(iters, sqrt((double) n), &x, &y);
				iters++;
				// printf("%lld^2 - %lld * %lld^2 = %lld\n", x, n, y, x * x - n * y * y);
			}

			if (x * x - n * y * y == +1) {
				xsol = x;
				ysol = y;
			} else {
				xsol = x * x + n * y * y;
				ysol = 2 * x * y;
			}

			printf("D = %d: (%lld, %lld)\n", n, xsol, ysol);
			//printf("%lld^2 - %lld * %lld^2 = %lld\n", xsol, n, ysol, xsol * xsol - n * ysol * ysol);
		}



		/*
		x = sqrt((double) n);

		if (((int) x) * ((int) x) == n) 
			continue;

		while (1) {
			a = (int) floor(x);
			printf("a = %d\n", a);
			x = 1.0 / (x - a);
		}
		*/
	}



}

#include <stdio.h>

/* Lagrange interpolation */

struct fraction {
	long long t, b;
};

long long gcd(long long a, long long b) {
	if (a < 0)
		return gcd(-a, b);
	if (b < 0)
		return gcd(a, -b);
	if (a < b)
		return gcd(b, a);
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

struct fraction fraccreate(long long t, long long b) {
	struct fraction frac;
	frac.t = t;
	frac.b = b;
	return frac;
}

struct fraction fracadd(struct fraction a, struct fraction b) {
	long long d;
	a.t = a.t * b.b + a.b * b.t;
	a.b = a.b * b.b;
	d = gcd(a.t, a.b);
	a.t = a.t / d;
	a.b = a.b / d;
	return a;
}

long long fracint(struct fraction a) {
	return a.t / a.b;
}

long long gen(long long n) {
	long long i;
	long long ans = 0;
	long long pow = 1;
	for (i = 0; i <= 10; i++) {
		ans += (i % 2 == 0 ? +1 : -1) * pow;
		pow *= n;
	}
	return ans;

}

int main() {
	struct fraction guess, term;
	long long x, i, j, deg;

	long long sum = 0;
	for (deg = 0; deg < 10; deg++) {
		x = 0;
		do {
			x++;
			guess = fraccreate(0, 1);
			for (i = 1; i <= deg + 1; i++) {
				term = fraccreate(gen(i), 1);
				for (j = 1; j <= deg + 1; j++) {
					if (i != j) {
						term.t *= x - j;
						term.b *= i - j;
					}
				}
				guess = fracadd(guess, term);
			}
		} while (fracint(guess) == gen(x));
		sum += fracint(guess);
	}

	printf("sum = %lld\n", sum);

	return 0;
}

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

struct fraction fracadd(struct fraction a, struct fraction b) {
	long long d;
	a.t = a.t * b.b + a.b * b.t;
	a.b = a.b * b.b;
	d = gcd(a.t, a.b);
	a.t = a.t / d;
	a.b = a.b / d;
	return a;
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
	long long x, a, b, aans, bans, i, j, deg, sum, d;

	sum = 0;
	for (deg = 0; deg < 10; deg++) {
		x = 0;
		do {
			x++;
			aans = 0;
			bans = 1;
			for (i = 1; i <= deg + 1; i++) {
				a = gen(i);
				b = 1;
				for (j = 1; j <= deg + 1; j++) {
					if (i != j) {
						a *= x - j;
						b *= i - j;
					}
				}
				aans = aans * b + bans * a;
				bans = bans * b;
				d = gcd(aans, bans);
				aans /= d;
				bans /= d;
				// printf(" + %d / %d", a, b);
			}
			// printf(" = %d / %d = %d\n", aans, bans, aans / bans);
		} while (aans / bans == gen(x));
		sum += aans / bans;
	}

	printf("sum = %lld\n", sum);

	return 0;
}

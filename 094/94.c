#include <stdio.h>
#include <math.h>

long long isqrt(long long n) {
	long long rt = (long long) sqrt((double) n);
	return rt * rt == n ? rt : -1;
}

int main() {
	long long a, rt, sq, d, perim, sum;

	sum = 0;
	for (a = 3; a <= 333333333; a += 2) {
		for (d = +1; d >= -1; d -= 2) {
			perim = 3 * a + d;
			sq = perim * (a - d);
			rt = isqrt(sq);
			if (rt != -1 && (a + d) * rt % 4 == 0) {
				sum += perim;
				printf("%10lld + %10lld + %10lld = %10lld\n", a, a, a + d, perim);
			}
		}
	}

	printf("perimeter sum                        = %10lld\n", sum);

	return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct triangle {
	int p, a, b, c;
};

const int L = 1500000;

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

int tricmp(const void *ptr1, const void *ptr2) {
	struct triangle *tri1, *tri2;
	tri1 = (struct triangle *) ptr1, tri2 = (struct triangle *) ptr2;
	/* sufficient to compare p and a? */
	if (tri1->p < tri2->p) return -1;
	if (tri1->p > tri2->p) return +1;
	return tri1->a - tri2->a;
}

int trisequal(struct triangle *tri1, struct triangle *tri2) {
	return tri1->a == tri2->a && tri1->b == tri2->b && tri1->c == tri2->c;
}

int main() {
	int i;
	int m, n, k;
	int nuniq, count;
	int ntris;
	struct triangle *tris;

	/* determine number of triangles */
	ntris = 0;
	for (m = 1; 2 * m * (m + 1) <= L; m++) {
		for (n = 1; n < m && 2 * m * (m + n) <= L; n++) {
			for (k = 1; 2 * k * m * (m + n) <= L; k++) {
				ntris++;
			}
		}
	}

	tris = malloc(ntris * sizeof(struct triangle));

	/* create triangles */
	i = 0;
	for (m = 1; 2 * m * (m + 1) <= L; m++) {
		for (n = 1; n < m && 2 * m * (m + n) <= L; n++) {
			for (k = 1; 2 * k * m * (m + n) <= L; k++) {
				tris[i].a = min(k * (m * m - n * n), k * 2 * m * n);
				tris[i].b = max(k * (m * m - n * n), k * 2 * m * n);
				tris[i].c = k * (m * m + n * n);
				tris[i].p = tris[i].a + tris[i].b + tris[i].c;
				i++;
			}
		}
	}

	/* sort triangles to ignore duplicates */
	qsort(tris, ntris, sizeof(struct triangle), tricmp);

	/* count unique triangles of each perimeter */
	/* skip consecutive identical triangles (duplicates) */
	/* sum the number of perimeters that only one unique triangle has */
	nuniq = 1;
	count = 0;
	for (i = 1; i < ntris; i++) {
		if (!trisequal(&tris[i], &tris[i-1]) && tris[i].p == tris[i-1].p) {
			nuniq++;
		} else if (tris[i].p != tris[i-1].p) {
			if (nuniq == 1)
				count++;
			nuniq = 1;
		}
	}

	printf("%d\n", count);
	free(tris);
	return 0;
}

#include <stdio.h>
#include <string.h>
#include <math.h>

char words[2000][20];
int maps1[10000][26];
int maps2[10000][26];

int max(int a, int b) { return a > b ? a : b; }

void createmap(int *map, char *str, int sq) {
	int i, l;
	memset(map, -1, 26 * sizeof(int));
	l = strlen(str);
	for (i = l - 1; i >= 0; i--) {
	}
}

int iexp(int base, int pow) {
	int res;
	res = 1;
	while (pow-- > 0)
		res *= base;
	return res;
}

int areanagrams(char *str1, char *str2) {
	int i;
	int freqs1[26], freqs2[26];

	if (strcmp(str1, str2) == 0)
		return 0;

	memset(freqs1, 0, 26 * sizeof(int));
	memset(freqs2, 0, 26 * sizeof(int));

	for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {
		freqs1[str1[i] - 'A']++;
		freqs2[str2[i] - 'A']++;
	}

	if (str1[i] != '\0' || str2[i] != '\0')
		return 0;

	for (i = 0; i < 26; i++) {
		if (freqs1[i] != freqs2[i])
			return 0;
	}

	return 1;
}

int func(char *str1, char *str2) {
	int l;
	int k1, k2, kmin, kmax;
	int sq;
	char map1[10], map2[10];
	int i, j;

	l = strlen(str1);
	kmin = (int) ceil(sqrt(pow(10.0, (double) l - 1)));
	kmax = (int) ceil(sqrt(pow(10.0, (double) l)));


	for (k1 = kmax - 1; k1 >= kmin; k1--) {
		memset(map1, -1, 10 * sizeof(char));
		sq = k1 * k1;
		for (i = l - 1; i >= 0; i--) {
			if (map1[sq % 10] != -1 && map1[sq % 10] != str1[i])
				break;
			for (j = 0; j < 10; j++)
				if (j != sq % 10 && map1[j] == str1[i])
					break;
			if (j != 10)
				break;
			map1[sq % 10] = str1[i];
			sq /= 10;
		}
		if (i != -1)
			continue;

		for (k2 = kmax - 1; k2 >= kmin; k2--) {
			memset(map2, -1, 10 * sizeof(char));
			sq = k2 * k2;
			for (i = l - 1; i >= 0; i--) {
				if (map2[sq % 10] != -1 && map2[sq % 10] != str2[i])
					break;
				for (j = 0; j < 10; j++)
					if (j != sq % 10 && map2[j] == str2[i])
						break;
				if (j != 10)
					break;
				map2[sq % 10] = str2[i];
				sq /= 10;
			}
			if (i != -1)
				continue;

			if (memcmp(map1, map2, 10 * sizeof(char)) == 0) {
				/*
				for (i = 0; i < 10; i++) {
					if (map1[i] != -1)
						printf("%d%c", i, map1[i]);
				}
				printf("\n");
				*/
				return max(k1 * k1, k2 * k2);
			}
		}
	}

	return -1;
}

int main() {
	int nwords;
	int i, j, sq;

	nwords = 0;
	scanf("\"%[A-Z]\"", words[nwords++]);
	while (scanf(",\"%[A-Z]\"", words[nwords++]) == 1);

	for (i = 0; i < nwords; i++) {
		for (j = i + 1; j < nwords; j++) {
			if (areanagrams(words[i], words[j])) {
				printf("%s - %s\n", words[i], words[j]);
				sq = func(words[i], words[j]);
				if (sq != -1)
					printf("%d\n", sq);
			}
		}
	}

	return 0;
}

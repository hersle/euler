#include <stdio.h>

int fact(int n)
{
    if (n <= 1) return 1;
    return n * fact(n - 1);
}

int digitfactsum(int n)
{
    int sum = 0;
    while (n > 0) {
        sum += fact(n % 10);
        n /= 10;
    }
    return sum;
}

int chainlen(int n)
{
    int loop[1000];
    loop[0] = n;

    // printf("%d", loop[0]);

    int i = 1;
    int j;

    while (1) {
        loop[i] = digitfactsum(loop[i-1]);

        // printf(" %d", loop[i]);

        for (j = 0; j < i; j++) {
            if (loop[i] == loop[j]) {
                // printf("\n");
                return i;
            }
        }

        i++;
    }
}


int main()
{
    int n;
    int count = 0;
    for (n = 0; n < 1000000; n++) {
        if (chainlen(n) == 60)
            count++;
    }

    printf("count = %d\n", count);

    return 0;
}

#include <stdio.h>

long long numappend(long long n, int a)
{
    long long d = 1;
    while (a / d > 0)
        d *= 10;
    return n * d + a;
}

void ring_to_lines(int ring[10], int lines[15])
{
    int i;
    for (i = 0; i < 15; i++) {
        if (i % 3 == 0)
            lines[i] = ring[i / 3];
        else if (i % 3 == 1)
            lines[i] = ring[5 + i / 3];
        else    
            lines[i] = ring[5 + (1 + i / 3) % 5];
    }
}

long long get_solution(int lines[15])
{
    int i;
    int j = 0;
    for (i = 3; i < 15; i += 3)
        if (lines[i] < lines[j])
            j = i;

    long long n = lines[j];
    for (i = j + 1; i % 15 != j; i++)
        n = numappend(n, lines[i % 15]);

    return n;
}

int is_solution(int lines[15])
{
    int i;
    int sum1 = 0;
    for (i = 0; i < 3; i++)
        sum1 += lines[i];

    int sum2 = 0;
    for (i = i; i < 15; i++) {
        sum2 += lines[i];
        if (i % 3 == 2) {
            if (sum1 != sum2)
                return 0;
            sum2 = 0;
        }
    }

    return 1;
}

long long get_max_solution(int ring[10], int used[11], int i)
{
    if (i == 10) {
        int lines[15];
        ring_to_lines(ring, lines);
        if (is_solution(lines)) {
            printf("%lld\n", get_solution(lines));
            return get_solution(lines);
        }
        return 0;
    }

    int n;
    long long solution;
    long long solution_max = 0;
    for (n = 10; n >= 1; n--) {
        if (!used[n]) {
            ring[i] = n;
            used[n] = 1;
            solution = get_max_solution(ring, used, i + 1);
            if (solution > solution_max && solution < 1E16)
                solution_max = solution;
            used[n] = 0;
        }
    }

    return solution_max;
}

int main()
{
    int ring[10];
    int used[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    printf("max 16-digit solution: %lld\n", get_max_solution(ring, used, 0));
    return 0;
}

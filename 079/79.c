#include <stdio.h>

char logins[50][3];

int min(int a, int b)
{
    return a < b ? a : b;
}

int minlen(int code[150], int used[50], int i_start, int i_end)
{
    int i, j, k;
    for (i = 0; i < 50; i++) {
        if (!used[i]) {
            for (j = i_start; j != i_end; j = (j + 151) % 150) {
                for (k = 0; k < 3 && code[(j + k) % 150] == logins[i][k]; k++) {
                    code[(j + k
                }
            }
        }
    }

    return ((i_end - i_start + 150) % 150) + 1;
}

int main()
{
    int i;
    for (i = 0; i < 50; i++) {
        logins[i][0] = (char) getchar();
        logins[i][1] = (char) getchar();
        logins[i][2] = (char) getchar();
        printf("%c%c%c\n", logins[i][0], logins[i][1], logins[i][2]);
        getchar();
    }

    int code[150];
    int used[50] = {};
    for (i = 0; i < 50; i++) {
        code[0] = logins[i][0];
        code[1] = logins[i][1];
        code[2] = logins[i][2];
        printf("minlen(%c%c%c) = %d\n", code[0], code[1], code[2], minlen(code, used, 0, 2));
    }

    return 0;
}

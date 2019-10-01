#include <stdio.h>
#include <limits.h>

#define M 6

int main()
{
    printf("INT_MAX = %d\n", INT_MAX);

    int n = 1;
    while (n != INT_MAX) {
        // Get length of n
        int len1 = 0;
        int div = 1;
        while (n / div >= 1) {
            len1++;
            div *= 10;
        }

        // Get the digits of n
        int digits1[len1];
        div = 1;
        int i;
        for (i = 0; n / div >= 1; i++, div *= 10) {
            digits1[i] = n / div % 10;
        }


        // Check if n and m, 2m, ..., Mm has same digits
        int m;
        for (m = 2; m <= M; m++) {
            // Get length of m * n
            int len2 = 0;
            div = 1;
            while (n * m / div >= 1) {
                len2++;
                div *= 10;
            }

            // Digits must have same number of digits
            if (len1 != len2) break;

            // Get digits of m * n
            int digits2[len2];
            div = 1;
            for (i = 0; n * m / div >= 1; i++, div *= 10) {
                digits2[i] = n * m / div % 10;
            }

            // Compare digits
            int identical = 1;
            int j;
            for (i = 0; i < len1; i++) {
                for (j = 0; j < len2; j++) {
                    if (digits1[i] == digits2[j]) {
                        digits2[j] = -1;  // digit cannot be matched again
                        break;
                    }
                }
                // Not identical if digit not found in both numbers
                if (j == len2) {
                    break;
                }
            }

            if (i != len1) {
                break;
            }
        }

        // Digits are identical if the last loop completed
        if (m == M + 1) {
            printf("n = %d\n", n);
            // return 0;  // remove return to print more numbers
        }

        n++;
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "r");

    char key[3];
    char key_final[3];
    char ascii;
    int alphas;
    int alphas_max = 0;
    int n;
    int ascii_sum;
    int ascii_sum_most_alphas = 0;

    for (key[0] = 'a'; key[0] <= 'z'; key[0]++) {
        for (key[1] = 'a'; key[1] <= 'z'; key[1]++) {
            for (key[2] = 'a'; key[2] <= 'z'; key[2]++) {
                // Reset
                rewind(file);
                alphas = 0;
                n = 0;
                ascii_sum = 0;

                // Read first character
                fscanf(file, "%hhd", &ascii);

                // Handle first and remaining characters
                do {
                    ascii = ascii ^ key[n % 3];  // decrypt
                    ascii_sum += ascii;
                    if (isalpha(ascii))
                        alphas++;
                    n++;
                } while (fscanf(file, ",%hhd", &ascii));

                if (alphas > alphas_max) {
                    alphas_max = alphas;
                    ascii_sum_most_alphas = ascii_sum;
                    key_final[0] = key[0];
                    key_final[1] = key[1];
                    key_final[2] = key[2];
                }
            }
        }
    }

    printf("Sum for key with most alpha chars: %d\n", ascii_sum_most_alphas);
    fclose(file);
    return 0;
}

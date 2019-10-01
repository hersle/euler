#include <stdio.h>

int get_numeral_value(char numeral)
{
    switch (numeral) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
    }
}

int main()
{
    int ch;
    char numeral;

    int number;
    int value;
    int value_prev;

    int values[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    int length;

    int saved_chars = 0;

    while ((ch = getchar()) != EOF) {
        number = 0;
        length = 0;
        value_prev = 1000;
        while (ch != '\n') {
            length++;
            numeral = (char) ch;
            putchar(numeral);
            value = get_numeral_value(numeral);
            number += value;
            if (value_prev < value) 
                number -= 2 * value_prev;
            ch = getchar();
            value_prev = value;
        }
        printf(" = %d, ", number);

        /* Find optimal */
        int i;
        for (i = 0; i < 13; i++) {
            length -= (number / values[i]) * (i % 2 == 0 ? 1 : 2);
            number -= (number / values[i]) * values[i];
        }

        saved_chars += length;
        printf("saved %d chars\n", length);
    }

    printf("saved %d chars\n", saved_chars);
    return 0;
}

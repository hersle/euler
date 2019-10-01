#include <stdio.h>
#include <stdlib.h>

int main()
{
    int turns = 1000000;

    int dice_eyes = 4;

    int visits[40] = {};

    int cc = 1;
    int ch = 1;

    int turn;
    int square = 0;
    int dice1, dice2;
    int consec_doubles = 0;

    for (turn = 1; turn <= turns; turn++) {
        dice1 = 1 + rand() % dice_eyes;
        dice2 = 1 + rand() % dice_eyes;
        consec_doubles = dice1 == dice2 ? consec_doubles + 1 : 0;
        square = consec_doubles == 3 ? 10 : (square + dice1 + dice2) % 40;

        /* handle jumps */
        switch (square) {
            case  2:
            case 17:
            case 33:
                /* CC */
                switch (cc) {
                    case 1:
                        square = 0; break;
                    case 2:
                        square = 10; break;
                }
                cc = cc < 16 ? cc + 1 : 1;
                break;
            case  7:
            case 22:
            case 36:
                /* CH */
                switch (ch) {
                    case 1:
                        square = 0; break;
                    case 2:
                        square = 10; break;
                    case 3:
                        square = 11; break;
                    case 4:
                        square = 24; break;
                    case 5:
                        square = 39; break;
                    case 6:
                        square = 5; break;
                    case 7:
                    case 8:
                        square = 5 + (square + 5) % 40 / 10 * 10; break;
                    case 9:
                        square = square < 12 || square > 28 ? 12 : 28; break;
                    case 10:
                        square = (square + 37) % 40; break;
                }
                ch = ch < 16 ? ch + 1 : 1;
                break;
            case 30:
                /* jail */
                square = 10; 
                break;
        }

        visits[square]++;
    }

    int squares[3] = {-1, -1, -1};
    for (square = 0; square < 40; square++) {
        if (squares[0] == -1 || visits[square] > visits[squares[0]]) {
            squares[2] = squares[1];
            squares[1] = squares[0];
            squares[0] = square;
        } else if (squares[1] == -1 || visits[square] > visits[squares[1]]) {
            squares[2] = squares[1];
            squares[1] = square;
        } else if (squares[2] == -1 || visits[square] > visits[squares[2]]) {
            squares[2] = square;
        }
        printf("square %02d: %f %\n", square, 100.0 * visits[square] / turns);
    }
    printf("%02d%02d%02d\n", squares[0], squares[1], squares[2]);

    return 0;
}

#include <stdio.h>

void solve_sudoku(int sudoku[81])
{

}

void read_sudoku(int sudoku[81])
{
    while (getchar() != '\n');  /* skip first line */
    int cell;
    for (cell = 0; cell < 81; cell++) {
        sudoku[cell] = getchar() - '0';
    }
}

void print_sudoku(int sudoku[81])
{
    int cell;
    for (cell = 0; cell < 81; cell++) {
        putchar('0' + sudoku[cell]);
        if (cell % 9 == 8) putchar('\n');
    }
}

int main()
{
    int i;
    int sudoku[81];
    for (i = 0; i < 1; i++) {
        read_sudoku(sudoku);
        /* TODO: solve sudoku */
        print_sudoku(sudoku);
    }
    
    return 0;
}

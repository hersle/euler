#include <stdio.h>
#include <string.h>

void set_cell(int sudoku[81], int cell, int num)
{
    sudoku[cell] = num;
}

int conflicts(int sudoku[81], int cell0, int cell1, int d, int num)
{
    while (cell0 < cell1 && sudoku[cell0] != num) cell0 += d;
    return cell0 != cell1;
}

int is_candidate(int sudoku[81], int cell, int num)
{
    int cell0_row = (cell / 9) * 9;
    int cell0_col = cell % 9;
    int cell0_box = (cell0_row / 27) * 27 + (cell0_col / 3) * 3;
    return !conflicts(sudoku, cell0_row, cell0_row + 9, 1, num) &&
           !conflicts(sudoku, cell0_col, cell0_col + 81, 9, num) &&
           !conflicts(sudoku, cell0_box, cell0_box + 3, 1, num) &&
           !conflicts(sudoku, cell0_box + 9, cell0_box + 12, 1, num) &&
           !conflicts(sudoku, cell0_box + 18, cell0_box + 21, 1, num);
}

void solve_cell(int sudoku[81], int cell)
{
    int num;
    int candidate = 0;
    for (num = 1; num <= 9; num++) {
        if (is_candidate(sudoku, cell, num)) {
            if (candidate != 0)
                return;  /* multiple candidates; cannot solve cell */
            candidate = num;
        }
    }
    set_cell(sudoku, cell, candidate);
}

void solve_sudoku_guess(int sudoku[81], int cell_last)
{
    int cell;
    int num;
    for (cell = 0; cell < 81; cell++) {
        for (num = 1; num <= 9; num++) {
            if (is_candidate(sudoku, cell, num)) {
                set_cell(sudoku, cell, num);

                /* TODO */
                solve_sudoku_guess(sudoku, cell);

                if (sudoku[cell] == 0)
                    set_cell(sudoku, 0, num);
            }
        }
    }
}

void solve_sudoku(int sudoku[81])
{
    int cell;
    do {
        for (cell = 0; cell < 81; cell++) {
            if (sudoku[cell] == 0) {
                solve_cell(sudoku, cell);
                if (sudoku[cell] != 0)
                    break;
            }
        }
    } while (cell < 81);
}

void print_sudoku(int sudoku[81])
{
    int cell;
    for (cell = 0; cell < 81; cell++) {
        putchar('0' + sudoku[cell]);
        if (cell % 9 == 8) putchar('\n');
    }
}

void read_sudoku(int sudoku[81])
{
    while (getchar() != '\n');  /* skip first line */
    int cell;
    for (cell = 0; cell < 81; cell++) {
        set_cell(sudoku, cell, getchar() - '0');
        if (cell % 9 == 8) getchar();  /* skip newline */
    }
}

int main()
{
    int sudoku[81];
    int i;
    for (i = 0; i < 2; i++) {
        read_sudoku(sudoku);
        solve_sudoku(sudoku);
        print_sudoku(sudoku);
    }
    return 0;
}

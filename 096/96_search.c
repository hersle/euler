#include <stdio.h>
#include <string.h>

struct sudoku {
    int board[81];
    int n_candidates[81];
    int is_candidate[81][10];
};

void deny_candidate(struct sudoku *s, int cell0, int cell1, int d, int candidate)
{
    while (cell0 < cell1) {
        s->is_candidate[cell0][candidate] = 0;
        cell0 += d;
    }
}

void set_cell(struct sudoku *s, int cell, int num)
{
    s->board[cell] = num;

    int cell0_row = (cell / 9) * 9;
    int cell0_col = cell % 9;
    int cell0_box = (cell0_row / 27) * 27 + (cell0_col / 3) * 3;

    deny_candidate(s, cell0_row, cell0_row + 9, 1, num);
    deny_candidate(s, cell0_col, cell0_col + 81, 9, num);
    deny_candidate(s, cell0_box, cell0_box + 3, 1, num);
    deny_candidate(s, cell0_box + 9, cell0_box + 12, 1, num);
    deny_candidate(s, cell0_box + 18, cell0_box + 21, 1, num);
}

void solve_sudoku(struct sudoku *s)
{
    int cell;
    for (cell = 0; cell < 81; cell++) {
        if (s->n_candidates[cell] == 1) {
        }
    }
}

void read_sudoku(struct sudoku *s)
{
    while (getchar() != '\n');  /* skip first line */

    int cell;
    int num;

    for (cell = 0; cell < 81; cell++) {
        s->n_candidates[cell] = 9;
        for (num = 1; num <= 9; num++) {
            s->is_candidate[cell][num] = 1;
            /* s->candidates[cell][num-1] = num; */
        }
    }

    for (cell = 0; cell < 81; cell++) {
        set_cell(s, cell, getchar() - '0');
        if (cell % 9 == 8) getchar();  /* skip newline */
    }
}

void print_sudoku(struct sudoku *s)
{
    int cell;
    for (cell = 0; cell < 81; cell++) {
        putchar('0' + s->board[cell]);
        if (cell % 9 == 8) putchar('\n');
    }
}

int main()
{
    struct sudoku s;
    int i;
    for (i = 0; i < 2; i++) {
        read_sudoku(&s);
        solve_sudoku(&s);
        print_sudoku(&s);
    }
    return 0;
}

/*
void solve_sudoku(int sudoku[81])
{
    int cell;
    int num;
    do {
        for (cell = 0; cell < 81; cell++) {
            if (sudoku[cell] == 0) {
                for (num = 1; num <= 9; num++) {
                    
                }

                if (sudoku[cell] != 0)
                    break;
            }
        }
    } while (cell < 81);
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
                return;
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
*/

#include <stdio.h>

int sudoku[81];
int row_used[9][10], col_used[9][10], box_used[9][10];

int get_row_id(int cell) { return cell / 9; }
int get_col_id(int cell) { return cell % 9; }
int get_box_id(int cell) { return (cell / 27) * 3 + (cell % 9) / 3; }

void set_cell(int cell, int n)
{
    row_used[get_row_id(cell)][n] = 1;
    col_used[get_col_id(cell)][n] = 1;
    box_used[get_box_id(cell)][n] = 1;
    sudoku[cell] = n;
}

void clear_cell(int cell)
{
    row_used[get_row_id(cell)][sudoku[cell]] = 0;
    col_used[get_col_id(cell)][sudoku[cell]] = 0;
    box_used[get_box_id(cell)][sudoku[cell]] = 0;
    sudoku[cell] = 0;
}

void read_sudoku()
{
    int id, n, cell;
    for (id = 0; id < 9; id++) {
        for (n = 1; n <= 9; n++) {
            row_used[id][n] = 0;
            col_used[id][n] = 0;
            box_used[id][n] = 0;
        }
    }
    for (cell = 0; cell < 81; cell++) {
        set_cell(cell, getchar() - '0');
        if (cell % 9 == 8) getchar();  /* skip newline */
    }
}

void print_sudoku()
{
    int cell;
    for (cell = 0; cell < 81; cell++) {
        putchar('0' + sudoku[cell]);
        if (cell % 9 == 8) putchar('\n');
    }
}

int is_candidate(int cell, int n)
{
    return !row_used[get_row_id(cell)][n] &&
           !col_used[get_col_id(cell)][n] &&
           !box_used[get_box_id(cell)][n];
}

int solve_sudoku(int cell)
{
    if (cell == 81) 
        return 1;  /* solution found */
    if (sudoku[cell] != 0) 
        return solve_sudoku(cell + 1);

    int n;
    for (n = 1; n <= 9; n++) {
        if (is_candidate(cell, n)) {
            set_cell(cell, n);
            if (solve_sudoku(cell + 1) == 1)
                return 1;  /* solution found */
            clear_cell(cell);
        }
    }
    return 0;  /* no candidates; unsolvable */
}

int main()
{
    int ch;
    int sum = 0;
    while ((ch = getchar()) != EOF) {
        putchar(ch);
        while (putchar((char) getchar()) != '\n');
        read_sudoku();
        solve_sudoku(0);
        print_sudoku();
        sum += sudoku[0] * 100 + sudoku[1] * 10 + sudoku[2];
    }
    printf("sum = %d\n", sum);
    return 0;
}

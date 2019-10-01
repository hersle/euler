#include <stdio.h>

int sudoku[81];

void read_sudoku()
{
    int cell;
    for (cell = 0; cell < 81; cell++) {
        sudoku[cell] = getchar() - '0';
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

int conflicts_row(int n, int cell)
{
    for (cell = (cell / 9) * 9 + 1; cell % 9 > 0; cell++)
        if (sudoku[cell] == n) return 1;
    return sudoku[cell - 9] == n;
}

int conflicts_col(int n, int cell)
{
    for (cell = cell % 9; cell < 81; cell += 9)
        if (sudoku[cell] == n) return 1;
    return 0;
}

int conflicts_box(int n, int cell)
{
    int lim = (cell / 27) * 27 + ((cell % 9) / 3) * 3 + 27;
    cell = lim - 27;
    while (cell < lim) {
        if (sudoku[cell] == n) 
            return 1;
        if (cell % 3 == 2)
            cell += 7;
        else
            cell++;
    }
    return 0;
}

int conflicts(int n, int cell)
{
    return conflicts_row(n, cell) || 
           conflicts_col(n, cell) || 
           conflicts_box(n, cell);
}

int solve_sudoku(int cell)
{
    if (cell == 81) 
        return 1;
    if (sudoku[cell] != 0) 
        return solve_sudoku(cell + 1);

    int n;
    for (n = 1; n <= 9; n++) {
        if (!conflicts(n, cell)) {
            sudoku[cell] = n;
            if (solve_sudoku(cell + 1) == 1)
                return 1;
            sudoku[cell] = 0;
        } else {
        }
    }
    return 0;
}

int main()
{
    int i;
    int sum = 0;
    for (i = 0; i < 50; i++) {
        while (getchar() != '\n');
        printf("sudoku #%d:\n", i + 1);
        read_sudoku();
        solve_sudoku(0);
        print_sudoku();
        sum += sudoku[0] * 100 + sudoku[1] * 10 + sudoku[2];
    }
    printf("sum = %d\n", sum);
    return 0;
}

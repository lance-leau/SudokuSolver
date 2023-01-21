#include <stdio.h>
#include "sudoku.h"

// Global variables
char grid[81] = {0,};

int main(int argc, char *argv[25])
{
    if (argc != 2)
    {
        printf("missing argument: ./main <path1>\n");
        return 0;
    }
    loadSudoku(grid, argv[1]);
    solve(grid);
    saveSudoku(grid, argv[1]);
    return 0;
}

#include <stdio.h>
#include "sudoku.h"

// Global variables
int grid[81] = {0,};

int main()
{
    setGrid(grid);
    prettyPrint(grid);
    solve(grid);
    prettyPrint(grid);
    return 0;
}

#include <stdio.h>
#include "sudoku.h"

// Global variables
char grid[81] = {0,};

int main(int argc, char *argv[25])
{
    // check if number of arguments is sorrect
    if (argc != 2)
    {
        printf("missing argument: ./main <path>\n");
        return -1;
    }

    // load the sudoku grid
    if (loadSudoku(grid, argv[1]) != 0)
    {
        printf("loadSudoku(): '%s' file can not be opened\n", argv[1]);
        return -1;
    }

    prettyPrint(grid);

    // solve the sudoku grid
    if (!solve(grid))
    {
        printf("solve(): '%s' is not solvable, please enter valid grid\n"
                                                                     , argv[1]);
        return -1;
    }

    prettyPrint(grid);

    // save the sudoku grid
    if (saveSudoku(grid, argv[1]) != 0)
    {
        printf("saveSudoku(): '%s.result' file can not be saved to memory\n"
                                                                     , argv[1]);
        return -1;
    }
    // exit the programme with a success exit code
    return 0;
}

#include <stdio.h>
#include "sudoku.h"


/*\brief Checks if an integer is in a array
 * @param array int[] -- the array being checked
 * @param val int -- the int being searched for in the array
 * @return int -- returns true (1) if item is in array, 
 * returns false (0) if item is NOT in array
 */
int isIntInArray(int array[9], int val)
{
    for (size_t i = 0; i < 9; i++) if (array[i] == val) return 1;
    return 0;
}

/*\brief replaces the first 0 in the given array with the given int
 * @param array int[] -- the array the item is added to
 * @param val int -- the int added to the array
 * @return void -- the array in updated in place
 */ 
void addIntToArray(int array[9], int val)
{
    /* replaces the first 0 in the array with the given val*/
    for (size_t i = 0; i < 9; i++)
    {
        if (array[i] == 0)
        {
            array [i] = val;
            return;
        }
    }
    return;
}


/*\brief replaces the first 0 in the given array with the given int
 * @param grid int[81] -- the array representing a 9 by 9 grid of integers
 * @return int -- 1 if there are NO duplicate number in the rows of the grid, 
 * 0 if there are duplicate number in the rows of the grid,
 */ 
int checkRows(int grid[81])
{
    for (size_t i = 0; i < 9; i++)
    {
        int currRow[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
        for (size_t j = i * 9; j < (i*9)+9; j++)
        {
            if (grid[j] != 0)
            {
                if (isIntInArray(currRow, grid[j])) return 0;
                else addIntToArray(currRow, grid[j]);
            }
        }
    }
    return 1;
}


int checkCols(int grid[81])
{
    for (size_t i = 0; i < 9; i++)
    {
        int currRow[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
        for (size_t j = i; j < 81; j += 9)
        {
            if (grid[j] != 0)
            {
                if (isIntInArray(currRow, grid[j])) return 0;
                else addIntToArray(currRow, grid[j]);
            }
        }
    }
    return 1;
}

int checkBox(int grid[81])
{
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            int currRow[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
            for (size_t k = 0; k < 3; k++)
            {
                size_t temp = i*3 + k*9 + j*27;
                if (grid[temp] != 0)
                {
                    if (isIntInArray(currRow, grid[temp])) return 0;
                    else addIntToArray(currRow, grid[temp]);
                }
                if (grid[temp+1] != 0)
                {
                    if (isIntInArray(currRow, grid[temp+1])) return 0;
                    else addIntToArray(currRow, grid[temp+1]);
                }
                if (grid[temp+2] != 0)
                {
                    if (isIntInArray(currRow, grid[temp+2])) return 0;
                    else addIntToArray(currRow, grid[temp+2]);
                }
            }
        }
    }
    return 1;
}


int isBoardLegal(int grid[81])
{
    return checkRows(grid) && checkCols(grid) && checkBox(grid);
}

//--------------------------SetCell--------------------------//

void setCell(int grid[81], size_t i, int val)
{
    grid[i] = val;
}

void setGrid(int grid[81])
{
    int newGrid[81] = {9, 2, 7,  0, 0, 0,  0, 0, 0,
                       0, 0, 0,  0, 0, 1,  0, 0, 0,
                       0, 3, 0,  2, 5, 7,  0, 0, 0,
                       0, 0, 0,  0, 0, 0,  0, 0, 0,
                       0, 0, 0,  9, 0, 0,  0, 0, 7,
                       0, 0, 0,  0, 0, 0,  0, 2, 0,
                       4, 0, 0,  0, 0, 0,  0, 0, 0,
                       0, 0, 0,  0, 0, 0,  0, 7, 0,
                       0, 0, 0,  0, 0, 0,  0, 0, 2};
    for (size_t i = 0; i < 81; i++)
    {
        setCell(grid, i, newGrid[i]);
    }
}


//--------------------------PrettyPrint--------------------------//


void printLine(int grid[], size_t start)
{
    for (size_t i = 0; i < 3; i++)
    {
        size_t temp = i*3 + start;
        if (grid[temp] != 0) printf("║ %i ", grid[temp]);
        else printf("║   ");
        if (grid[temp + 1] != 0) printf("│ %i ", grid[temp + 1]);
        else printf("│   ");
        if (grid[temp + 2] != 0) printf("│ %i ", grid[temp + 2]);
        else printf("│   ");
    }
    printf("║\n");
}

void prettyPrint(int grid[81])
{
    printf("╔═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╗\n");
    printLine(grid, 0);
    printf("╟───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
    printLine(grid, 9);
    printf("╟───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
    printLine(grid, 18);
    printf("╠═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣\n");
    printLine(grid, 27);
    printf("╟───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
    printLine(grid, 36);
    printf("╟───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
    printLine(grid, 45);
    printf("╠═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣\n");
    printLine(grid, 54);
    printf("╟───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
    printLine(grid, 63);
    printf("╟───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
    printLine(grid, 72);
    printf("╚═══╧═══╧═══╩═══╧═══╧═══╩═══╧═══╧═══╝\n");
}



int __solve(int grid[81], size_t index)
{
    if (index == 81) return 1;
    if (grid[index] != 0) return __solve(grid, index+1);
    for (int i = 1; i < 10; i++)
    {
        grid[index] = i;
        if (isBoardLegal(grid))
        {
            if (__solve(grid, index+1)) return 1;
            else grid[index] = 0;
        }
    }
    grid[index] = 0;
    return 0;
}

int solve(int grid[81])
{
    return __solve(grid, 0);
}
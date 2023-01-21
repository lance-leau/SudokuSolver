#include <stdio.h>
#include "sudoku.h"


/*\brief Checks if a size_t is in a array
 * @param array size_t[] -- the array being checked
 * @param val size_t -- the char being searched for in the array
 * @param len size_t -- the length of the array
 * @return int -- returns true (1) if item is in array, 
 * returns false (0) if item is NOT in array
 */
int isSizeTInArray(size_t array[], size_t len, size_t val)
{
    for (size_t i = 0; i < len; i++) if (array[i] == val) return 1;
    return 0;
}

/*\brief Checks if an char is in a array
 * @param array char[] -- the array being checked
 * @param val char -- the char being searched for in the array
 * @return int -- returns true (1) if item is in array, 
 * returns false (0) if item is NOT in array
 */
int isCharInArray(char array[9], char val)
{
    for (size_t i = 0; i < 9; i++) if (array[i] == val) return 1;
    return 0;
}

/*\brief replaces the first 0 in the given array with the given char
 * @param array char[] -- the array the item is added to
 * @param val char -- the char added to the array
 * @return void -- the array in updated in place
 */ 
void addCharToArray(char array[9], char val)
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

/*\brief replaces the first 0 in the given array with the given char
 * @param array char[] -- the array the item is added to
 * @param val char -- the char added to the array
 * @return void -- the array in updated in place
 */ 
void addSizeTToArray(size_t array[], size_t len, size_t val)
{
    /* replaces the first 0 in the array with the given val*/
    for (size_t i = 0; i < len; i++)
    {
        if (array[i] == 0)
        {
            array [i] = val;
            return;
        }
    }
    return;
}


/*\brief checks that there are no duplicates in rows of the grid
 * @param grid char[81] -- the array representing a 9 by 9 grid of charegers
 * @return int -- 1 if there are NO duplicate number in the rows of the grid, 
 * 0 if there are duplicate number in the rows of the grid,
 */
int checkRows(char grid[81])
{
    for (size_t i = 0; i < 9; i++)
    {
        char currRow[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
        for (size_t j = i * 9; j < (i*9)+9; j++)
        {
            if (grid[j] != 0)
            {
                if (isCharInArray(currRow, grid[j])) return 0;
                else addCharToArray(currRow, grid[j]);
            }
        }
    }
    return 1;
}

/*\brief checks that there are no duplicates in columns of the grid
 * @param grid char[81] -- the array representing a 9 by 9 grid of charegers
 * @return int -- 1 if there are NO duplicate number in the rcols of the grid, 
 * 0 if there are duplicate number in the cols of the grid,
 */
int checkCols(char grid[81])
{
    for (size_t i = 0; i < 9; i++)
    {
        char currRow[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
        for (size_t j = i; j < 81; j += 9)
        {
            if (grid[j] != 0)
            {
                if (isCharInArray(currRow, grid[j])) return 0;
                else addCharToArray(currRow, grid[j]);
            }
        }
    }
    return 1;
}

/*\brief checks that there are no duplicates in the 3 by 3 boxes of the grid
 * @param grid char[81] -- the array representing a 9 by 9 grid of charegers
 * @return int -- 1 if there are NO duplicate number in the boxes of the grid, 
 * 0 if there are duplicate number in the boxes of the grid,
 */
int checkBox(char grid[81])
{
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            char currRow[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
            for (size_t k = 0; k < 3; k++)
            {
                size_t temp = i*3 + k*9 + j*27;
                if (grid[temp] != 0)
                {
                    if (isCharInArray(currRow, grid[temp])) return 0;
                    else addCharToArray(currRow, grid[temp]);
                }
                if (grid[temp+1] != 0)
                {
                    if (isCharInArray(currRow, grid[temp+1])) return 0;
                    else addCharToArray(currRow, grid[temp+1]);
                }
                if (grid[temp+2] != 0)
                {
                    if (isCharInArray(currRow, grid[temp+2])) return 0;
                    else addCharToArray(currRow, grid[temp+2]);
                }
            }
        }
    }
    return 1;
}

/*\brief checks that the rows, cols and boxes of the grid contains no duplicates
 * @param grid char[81] -- the array representing a 9 by 9 grid of charegers
 * @return int -- 1 if board is valid, 0 if board is NOT vaild
 */
int isBoardLegal(char grid[81])
{
    return checkRows(grid) && checkCols(grid) && checkBox(grid);
}


/*\brief sets the value of the grid at index i to value val
 * @param grid char[81] -- the array representing a 9 by 9 grid of charegers
 * @param i size_t -- index of the modified cell
 * @param val char -- the new value of the cell
 * @return void -- the given grid is modified in place
 */
void setCell(char grid[81], size_t i, char val)
{
    grid[i] = val;
}

/*\brief sets the values of the grid at index 'hard coded' values -ask Lancelot
 * @param grid char[81] -- the array representing a 9 by 9 grid of charegers
 * @return void -- the given grid is modified in place
 */
void setGrid(char grid[81])
{
    char newGrid[81] = {9, 2, 7,  0, 0, 0,  0, 0, 0,
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



/*\brief anex function of prettyPrint() - prints only 1 line with numbers
 * @param grid char[81] -- the array representing a 9 by 9 grid of charegers
 * @param start size_t -- the index of the start of the line
 * @return void
 */
void __prettyPrint(char grid[], size_t start)
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

/*\brief prints the given grid to the terminal
 * @param grid char[81] -- the array representing a 9 by 9 grid of charegers
 * @return void
 */
void prettyPrint(char grid[81])
{
    printf("╔═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╗\n");
    __prettyPrint(grid, 0);
    printf("╟───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
    __prettyPrint(grid, 9);
    printf("╟───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
    __prettyPrint(grid, 18);
    printf("╠═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣\n");
    __prettyPrint(grid, 27);
    printf("╟───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
    __prettyPrint(grid, 36);
    printf("╟───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
    __prettyPrint(grid, 45);
    printf("╠═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣\n");
    __prettyPrint(grid, 54);
    printf("╟───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
    __prettyPrint(grid, 63);
    printf("╟───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
    __prettyPrint(grid, 72);
    printf("╚═══╧═══╧═══╩═══╧═══╧═══╩═══╧═══╧═══╝\n");
}

void __uglyPrint(char grid[81], size_t i)
{
    if (81 < i) printf("\n");
    else
    {
        if (grid[i-1] == 0) printf(".");
        else printf("%i", grid[i-1]);
        if (i%3 == 0)
        {
            if (i != 0)
            {
                if (i%27 == 0 && i != 81) printf("\n");
                if (i%9 == 0 && i != 81) printf("\n");
                else printf(" ");
            }
        }
        __uglyPrint(grid, i+1);
    }
    
}


void uglyPrint(char grid[81])
{
    __uglyPrint(grid, 1);
}

int isBoardSolved(char grid[])
{
    for (size_t i = 0; i < 81; i++) if (grid[i] == 0) return 0;
    return isBoardLegal(grid);
}

/*\brief solves the grid with the backtraking method
 * @param grid char[81] -- the array representing a 9 by 9 grid of charegers
 * @param index size_t -- the index the the cell being modified - starts at 0
 * @return void -- the given grid is modified in place
 */
int __solve(char grid[81], size_t index)
{
    if (index == 81) return 1;
    if (grid[index] != 0) return __solve(grid, index+1);
    for (char i = 1; i < 10; i++)
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

/*\brief solves the grid with the backtraking method
 * @param grid char[81] -- the array representing a 9 by 9 grid of charegers
 * @return void -- the given grid is modified in place
 */
int solve(char grid[81])
{
    __solve(grid, 0);

    if (isBoardSolved(grid))
    {
        // printf("Grid is solvable\n");
        return 1;
    }
    else
    {
        // printf("Grid is not solvable\n");
        return 0;
    }
}

int loadSudoku(char grid[81], char path[])
{
    FILE* ptr;
    char ch = 0;
 
    // Open the file as a reader
    ptr = fopen(path, "r");

    size_t gridIndex = 0;
    while (ch != EOF && gridIndex < 81)
    {
        ch = fgetc(ptr);
        if (ch == '.')
        {
            gridIndex++;
        }
        else if (ch != ' ' && ch != '\n')
        {
            grid[gridIndex] = ch - '0';
            gridIndex++;
        }
    }
 
    // Closing the file
    fclose(ptr);
    return 0;
}

void mergeStrings(char s1[], char s2[])
{
    size_t i = 0;
	while (s1[i] != 0) i++;
	size_t j = 0;
	while (s2[j] != 0)
	{
		s1[i+j] = s2[j];
		j++;
	}
	s1[i+j] = 0;
}


int saveSudoku(char grid[81], char path[])
{
    FILE *fptr;

    char newpath[50] = "";
    char fileExtention[] = ".result";
    mergeStrings(newpath, path);
    mergeStrings(newpath, fileExtention);
    fptr = fopen(newpath,"w");
    for (size_t i = 1; i <= 81; i++)
    {
        fprintf(fptr, "%i", grid[i-1]);
        if (i%3 == 0)
        {
            if (i%27 == 0) fprintf(fptr, "\n");
            if (i%9 == 0 && i != 81) fprintf(fptr, "\n");
            else if (i != 81) fprintf(fptr, " ");
        }
        else if (i%3 == 0) fprintf(fptr, " ");
    }
    fclose(fptr);

    return 0;
}
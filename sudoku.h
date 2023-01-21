#pragma once
void prettyPrint(char grid[81]);
void uglyPrint(char grid[81]);
void setCell(char grid[81], size_t i, char val);
void setGrid(char grid[81]);
int solve(char grid[81]);
int loadSudoku(char grid[81], char path[]);
int saveSudoku(char grid[81], char path[]);
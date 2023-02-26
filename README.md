To run the code:
Oppen a terminal and nevigate to ```./SudokuSolver```
- To build the .exe, execute ```make```  in the terminal.
- To run the code: ```./main ./sudokuBoards/grid_0<0/1/2>```
    A correstponding ```./sudokuBoards/grid_0<0/1/2>.result``` will appear in the sudokuBoards directory
To view the grid: ```cat ./sudokuBoards/grid_0<0/1/2.result>```

The grid file format is as follows:
- 11 lines:
    - 9 lines of 11 characters;
    - 2 empty lines;
- empty cells are represented by dots (```.```)
- Horizontal lines are seperated by spaces every 3 character
- Vertical lines are seperated by empty lines every 3 lines

here is an exemple of a valid input grid and a valid result grid:
```
... ..4 58.
... 721 ..3
4.3 ... ...

21. .67 ..4
.7. ... 2..
63. .49 ..1

3.6 ... ...
... 158 ..6
... ..6 95.
```

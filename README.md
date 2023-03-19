To run the code:
Open a terminal and nevigate to ```./SudokuSolver```
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
INPUT:              OUTPUT:
... ..4 58.         127 634 589
... 721 ..3         589 721 643
4.3 ... ...         463 985 127

21. .67 ..4         218 567 394
.7. ... 2..         974 813 265
63. .49 ..1         635 249 871

3.6 ... ...         356 492 718
... 158 ..6         792 158 436
... ..6 95.         841 376 952
```

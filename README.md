# SudokuSolver

This is a sudoku solver solver which is written in C.
The sudoku solver solves the puzzle using heuristic method rather than backtracking method. The heuristic method reduces the time complexity comapared to the backtracking method

# File System 

The project is compiled and linked using CMake. The file structure consists of two main folders

* ### The include folder: 
        In this folder we store all the include header files. In this folder we have only one header file "sudoku.h". In this header file all stuctures and functions are declared.
    
* ### The src folder:
        In this folder we store all the source C files. In this folder we have 5 C files.
    * ##### sudoku.c:
            In this file we have the main function which takes the sudoku input and solves it and prints the input sudoku and the output sudoku. If the program can't solve the sudoku, it prints a ERROR message on the console.
    * ##### puzzle.c:
            
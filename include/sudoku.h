#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

extern int UNSOLVED;
extern int ROW_NUMS;
extern int COLUMN_NUMS;

typedef struct Box
{
    struct Box *next;
} Box;


typedef struct Square{
    int number;

    int possible[9]; //The possible numbers in which the 1 means not posiible, 0 means posbbile 
    //for the particular position
    // 0 0 0 0 0 0 0 0 0     
    // 9 8 7 6 5 4 3 2 1 (indices), here all numbers are possilbe in the code 000000000
    int solvable; //no of possible numbers to put in the cell
    int row;
    int column;
    Box *box;
} Square;

int **createPuzzle();
Square ***setUpPuzzle(int**); 
//void solvePuzzle(int **puzzle);
//bool solve(int, int, int, int**);
void printPuzzle(Square***);
void checkPuzzle(Square***);
int solveSquare(Square *square);
int updateSudoku(Square ***sudoku, int row, int column);

#endif
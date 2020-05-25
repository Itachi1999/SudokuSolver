#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



extern char IMPOSSIBLE; //111111111, if the code is 0x1FF, no another number is possible
extern int ROW_NUMS;
extern int COLUMN_NUMS;

typedef struct Box
{
    struct Box *next;
} Box;


typedef struct Square{
    int number;

    char code; //The possible numbers in which the 1 means not posiible, 0 means posbbile 
    //for the particular position
    // 000000000
    // 987654321, here all numbers are possilbe in the code 000000000

    int row;
    int column;
    Box *box;
} Square;

int **createPuzzle();
Square ***setUpPuzzle(int**); 
//void solvePuzzle(int **puzzle);
//bool solve(int, int, int, int**);
void printPuzzle(int**);


#endif
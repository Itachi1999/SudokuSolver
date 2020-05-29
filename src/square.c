#include "sudoku.h"

int solveSquare(Square *square){
    int i = 0;

    for (i = 0; i < ROW_NUMS; i++)
    {
        if (square -> possible[i] == 0)
        {
            square -> number = i + 1;
            square -> solvable = 0;
            UNSOLVED--;
        }
        
    }
}
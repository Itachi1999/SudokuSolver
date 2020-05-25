#include "sudoku.h"

int ROW_NUMS = 9;
int COLUMN_NUMS = 9;


int main(){
    int **puzzle;
    //printf("Henlo from main1");
    puzzle = createPuzzle();
    printPuzzle(puzzle);
    //printf("Henlo from main2");
    //solvePuzzle(puzzle);
    //printPuzzle(puzzle);
    //printf("Hello World, learing Github");
    free(puzzle);
    return 0;
}
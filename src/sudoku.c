#include "sudoku.h"

int UNSOLVED = 81;
int ROW_NUMS = 9;
int COLUMN_NUMS = 9;


int main(){
    int **puzzle;
    Square ***sudoku;
    //printf("Henlo from main1");
    puzzle = createPuzzle();
    //printf("Henlo from main2");
    //solvePuzzle(puzzle);
    //printPuzzle(puzzle);
    //printf("Hello World, learing Github");
    sudoku = setUpPuzzle(puzzle);
    printPuzzle(sudoku);

    printf("\n\n");
    checkPuzzle(sudoku);
    printPuzzle(sudoku);
    free(puzzle);
    free(sudoku);
    return 0;
}
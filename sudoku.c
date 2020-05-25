#include "sudoku.h"

int main(){
    int **puzzle;
    //printf("Henlo from main1");
    puzzle = createPuzzle();
    printPuzzle(puzzle);
    //printf("Henlo from main2");
    solvePuzzle(puzzle);
    printPuzzle(puzzle);
    //printf("Hello World, learing Github");
    free(puzzle);
    return 0;
}
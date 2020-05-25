#include "sudoku.h"

int main(){
    int **puzzle;
    //printf("Henlo from main1");
    puzzle = createPuzzle();
    //printf("Henlo from main2");
    printPuzzle(puzzle);
    //printf("Hello World, learing Github");
    //free(puzzle);
    return 0;
}
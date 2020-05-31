#include "sudoku.h"

int UNSOLVED = 81;
int ROW_NUMS = 9;
int COLUMN_NUMS = 9;


int main(){
    int **puzzle;
    int progress = 0;
    Sudoku *sudoku;
    //printf("Henlo from main1");
    puzzle = createPuzzle();
    //printf("Henlo from main2");
    //solvePuzzle(puzzle);
    //printPuzzle(puzzle);
    //printf("Hello World, learing Github");
    sudoku = setUpPuzzle(puzzle);
    printPuzzle(sudoku -> squares);

    printf("\n\n");
    while(UNSOLVED){
        progress = checkPuzzle(sudoku -> squares, sudoku -> boxes);
        if(progress == 0)
        {
            printf("Can't solve the puzzle\n");
            break;
        }
    }
    printPuzzle(sudoku -> squares);
    free(puzzle);
    free(sudoku);
    return 0;
}
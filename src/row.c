#include "sudoku.h"

int checkRows(Square ***sudoku){
    int i = 0, j = 0, x = 0;
    int sum_possible[9] = {0}, place[9] = {0};

    //check all rows to see if any number has only one square to fit in the row
    for (i = 0; i < ROW_NUMS; i++)
    {
        //initialise the array as zero for each row
        for(j = 0; j < COLUMN_NUMS; j++){
            sum_possible[j] = 0;
            place[j] = 0;
        }

        //check all squares in the row
        for (j = 0; j < COLUMN_NUMS; j++)
        {
            if(sudoku[i][j] -> number != 0)
                continue;

            
            //if not number == 0 the check for all numbers for posibilities
            for(x = 0; x < 9; x++){

                //check for all numberss
                if(sudoku[i][j] -> possible[x] == 0)
                {
                    sum_possible[x]++;
                    place[x] = j;
                }
            }
        }
        
        for(x = 0; x < 9; x++){
            if(sum_possible[x] == 1){
                sudoku[i][place[x]] -> number = x + 1;
                sudoku[i][place[x]] -> solvable = 0;
                UNSOLVED--;

                updateSudoku(sudoku, i, place[x]);
                updateBoxes(sudoku, i, place[x]);

                return 1;
            }
        }
    }
    return 0;
}
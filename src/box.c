#include "sudoku.h"


int boxSingles(Square ***sudoku, Box **boxes){
    int i = 0, j = 0, x = 0;
    int temp = 0, count = 0;

    //loop through all boxes
    for (i = 0; i < 9; i++)
    {
        //loop through all numbers possible
        for (j = 0; j < 9; j++)
        {
            count = 0;
            //loop through all sqaures
            for(x = 0; x < 9; x++){
                if(boxes[i] -> squares[x] ->number != 0)
                    continue;

                if(boxes[i] -> squares[x] -> possible[j] == 0){
                    count++;
                    temp = x;
                }

                if(count == 2)
                    break;
            }

            if(count == 1){
                boxes[i] -> squares[temp] -> number = j + 1;
                UNSOLVED--;
                boxes[i] -> squares[temp] -> solvable = 0;

                updateSudoku(sudoku, boxes[i] -> squares[temp] -> row, boxes[i] -> squares[temp] -> column);
                //Don't need the updateboxes function because the number is not possibl in other boxes
                //updateBoxes(sudoku, boxes[i] -> squares[temp] -> row, boxes[i] -> squares[temp] -> column);
                
                //if it solves something
                return 1;
            }
        }   
    }
    //if it doesn't solve anything
    return 0;
}

Box **createBoxes(){
    Box **boxes;
    int i = 0, j = 0;

    boxes = (Box**)malloc(sizeof(Box*) * 9); //9 boxes in total
    for (i = 0; i < 9; i++)
    {
        boxes[i] = (Box*)malloc(sizeof(Box));
        boxes[i] -> squares = (Square**)malloc(sizeof(Square*) * 9);
        boxes[i] -> numbers = 0;
        boxes[i] -> solvable = 9;

        for (j = 0; j < 9; j++)
        {
            boxes[i] -> possible[j] = 0;
        }
        
    }
    return boxes;
}


int updateBoxes(Square ***sudoku, int row, int column){
    int i = 0;
    int number = sudoku[row][column] -> number;
    Box *box = sudoku[row][column] -> box;

    for (i = 0; i < 9; i++)
    {
        if (box -> squares[i] -> possible[number - 1] == 0)
        {
            box -> squares[i] -> solvable--;
            box -> squares[i] -> possible[number - 1] = 1;
        }
        
    }
    return 0;
}
#include "sudoku.h"

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
    
}
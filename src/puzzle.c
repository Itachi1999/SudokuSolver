#include "sudoku.h"


int **createPuzzle(){
    int **puzzle; 
    int i = 0, j = 0;
    int array[9][9] = {0, 1, 9,      0, 0, 2,       0, 0, 0,
                       4, 7, 0,      6, 9, 0,       0, 0, 1,
                       0, 0, 0,      4, 0, 0,       0, 9, 0,
                       
                       8, 9, 4,      5, 0, 7,       0, 0, 0,
                       0, 0, 0,      0, 0, 0,       0, 0, 0,
                       0, 0, 0,      2, 0, 1,       9, 5, 8,
                       
                       0, 5, 0,      0, 0, 6,       0, 0, 0,
                       6, 0, 0,      0, 2, 8,       0, 7, 9,
                       0, 0, 0,      1, 0, 0,       8, 6, 0,};

    //printf("Henlo from createpuzzle1");
    puzzle = (int **)malloc(sizeof(int*) * 9);
    //printf("Henlo from createpuzzle2");
    for(i = 0; i < 9; i++){
        puzzle[i] = (int*)malloc(sizeof(int) * 9);
        for(j = 0; j < 9; j++){
            puzzle[i][j] = array[i][j];
        }
    }
    //printf("Henlo from createpuzzle");
    return puzzle;
}

void printPuzzle(int **puzzle){
    int i, j = 0;
    printf("--------------------------\n");
    for(i = 0; i < 9; i++){
        printf("| ");
        for(j = 0; j < 9; j++){
            printf("%d ", puzzle[i][j]);
            if((j + 1) % 3 == 0){
                printf("| ");
            }
        }
        printf("\n");
        if((i + 1) % 3 == 0){
            printf("------------------------\n");
        }
    }
}


Square*** setUpPuzzle(int **puzzle){
    Square ***sudoku;
    int i = 0, j = 0;

    for(i = 0; i < 9; i++){
        sudoku[i] = (Square**)malloc(sizeof(Square**) * 9);
        for(j = 0; j < 9; j++){
            sudoku[i][j] = (Square*)malloc(sizeof(Square*) * 9);
            
            
            sudoku[i][j] -> number = puzzle[i][j];
            sudoku[i][j] -> row = i;
            sudoku[i][j] -> column = j;
            
            if(puzzle[i][j]){
                sudoku[i][j] -> code = IMPOSSIBLE;
            }
            else
            {
                sudoku[i][j] -> code = 0x0;
            }
            
        }
    }
}

// bool solve(int i, int j, int n, int **puzzle){
//     int x = 0, y = 0, x_box = 0, y_box = 0;

//     //row checking
//     for(x = 0; x < 9; x++){
//         if(puzzle[i][x] == n){
//             return false;
//         }
//     }

//     for(x = 0; x < 9; x++){
//         if(puzzle[x][j] == n){
//             return false;
//         }
//     }

//     x_box = (i / 3) * 3;
//     y_box = (j / 3) * 3;

//     for(x = 0; x < 3; x++){
//         for(y = 0; y < 3; y++){
//             if(puzzle[x_box + i][y_box + j] == n){
//                 return false;
//             }
//         }
//     } 

//     return true;
// }

// void solvePuzzle(int** puzzle){
//     int i = 0, j = 0, n = 0;
//     printf("Solving");
//     for(i = 0; i < 9; i++){
//         printf("Solving i: %d ", i);
//         for (j = 0; j < 9; j++){
//             printf("Solving j: %d ", j);
//             if(puzzle[i][j] == 0){
//                 for(n = 1; n < 10; n++){
//                     if(solve(i, j, n, puzzle)){
//                         puzzle[i][j] = n;
//                         printf("Solving n: %d ", n);
//                         solvePuzzle(puzzle);
//                         puzzle[i][j] = 0;
//                     }
//                 }
//                 return; 
//             }
//         }
//     }
//    // return;
// }

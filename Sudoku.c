#include <stdio.h>

#include <stdbool.h>



#define N 9



void printGrid(int grid[N][N]) {

    for (int row = 0; row < N; row++) {

        for (int col = 0; col < N; col++) {

            printf("%d ", grid[row][col]);

        }

        printf("\n");

    }

}



bool isSafe(int grid[N][N], int row, int col, int num) {

    for (int x = 0; x < N; x++) {

        if (grid[row][x] == num)

            return false;

    }



    for (int x = 0; x < N; x++) {

        if (grid[x][col] == num)

            return false;

    }



    int startRow = row - row % 3;

    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            if (grid[i + startRow][j + startCol] == num)

                return false;

        }

    }



    return true;

}



bool solveSudoku(int grid[N][N]) {

    int row, col;

    bool emptyFound = false;



    for (row = 0; row < N; row++) {

        for (col = 0; col < N; col++) {

            if (grid[row][col] == 0) {

                emptyFound = true;

                break;

            }

        }

        if (emptyFound)

            break;

    }



    if (!emptyFound)

        return true;



    for (int num = 1; num <= 9; num++) {

        if (isSafe(grid, row, col, num)) {

            grid[row][col] = num;  



            if (solveSudoku(grid))

                return true;



            grid[row][col] = 0;  

        }

    }



    return false;  // Trigger backtracking

}



int main() {

    int grid[N][N];

    printf("Enter the Sudoku grid (enter 0 for empty cells):\n");



    for (int i = 0; i < N; i++) {

        for (int j = 0; j < N; j++) {

            scanf("%d", &grid[i][j]);

        }

    }



    if (solveSudoku(grid)) {

        printf("\nSolved Sudoku Puzzle:\n");

        printGrid(grid);

    } else {

        printf("\nNo solution exists for the given Sudoku puzzle.\n");

    }



    return 0;

}


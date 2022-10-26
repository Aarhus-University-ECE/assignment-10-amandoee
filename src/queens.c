//Program til at løse 8-queens problemet. !!Github CO-Pilot er blevet anvendt til denne ogpave!!

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Initialize 8x8 array array with 0's
int array[8][8] = {0};

//Function to print array
void printarray() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

//Function to check if queen can be placed in array
bool check(int row, int col) {
    int i, j;

    //Check if there is a queen in the same column
    for (i = 0; i < row; i++) {
        if (array[i][col] == 1) {
            return false;
        }
    }

    //Check if there is a queen in the upper left diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (array[i][j] == 1) {
            return false;
        }
    }

    //Check if there is a queen in the upper right diagonal
    for (i = row, j = col; i >= 0 && j < 8; i--, j++) {
        if (array[i][j] == 1) {
            return false;
        }
    }

    return true;
}


//Recursive function to place queens in array
bool placeQueen(int row) {
    //If all queens are placed, return true
    if (row == 8) {
        return true;
    }

    //Place queen in each column of the current row
    for (int i = 0; i < 8; i++) {
        //Check if queen can be placed in array
        if (check(row, i)) {
            //Place queen in array
            array[row][i] = 1;

            //Check if queen can be placed in the next row
            if (placeQueen(row + 1)) {
                return true;
            }

            //If queen cannot be placed in the next row, remove queen from array
            array[row][i] = 0;
        }
    }

    return false;
}

//Function to print array with queens and their possible moves
void printQueens() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            //Print queen
            if (array[i][j] == 1) {
                printf("Q ");
            } else if (array[i][j] == 2) {
                //Print possible moves
                printf("X ");
            }           
            //Print empty space
            else {
                printf(". ");
            }


        }
        printf("\n");
    }
}


//Function to place all queens if possible
void solve() {
    //If all queens can be placed, print array
    if (placeQueen(0)) {
        //print array with colors

        printQueens();

    } else {
        printf("Ingen løsning");
    }
}

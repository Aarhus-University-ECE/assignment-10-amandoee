#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



//create 8x8 board with all values set to 0
int board[8][8] = {0};


//Function to print board
void printBoard(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }}

//Function to calculate maximum amount of knights on a nxm board

int maxKnights(int n, int m){
    int max = 0;
    if(n == 1 || m == 1){
        max = 1;
    }
    else if(n == 2 || m == 2){
        if(n == 2){
            max = m/4*4 + (m%4 == 1 ? 2 : (m%4 >= 2 ? 4 : 0));
        }
        else{
            max = n/4*4 + (n%4 == 1 ? 2 : (n%4 >= 2 ? 4 : 0));
        }
    }
    else{
        max = (n*m+1)/2;
    }
    return max;
}

//Function to place knights on board without attacking eachother and return amount of knights placed
int placeKnights(int n, int m, int x, int y, int knightsPlaced){
    //If all knights are placed, return amount of knights placed
    if(knightsPlaced == maxKnights(n, m)){
        return knightsPlaced;
    }
    //If knight is placed on a square that is already occupied, return amount of knights placed
    else if(board[x][y] == 1){
        return knightsPlaced;
    }
    //If knight is placed on a square that is not already occupied, place knight and mark all squares that it can attack
    else{
        board[x][y] = 1;
        knightsPlaced++;
        //Mark squares that the knight can attack
        if(x+2 < n && y+1 < m){
            board[x+2][y+1] = 2;
        }
        if(x+2 < n && y-1 >= 0){
            board[x+2][y-1] = 2;
        }
        if(x-2 >= 0 && y+1 < m){
            board[x-2][y+1] = 2;
        }
        if(x-2 >= 0 && y-1 >= 0){
            board[x-2][y-1] = 2;
        }
        if(x+1 < n && y+2 < m){
            board[x+1][y+2] = 2;
        }
        if(x+1 < n && y-2 >= 0){
            board[x+1][y-2] = 2;
        }
        if(x-1 >= 0 && y+2 < m){
            board[x-1][y+2] = 2;
        }
        if(x-1 >= 0 && y-2 >= 0){
            board[x-1][y-2] = 2;
        }
        //Place knights on all squares that are not already occupied or marked
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] != 2 && board[i][j] != 1){
                    knightsPlaced = placeKnights(n, m, i, j, knightsPlaced);
                }
            }
        }
        return knightsPlaced;
    }
}

//Print board with knights placed
void printKnights(int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 1){
                printf("K ");
            }
            else{
                printf(". ");
            }
        }
        printf("\n");
    }
}


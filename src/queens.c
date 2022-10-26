//Program til at løse 8-queens problemet. !!Github CO-Pilot er blevet anvendt til denne ogpave!!

//Nøglen til at løse dette problem er at indse, at der må være én queen per række og kolonne.
//Derfor kan vi løse problemet ved at løbe igennem hver række og kolonne.
//Dette gøres rekursivt, hvor vi starter med at sætte en queen i den første række og kolonne, og derefter forsøger at sætte en queen i næste række og kolonne osv. osv. Hvis næste skridt fejler, skal den forrige queen flyttes til næste kolonne, og så prøves der igen.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int array[8][8] = {0};

//Funktion til at printe array. Benyttes til debugging.
void printarray() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

//Funktion der tjekker om queen kan placeres i en given placering.
bool check(int row, int col) {
    int i, j;

    //Tjek om der er en queen i samme række og kolonne.
    for (i = 0; i < row; i++) {
        if (array[i][col] == 1) {
            return false;
        }
    }

    //Tjek om der er en queen i venstre øvre diagonal. Behøves kun tjekke opad
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (array[i][j] == 1) {
            return false;
        }
    }

    //Tjek om der er en queen i højre øvre diagonal
    for (i = row, j = col; i >= 0 && j < 8; i--, j++) {
        if (array[i][j] == 1) {
            return false;
        }
    }

    return true;
}


//Funktion der tjekker muligheder, indtil det gælder at der er en dronning i alle 8 rækker.
bool placeQueen(int row) {
    //Hvis alle dronninger er placeret, returner true.
    if (row == 8) {
        return true;
    }

    //Placer dronning i alle kolonner i en given række.
    for (int i = 0; i < 8; i++) {
        //Check if queen can be placed in array
        if (check(row, i)) {
            array[row][i] = 1;

            //Check om dronning kan placeres i næste række også. Rekursivt, så for alle rækker til en given kombination.
            if (placeQueen(row + 1)) {
                return true;
            }

            //Hvis dronningen ikke kunne placeres i rækken efter, så fjern dronningen og prøv næste kolonne.
            array[row][i] = 0;
        }
    }

    return false;
}

//Printer løsningen med Q for dronning og - for tom plads.
void printQueens() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            //Print queen
            if (array[i][j] == 1) {
                printf("Q ");
            } 

            //Print tomrum
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

        printQueens();

    } else {
        printf("Ingen løsning");
    }
}

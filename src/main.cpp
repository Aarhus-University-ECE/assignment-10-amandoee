extern "C"{
    // Add the header files required to run your main 

    #include "queens.c"
    #include "knights.c"

}

// File for sandboxing and trying out code
int main(int argc, char **argv)
{
    
    //Løser problemet og printer board for queens.
    printf("\n");
    printf("Queens:\n");
    solve();
    
    printf("\n");

    //Løser problemet og printer board for knights. Virker ikke som det skal... Af en eller anden grund.
    printf("Knights (Maximum being %d):\n", maxKnights(8, 8));

    bool solved = false;
    for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                board[i][j] = 1;
                if (placeKnights(8, 8, 0, 0, 0) == maxKnights(8, 8)){
                    printBoard();
                    return 0;
                } else {
                    //reset board
                    for(int i = 0; i < 8; i++){
                        for(int j = 0; j < 8; j++){
                            board[i][j] = 0;
                        }
                    }
                }
            }
        }

    //printKnights(8, 8);
    if (!solved){
        printf("Korrekt løsning ikke fundet \n");
    }

    printf("\n");

    return 0;
}
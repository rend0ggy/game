#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Game.h"
static int diceThrow (Game g);

int main (int argc, char * argv[]){

    int discipline[19] = DEFAULT_DISCIPLINES;
    int dice[19] = DEFAULT_DICE;
    Game g = newGame(discipline, dice);
    int gameAlive = TRUE;
    int turnOver = FALSE;
    action move;

    while(gameAlive == TRUE){
        int diceValue = 0;
        diceValue = diceThrow(g);
        diceValue += diceThrow(g);
        throwDice (g, diceValue);
        
        int whoseTurn = getWhoseTurn(g);
        printf("It is player %d's turn\n", whoseTurn);
        turnOver = FALSE;
        
        // player chooses action
        // while loop:
        // save action in actionCode
        // check if legal
        // change game state
        // 
        // following while loop not working yet --> fixing Game.c (finishing/fixing functions)
        while (turnOver != TRUE){
            move.actionCode = PASS;
            if (move.actionCode == PASS){
                turnOver = TRUE;
            }
        }
    }
    
    return EXIT_SUCCESS;
}


static int diceThrow (Game g){
    time_t t;
    int dice = 0;
    
    srand((unsigned) time(&t));
    dice = (1 + rand() % DICE_SIZE);
    
    return dice;
}

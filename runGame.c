#include "Game.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char * argv[]){
    Game game = newGame();
    int gameAlive = TRUE;
    while(gameAlive == TRUE){
        int diceValue = diceThrow(game); //diceThrow is in Game.c
        rollDice (game, diceValue);
        
        int whoseTurn = getWhoseTurn(game);
        printf("It is player %d's turn\n", whoseTurn);
        
        // player chooses action
        // while loop:
        // save action in actionCode
        // check if legal
        // change game state
        // 
        // following while loop not working yet --> fixing Game.c (finishing/fixing functions)
        while (playerturn notover){
            int action = 0;
            printf("Choose an action:\n");
            scanf("%d", &action);
            player->a.actionCode = action;
            makeAction(game, action);
        }
    }
    
    return EXIT_SUCCESS;
}

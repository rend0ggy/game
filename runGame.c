#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Game.h"

//
int main (int argc, char * argv[]){
    int disciplines[] = DEFAULT_DISCIPLINES;
    int dice[] = DEFAULT_DICE;
    Game g = newGame (disciplines, dice);
    int gameAlive = TRUE;
    while(gameAlive == TRUE){

        int diceValue = diceThrow();
        diceValue += diceThrow();
        printf("%d\n",diceValue);
        throwDice (g, diceValue);
        
        int whoseTurn = getWhoseTurn(g);
        printf("It is player %d's turn\n", whoseTurn);
        
        // player chooses action
        // while loop:
        // save action in actionCode
        // check if legal
        // change game state
        // 
        // following while loop not working yet --> fixing Game.c (finishing/fixing functions)
        //action tmpAct;
        action a;
        while (TRUE){
            // initialize variables
            int i = 0;
            int actionChoice = 0;
            path movePath = {'0'};
            char currentMove;
            int disciplineFrom;
            int disciplineTo;

            printf("Choose an action:\n");
            
            scanf("%d", &actionChoice);
            scanf("%s",movePath);


            scanf("%d", &disciplineFrom);
            scanf("%d", &disciplineTo);

            a.actionCode = actionChoice;
            memcpy(a.destination,movePath,PATH_LIMIT);
            a.disciplineFrom = disciplineFrom;
            a.disciplineTo = disciplineTo;
            
            makeAction(g, a);
        }
    }
    
    return EXIT_SUCCESS;
}

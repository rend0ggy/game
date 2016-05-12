#include "Game.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  Game game = newGame();
  int gameAlive = TRUE;
  while(gameAlive == TRUE)
  {
    int diceValue = diceThrow();
    diceValue += diceThrow();
    rollDice(game,diceValue);
    int whoseTurn = getWhoseTurn(game);
    printf("It is player %d's turn\n",whoseTurn);
  }
};

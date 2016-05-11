#include <stdio.h>
#include <stdlib.h>
#include "Game.h"

typedef struct _board{
        int regions[19];     //(purple, yellow yellow;
        int roll[19];        //(6 10 8;
}board;

typedef struct _player{
    int numPlayer;
        position posCampuses[];
        position posArcGrants[];
        int kpi;
        int numArcs;
        int numCampuses;
        int numGo8;
        int numPatents;
        int numPapers;
        int numTHD;
        int numBPS;
        int numBQN;
        int numMJ;
        int numMTV;
        int numMMONEY;
}player;

struct _game{
    board Board;
    player A;
    player B;
    player C;
    int numTurn;
    int currentTurn;
};

typedef struct _position{
        int x;
        int y;
        int direction;
}position;


char _path{
    char path[PATH_LIMIT];
};

Game newGame (int discipline[], int dice[])
{
    Game g = (Game) malloc(sizeof(struct_game));
    g->discipline = discipline;
    g->dice = dice;
    g->currentTurn = -1;


    return g;
}

// free all the memory malloced for the game
void disposeGame (Game g){
    free(g);
}

// make the specified action for the current player and update the 
// game state accordingly.  
// The function may assume that the action requested is legal.
// START_SPINOFF is not a legal action here
void makeAction (Game g, action a){
    while(isLegalAction() == TRUE){
        if (a== PASS){
            g->numTurn++;
        } else if (a==  BUILD_CAMPUS){
            isLegalAction();
        } else if (a== BUILD_GO8){
            isLegalAction();        
        } else if (a== OBTAIN_ARC){
            isLegalAction();        
        } else if (a== START_SPINOFF){
            isLegalAction();        
        } else if (a== OBTAIN_PUBLICATION){
            isLegalAction();        
        } else if (a== OBTAIN_IP_PATENT){
            isLegalAction();        
        } else if (a== RETRAIN_STUDENTS){
            isLegalAction();        
        }
    }
}

// advance the game to the next turn, 
// assuming that the dice has just been rolled and produced diceScore
// the game starts in turn -1 (we call this state "Terra Nullis") and 
// moves to turn 0 as soon as the first dice is thrown. 
void throwDice (Game g, int diceScore){
    if (diceScore > 0){
        g->numTurn ++;
    }
// in main function declare numTurn starts at -1

}

// what type of students are produced by the specified region?
// regionID is the index of the region in the newGame arrays (above) 
// see discipline codes above
int getDiscipline (Game g, int regionID){
    int i = regionID;
    int discipline = 0;
    discipline = discipline[i]
    
    return student;
}

// what dice value produces students in the specified region?
// 2..12
int getDiceValue (Game g, int regionID){
    int i = regionID;
    int diceValue = 0;
    diceValue = dice[i];
    
    return diceValue;
}

// which university currently has the prestige award for the most ARCs?
// this is NO_ONE until the first arc is purchased after the game 
// has started.  
int getMostARCs (Game g){

    return 0;
}

// which university currently has the prestige award for the most pubs?
// this is NO_ONE until the first publication is made.
int getMostPublications (Game g)
{
    if (g->numPapers == 0)
    {
        return NO_ONE;
    }

    int max = g->player[0].numPapers;

    for (int i = 0; i < numPlayer; ++i)
    {
        if (g->player[i].numPapers > max)
        {
            max = g->player[i].numPapers;
        }
    }
    return max;
}
// return the current turn number of the game -1,0,1, ..
int getTurnNumber (Game g){
    int turn = 0;
    turn = g->numTurn;

    return turn;
}

// return the player id of the player whose turn it is 
// the result of this function is NO_ONE during Terra Nullis
int getWhoseTurn (Game g){
    int whoseTurn = 0;
    int turn = getTurnNumber(g);
    if (getTurnNumber%3 == 0){
        whoseTurn = UNI_A;
    } else if (getTurnNumber%3 == 1){
        whoseTurn = UNI_B;
    } else if (getTurnNumber%3 == 2){
        whoseTurn = UNI_C;
    }

    return whoseTurn;
}

//
 return the contents of the given vertex (ie campus code or 
// VACANT_VERTEX)
int getCampus(Game g, path pathToVertex){

    return 0;
}

// the contents of the given edge (ie ARC code or vacent ARC)
int getARC(Game g, path pathToEdge){

    return 0;
}

// returns TRUE if it is legal for the current
// player to make the specified action, FALSE otherwise.
//
// "legal" means everything is legal: 
//   * that the action code is a valid action code which is legal to 
//     be made at this time
//   * that any path is well formed and legal ie consisting only of 
//     the legal direction characters and of a legal length, 
//     and which does not leave the island into the sea at any stage.
//   * that disciplines mentioned in any retraining actions are valid 
//     discipline numbers, and that the university has sufficient
//     students of the correct type to perform the retraining
//
// eg when placing a campus consider such things as: 
//   * is the path a well formed legal path 
//   * does it lead to a vacent vertex?
//   * under the rules of the game are they allowed to place a 
//     campus at that vertex?  (eg is it adjacent to one of their ARCs?)
//   * does the player have the 4 specific students required to pay for 
//     that campus?
// It is not legal to make any action during Terra Nullis ie 
// before the game has started.
// It is not legal for a player to make the moves OBTAIN_PUBLICATION 
// or OBTAIN_IP_PATENT (they can make the move START_SPINOFF)
// you can assume that any pths passed in are NULL terminated strings.
int isLegalAction (Game g, action a){
    int legal = 0;
    
    if (a== BUILD_CAMPUS){
        if (player.numBPS >= 1 && player.numBQN >= 1 && player.numMJ >= 1 && player.numMTV >= 1){
            legal = TRUE;
        }
    }
    
    if (a== BUILD_GO8){
        if (player.numMJ >= 2 && player.numMMONEY >= 3){
            legal = TRUE;
       }
    }
    
    if (a== OBTAIN_ARC){
        if (player.numBPS >= 1 && player.numBQN >= 1){
            legal = TRUE;
        }
    }
      
    if (a== START_SPINOFF)
      
    if (a== OBTAIN_PUBLICATION)
   
    if (a== OBTAIN_IP_PATENT)
            
    if (a== RETRAIN_STUDENTS){
        if (player.numBPS >= 3 || player.numBQN >= 3 || player.numMJ >= 3 
                || player.numMTV >= 3 || player.numMMONEY >= 3){
            legal = TRUE;
        }
    }
    return legal;
}

// --- get data about a specified player ---

// return the number of KPI points the specified player currently has
int getKPIpoints (Game g, int player){
    int points = player.kpi;

    return points;
}

// return the number of ARC grants the specified player currently has
int getARCs (Game g, int player){
    int numArcs = player.numArcs;

    return numArcs;
}

// return the number of GO8 campuses the specified player currently has
int getGO8s (Game g, int player){
    int numGo8 = player.Go8;

    return numGo8;
}

// return the number of normal Campuses the specified player currently has
int getCampuses (Game g, int player){
    int numCampus = player.numCampuses;

    return numCampus;
}

// return the number of IP Patents the specified player currently has
int getIPs (Game g, int player){
    int numPatents = player.numPatents;

    return numPatents;
}

// return the number of Publications the specified player currently has
int getPublications (Game g, int player){
    int numPapers = player.numPapers;

    return numPapers;
}

// return the number of students of the specified discipline type 
// the specified player currently has
int getStudents (Game g, int player, int discipline){
    

    return numStudents;
}

// return how many students of discipline type disciplineFrom
// the specified player would need to retrain in order to get one 
// student of discipline type disciplineTo.  This will depend 
// on what retraining centers, if any, they have a campus at.
int getExchangeRate (Game g, int player, 
                     int disciplineFrom, int disciplineTo){
    
    return 0;
}
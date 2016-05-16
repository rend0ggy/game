#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Game.h"

static int spinoffChance();

// create a new game and return to the main game loop
// The game structure stores all global information about the game
Game newGame (int discipline[], int dice[])
{
	Game tmp;
    Game g = malloc(sizeof(tmp));
    g->dice = 0;
    g->currentTurn = -1;
    // Set up the students
    g->A.numBPS = 3;
    g->B.numBPS = 3;
    g->C.numBPS = 3;
    g->A.numBQN = 3;
    g->B.numBQN = 3;
    g->C.numBQN = 3;
    g->A.numMTV = 1;
    g->B.numMTV = 1;
    g->C.numMTV = 1;
    g->A.numMJ = 1;
    g->B.numMJ = 1;
    g->C.numMJ = 1;
    g->A.numTHD = 0;
    g->B.numTHD = 0;
    g->C.numTHD = 0;
    g->A.numMMONEY = 1;
    g->B.numMMONEY = 1;
    g->C.numMMONEY =1;
    // Set up the campuses
    position po;

    g->A.campuses_pos[0] = po.mapref[0][0];
    g->A.campuses_pos[1] = po.mapref[2][20];
    g->B.campuses_pos[0] = po.mapref[-10][6];
    g->B.campuses_pos[1] = po.mapref[22][14];
    g->C.campuses_pos[0] = po.mapref[20][0];
    g->C.campuses_pos[1] = po.mapref[-8][16];

    //set up the board
    int i = 0;
    while(i < 19){
	    g->Board.regions[i] = discipline[i];
	    g->Board.roll[i] = dice[i];
	    i++;
    }
    return g;
}

// free all the memory malloced for the game
void disposeGame (Game g){
    free(g);
}

// make the specified action for the current player and update the 
// game state accordingly.  
// The function first tests whether the requested actoin is legal
// If the action is legal it then changes global game variables through each function
void makeAction (Game g, action a){
    //int currentPlayer = getWhoseTurn(g);
    if (isLegalAction(g, a) == TRUE){
        if (a.actionCode == PASS){
            g->numTurn++;
        } else if (a.actionCode ==  BUILD_CAMPUS){
            //buildCampus(Game g,player p);
        } else if (a.actionCode == BUILD_GO8){
            //buildGO8(Game g,player p);
        } else if (a.actionCode == OBTAIN_ARC){
            //buildARC(Game g, player p);
        } else if (a.actionCode == START_SPINOFF){
            int chance = spinoffChance();
            if (chance == 1){
               // buildIP(g, currentPlayer);
            } else {
               // buildPublication(g, currentPlayer);
            }
        } else if (a.actionCode == RETRAIN_STUDENTS){
            //retrainStudents(Game g,player p);
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

static int spinoffChance (){
    time_t t;
    int chance = 0;
    
    srand((unsigned) time(&t));
    chance = (1 + rand() % 3);
    
    return chance;
}

// what type of students are produced by the specified region?
// regionID is the index of the region in the newGame arrays (above) 
// see discipline codes above
int getDiscipline (Game g, int regionID){
    //int i = regionID;
    int discipline = 0;
    //discipline = discipline[i];
    
    return discipline;
}

// what dice value produces students in the specified region?
// 2..12
int getDiceValue (Game g, int regionID){
    //int i = regionID;
    int diceValue = 0;
    //diceValue = g.dice;
    
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
	int playerNumber = NO_ONE;
	return playerNumber;
}
// return the current turn number of the game -1,0,1, ..
int getTurnNumber (Game g){
    int numTurn = g->numTurn;
    return numTurn;
}

// return the player id of the player whose turn it is 
// the result of this function is NO_ONE during Terra Nullis
int getWhoseTurn (Game g){
    int currentPlayer;
    if (g->currentTurn == -1){
        currentPlayer = NO_ONE;
    } else {
        currentPlayer = (((g->currentTurn) % NUM_UNIS) + 1);
    }
    return currentPlayer;
}

//return the contents of the given vertex (ie campus code or 
// VACANT_VERTEX)
int getCampus(Game g, path pathToVertex){

    return 0;
}

int* regionAssociatedWithPOS(position p,int dice)
{
	// This function returns EVERY dice roll that would lead to a new student 
	// for a given campus (i.e. the number on the sorounding hexagons)
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


// Function returns a player from the game based on the player number given as input
player intToPlayerConversion(Game g, int playerNum){
	player p;
	if(playerNum == UNI_A) {
		p = g->A;
	}

	if(playerNum == UNI_B) {
		p = g->B;
	}

	if(playerNum == UNI_C) {
		p = g->C;
	}
	return p;
}

int isLegalAction (Game g, action a){
    int legal = 0;
    player p = intToPlayerConversion(g,getWhoseTurn(g));
    
    if (a.actionCode == BUILD_CAMPUS){
        if (p.numBPS >= 1 && p.numBQN >= 1 && p.numMJ >= 1 && p.numMTV >= 1){
            legal = TRUE;
        }
    }
    
    if (a.actionCode == BUILD_GO8){
        if (p.numMJ >= 2 && p.numMMONEY >= 3){
            legal = TRUE;
       }
    }
    
    if (a.actionCode == OBTAIN_ARC){
        if (p.numBPS >= 1 && p.numBQN >= 1){
            legal = TRUE;
        }
    }
      
    if (a.actionCode == START_SPINOFF)
    {
        if (p.numMJ >= 1 || p.numMTV >= 1 || p.numMMONEY >= 1)
        {
            legal = TRUE;
        }
    }
      
    if (a.actionCode == OBTAIN_PUBLICATION)
    {
        legal = TRUE;
    }
   
    if (a.actionCode == OBTAIN_IP_PATENT)
    {
        legal = TRUE;
    }
            
    if (a.actionCode == RETRAIN_STUDENTS){
        if (p.numBPS >= 3 || p.numBQN >= 3 || p.numMJ >= 3 
                || p.numMTV >= 3 || p.numMMONEY >= 3){
            legal = TRUE;
        }
    }
    return legal;
}

// --- get data about a specified player ---

// return the number of KPI points the specified player currently has
int getKPIpoints (Game g, player p){
    int points = p.kpi;
    return points;
}

// return the number of ARC grants the specified player currently has
int getARCs (Game g, player p){
    int numArcs = p.numArcs;

    return numArcs;
}

// return the number of GO8 campuses the specified player currently has
int getGO8s (Game g, player p){
    int numGo8 = p.numGo8;

    return numGo8;
}

// return the number of normal Campuses the specified player currently has
int getCampuses (Game g, player p){
    int numCampus = p.numCampuses;

    return numCampus;
}

// return the number of IP Patents the specified player currently has
int getIPs (Game g, player p){
    int numPatents = p.numPatents;

    return numPatents;
}

// return the number of Publications the specified player currently has
int getPublications (Game g, player p){
    int numPapers = p.numPapers;

    return numPapers;
}

// return the number of students of the specified discipline type 
// the specified player currently has
int getStudents (Game g, player p, int discipline){
    int numStudents = 0;
    numStudents += p.numTHD;
    numStudents += p.numBPS;
    numStudents += p.numBQN;
    numStudents += p.numMJ;
    numStudents += p.numMTV;

    return numStudents;
}

// return how many students of discipline type disciplineFrom
// the specified player would need to retrain in order to get one 
// student of discipline type disciplineTo.  This will depend 
// on what retraining centers, if any, they have a campus at.
int getExchangeRate (Game g, player p, int disciplineFrom, int disciplineTo)
{
    
    return 0;
}

int main(void)
{
	return 0;
}

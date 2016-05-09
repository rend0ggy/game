#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "Game.h"

#define DEFAULT_DISCIPLINES {STUDENT_BQN, STUDENT_MMONEY, STUDENT_MJ, \
                STUDENT_MMONEY, STUDENT_MJ, STUDENT_BPS, STUDENT_MTV, \
                STUDENT_MTV, STUDENT_BPS,STUDENT_MTV, STUDENT_BQN, \
                STUDENT_MJ, STUDENT_BQN, STUDENT_THD, STUDENT_MJ, \
                STUDENT_MMONEY, STUDENT_MTV, STUDENT_BQN, STUDENT_BPS}
                
#define DEFAULT_DICE {9,10,8,12,6,5,3,11,3,11,4,6,4,7,9,2,8,10,5}

void testGame(Game g);

int main (int argc, char* argv[]){

    int disciplines[] = DEFAULT_DISCIPLINES;
    int dice[] = DEFAULT_DICE;
    Game g = newGame (disciplines, dice);
    testGame(g);
    return EXIT_SUCCESS;
}

void testGame(Game g){
    
    printf("Testing initial conditions:");
    assert(getTurnNumber(g) == -1);
    
    assert (getDiscipline(g, 7) == STUDENT_MTV);
    assert (getDiceValue (g, 7) == 11);
  
    assert(getKPIpoints(g, UNI_A) == 24);
    assert(getKPIpoints(g, UNI_B) == 24);
    assert(getKPIpoints(g, UNI_C) == 24);
    
    assert(getMostARCs(g) == NO_ONE);
    assert(getMostPublications(g) == NO_ONE);
    assert(getWhoseTurn(g) == NO_ONE);
    
    printf("Testing for legal actions:");
    getARCs(g, UNI_A);
    assert(getKPIpoints(g, UNI_A) == 26);
    
    getGO8s(g, UNI_A);
    assert(getKPIpoints(g, UNI_A) == 46);
    
    getCampuses(g, UNI_A);
    assert(getKPIpoints(g, UNI_A) == 56);
    
    getIPs (g, UNI_A);
    assert(getKPIpoints(g, UNI_A) == 66);
    
    getPublications(g, UNI_A);
    assert(getKPIpoints(g, UNI_A) == 66);
}

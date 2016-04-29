#include "dominion.h"


int main() {
	  /*
	   * Assume player 1 has 5 cards then village card got used so total cards are 4.
	   * Then the player gets 1 card.
	   * Also, Actions increased by two
	   */
  struct gameState g;
  int cards[10] =
  {
		   estate,
		   duchy,
		   province,
		   copper,
		   silver,
		   gold,
		   adventurer,
		   great_hall,
		   minion,
		   steward
  };

  initializeGame(2, cards, 3, &g);
  int b[1];
  int HandCount = g.handCount[0];
  int currentAction = g.numActions;
  //printf("num actions %d\n",g.numActions);
  cardEffect(village,0, 0, 0, &g, 1, b);
  //printf("num actions %d\n",g.numActions);

  int HandCountAfter = g.handCount[0];
  int handDelta = (HandCountAfter - HandCount) + 1;
  int actionDelta = (g.numActions-currentAction);
  myassert(handDelta == 1, "USED village card but got no cards or got more than one card!");
  myassert(actionDelta == 2, "USED village card but got no action increase or got more than two actions!");

  checkasserts();
}

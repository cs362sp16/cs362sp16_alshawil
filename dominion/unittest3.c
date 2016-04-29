#include "dominion.h"


int main() {

  struct gameState g;
  int cards[10] = {
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
  int PlayCardStatus = playCard(0, 3,2, 1, &g);

  myassert(g.phase == 0, "In the wrong phase!");
  printf("Phase:%d\n",g.phase);
  printf("numActions:%d\n",g.numActions);
  myassert(g.numActions > 0, "No enough Actions!");

  myassert(PlayCardStatus == 0, "Player was not able to play card!");



  checkasserts();
}

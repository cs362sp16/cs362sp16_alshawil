#include "dominion.h"


int main() {
	  /*
	   * Assume player 1 has 5 cards then council_room card got used so total cards are 4.
	   * Then the player gets 4 cards.
	   * other players draw a card
	   * Also, buys increased by one
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
  int currentBuys = g.numBuys;
  //printf("Buys %d\n",g.numBuys);
  //cardEffect(great_hall,0, 0, 0, &g, 1, b);
  //council_roomCard(0,&g,0);

  //printf("Buys %d\n",g.numBuys);

  int handDelta = (g.handCount[0] - HandCount) + 1;
  int BuysDelta = (g.numBuys-currentBuys);
  //myassert(handDelta == 4, "USED council_roomCard card but got no cards or got more than one card!");
  //myassert(BuysDelta == 1, "USED council_roomCard card but got no action increase or got more than one action!");

  checkasserts();
  return 0;
}

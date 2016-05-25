#include "dominion.h"


int main() {

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
  cardEffect(smithy,0, 0, 0, &g, 1, b);
  /*
   * Assume player 1 has 5 cards then smithy card got used so total cards are 4. Then the player gets 3 cards.
   */
  int HandCountAfter = g.handCount[0];
  int delta = (HandCountAfter - HandCount) + 1;
  myassert(delta == 3, "USED smithy card but Did not get three cards!");

  checkasserts();
  return 0;
}

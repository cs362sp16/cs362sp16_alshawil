#include "dominion.h"


int main() {

  struct gameState g,g2;
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
  int ShuffleStatus = shuffle(0, &g);
  myassert(ShuffleStatus == 0, "Player 1 did not Shuffle");

  ShuffleStatus = shuffle(1, &g);
  myassert(ShuffleStatus == 0, "Player 2 did not Shuffle");

  int cards2[1] = {estate};
  initializeGame(2, cards2, 3, &g2);
  ShuffleStatus = shuffle(1, &g2);
  myassert(ShuffleStatus == -1, "Can't Shuffle one card?!");

  checkasserts();
}

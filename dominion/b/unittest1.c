#include "dominion.h"


int main() {

  struct gameState g;
  int cards[6] = {
		   estate,
		   duchy,
		   province,
		   copper,
		   silver,
		   gold
  };
  int GameStatus = initializeGame(2, cards, 3, &g);
  myassert(GameStatus == -1, "Can't Initlizize Game with missing cards!");

  int cards2[10] =
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

  GameStatus = initializeGame(2, cards2, 3, &g);
  myassert(GameStatus == 0, "Two players with 10 cards");

  int cards3[10] =
  {
		   estate,
		   duchy,
		   province,
		   copper,
		   silver,
		   gold,
		   adventurer,
		   great_hall,
		   steward,
		   steward
  };
  GameStatus = initializeGame(2, cards3, 3, &g);
  myassert(GameStatus == -1, "Duplicate Cards are not allowed for initilization!");


  checkasserts();
  return 0;
}

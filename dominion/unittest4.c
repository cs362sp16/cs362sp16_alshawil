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
  initializeGame(1, cards, 3, &g);
  int DeckCount = fullDeckCount(0,estate,&g);
  printf("DeckCount:%d\n",DeckCount);
  myassert(DeckCount == 0, "curse does not exist");

  DeckCount = fullDeckCount(0,steward,&g);
  myassert(DeckCount > 0, "There should be at least one steward card");

  DeckCount = fullDeckCount(0,minion,&g);
  myassert(DeckCount > 0, "There should be at least one minion card");

  DeckCount = fullDeckCount(0,province,&g);
  myassert(DeckCount > 0, "There should be at least one province card");
  int i;
  for(i=0; i < 10;i++)
  {
	  DeckCount = fullDeckCount(0,cards[i],&g);
	  myassert(DeckCount > 0, "There should be at least one card from the cards array");
  }

  checkasserts();
}

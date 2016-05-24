#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {
	struct gameState G,g;
	struct gameState *p = &G;

	int k[10][5] = {
			{adventurer, gardens, embargo, village, minion, mine, cutpurse,
					smithy, tribute, sea_hag}
			,
			{gardens,adventurer , embargo, village, minion, mine, cutpurse,
						sea_hag, tribute, smithy}
			,
			{adventurer, embargo , gardens, village, minion, mine, cutpurse,
						sea_hag, tribute, smithy}
			,
			{adventurer, tribute , embargo, village, minion, mine, cutpurse,
						sea_hag, gardens, smithy}
			,
			{sea_hag, mine , smithy, village, minion,tribute , cutpurse,
					adventurer, gardens, embargo}
	};

	printf ("Starting game.\n");


	int money = 0;
	int smithyPos = -1;
	int adventurerPos = -1;
	int i=0;

	int numSmithies = 0;
	int numAdventurers = 0;
	int loop;
	int num = 0;
	int cardsrand = 0;
	for(loop = 0; loop < 5;loop++)
	{
		struct gameState G,g;
		struct gameState *p = &G;
		num = 2 + (rand() % (int)(MAX_PLAYERS - 2 + 1));
		cardsrand = rand() % 4;
		initializeGame(num, k[cardsrand], atoi(argv[1]), p);
		money = 0;
		smithyPos = -1;
		adventurerPos = -1;
		i=0;
		numSmithies = 0;
		numAdventurers = 0;
		while (!isGameOver(p)) {
			money = 0;
			smithyPos = -1;
			adventurerPos = -1;
			for (i = 0; i < numHandCards(p); i++) {
				if (handCard(i, p) == copper)
					money++;
				else if (handCard(i, p) == silver)
					money += 2;
				else if (handCard(i, p) == gold)
					money += 3;
				else if (handCard(i, p) == smithy)
					smithyPos = i;
				else if (handCard(i, p) == adventurer)
					adventurerPos = i;
			}


			if (smithyPos != -1) {
				printf("0: smithy played from position %d\n", smithyPos);
				playCard(smithyPos, -1, -1, -1, p);
				printf("smithy played.\n");
				money = 0;
				i=0;
				while(i<numHandCards(p)){
					if (handCard(i, p) == copper){
						playCard(i, -1, -1, -1, p);
						money++;
					}
					else if (handCard(i, p) == silver){
						playCard(i, -1, -1, -1, p);
						money += 2;
					}
					else if (handCard(i, p) == gold){
						playCard(i, -1, -1, -1, p);
						money += 3;
					}
					i++;
				}
			}

			if (money >= 8) {
				printf("0: bought province\n");
				buyCard(province, p);
			}
			else if (money >= 6) {
				printf("0: bought gold\n");
				buyCard(gold, p);
			}
			else if ((money >= 4) && (numSmithies < 2)) {
				printf("0: bought smithy\n");
				buyCard(smithy, p);
				numSmithies++;
			}
			else if (money >= 3) {
				printf("0: bought silver\n");
				buyCard(silver, p);
			}

			printf("0: end turn\n");
			endTurn(p);
			printf ("Player 0: %d\nPlayer 1: %d\n", scoreFor(0, p), scoreFor(1, p));

		} // end of While

		printf ("Finished game.\n");
		printf ("Player 0: %d\nPlayer 1: %d\n", scoreFor(0, p), scoreFor(1, p));
		//memcpy ( p, &g, sizeof(struct gameState) );
	}

	return 0;
}

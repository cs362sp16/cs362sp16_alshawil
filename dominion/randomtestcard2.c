#include "dominion.h"
#define Limit 100
/*
 *
 * Random test for  steward card
 */
int main(int argc ,char** argv) {

	int Seed = atoi(argv[1]);
	SelectStream(3);
	PutSeed(Seed);
	int i,j,Players,is_failed,passed,failed,tests;
	int choice1,choice2,choice3;
	int bonus[1],resetbonus[1];
	int beforeHandCount,afterHandCount;
	int beforecoinsCount,aftercoinsCount;
	passed=failed=tests=0;

	struct gameState g,reset;
	int cards[10] ={estate,duchy,province,copper,silver,gold,adventurer,great_hall,minion,steward};

	//Test whether a player got +4 cards when council_room used
	for( i=0; i < Limit; i++)
	{
		//players between 2 and Max_players
		Players = 2 + (rand() % (int)(MAX_PLAYERS - 2 + 1));
		//printf("	Round %d with Players: %d\n",i,Players);
		initializeGame(Players, cards, Seed, &g);


		for (j = 0; j < Players; j++)
		{
			// choice can be [0,2]
			choice1 = rand() % 3;
			choice2 = rand() % g.handCount[j];
			choice3 = 0 + (rand() % (int)((g.handCount[j]-1) - 0 + 1));
			beforecoinsCount=aftercoinsCount=beforeHandCount=afterHandCount=0;
			//printf("		Player %d\n",j);
			//printf("			Before HandCount... %d\n",g.handCount[j]);
			beforeHandCount=g.handCount[j];
			beforecoinsCount = g.coins;
			cardEffect(steward,choice1, choice2, choice3, &g, 0, bonus);
			//printf("			After HandCount... %d\n",g.handCount[j]);
			afterHandCount=g.handCount[j];
			aftercoinsCount = g.coins;
			endTurn(&g);
			if(choice1==1)
			{
				// when choice 1. Current player get +2 cards
				is_failed=myassert((afterHandCount - beforeHandCount) == 1,"Test Failed: +2 cards");

			}else if(choice1==2)
			{
				//+2 coins
				is_failed=myassert((beforeHandCount - afterHandCount) == 1,"Test Failed: +2 coins.");

			}
			else
			{
				//trash 2 cards in hand.
				is_failed=myassert((beforeHandCount - afterHandCount ) == 3,"Test Failed: Trash 2 cards.");


			}
			if(is_failed)
			{
				failed = failed + 1;
			}
			else
			{
				passed = passed + 1;
			}
			tests = tests + 1;
			// reset bonus
			memcpy ( bonus, resetbonus, sizeof(bonus) );

		}
		// reset gameState struct
		memcpy ( &g, &reset, sizeof(struct gameState) );
	}

	float failedTests= ((float)failed/(float)tests)*100;
	float passedTests = ((float)passed/(float)tests)*100;
	printf("Passed: %d, Failed: %d\n",passed,failed);
	printf("Passed: %f%, Failed: %f\n",passedTests,failedTests);
	checkasserts();

	return 0;
}

#include "dominion.h"
#define Limit 10
/*
 *
 * Testing  council_room card already wrote a manual unit test in cardtest4.c
 */
int main(int argc ,char** argv) {

	int Seed = atoi(argv[1]);
	SelectStream(1);
	PutSeed(Seed);
	int i,j,k,Players,before,after,is_failed,passed,failed,tests;
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
			before=after=0;
			//printf("		Player %d\n",j);
			//printf("			Before HandCount... %d\n",g.handCount[j]);
			before=g.handCount[j];
			council_roomCard(j,&g,0);
			//printf("			After HandCount... %d\n",g.handCount[j]);
			after=g.handCount[j];
			endTurn(&g);
			is_failed=myassert((after - before) == 3,"Test Failed: The difference in handcount before and after using adventurer card is more or less than 4 cards.");
			if(is_failed)
			{
				failed = failed + 1;
			}
			else
			{
				passed = passed + 1;
			}
			tests = tests + 1;

		}

		memcpy ( &g, &reset, sizeof(struct gameState) );
	}
	//Test if numBuys increased
	for( i=0; i < Limit; i++)
	{
		//players between 2 and Max_players
		Players = 2 + (rand() % (int)(MAX_PLAYERS - 2 + 1));
		//printf("	Round %d with Players: %d\n",i,Players);
		initializeGame(Players, cards, Seed, &g);


		for (j = 0; j < Players; j++)
		{
			before=after=0;
			k = rand()%2;
			// randomly set numBuys to random number or leave as it is
			if(k)
			{
				g.numBuys =  2 + (rand() % (int)(Limit - 2 + 1));;
			}

			//printf("		Player %d\n",j);
			//printf("			Before numBuys... %d\n",g.numBuys);
			before=g.numBuys;
			council_roomCard(j,&g,0);
			//printf("			After numBuys... %d\n",g.numBuys);
			after=g.numBuys;
			endTurn(&g);
			is_failed=myassert((after - before) == 1,"Test Failed: The difference in numBuys before and after using council_room card is more or less than 1 buys.");
			if(is_failed)
			{
				failed = failed + 1;
			}
			else
			{
				passed = passed + 1;
			}
			tests = tests + 1;

		}

		memcpy ( &g, &reset, sizeof(struct gameState) );
	}
	float failedTests= ((float)failed/(float)tests)*100;
	float passedTests = ((float)passed/(float)tests)*100;
	printf("Passed: %d, Failed: %d\n",passed,failed);
	printf("Passed: %f%, Failed: %f\n",passedTests,failedTests);
	checkasserts();
	return 0;
}

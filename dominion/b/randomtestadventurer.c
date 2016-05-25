#include "dominion.h"
#define Limit 100
int main(int argc ,char** argv) {

	int Seed = atoi(argv[1]);
	SelectStream(1);
	PutSeed(Seed);
	int i,j,k,Players,before,after,is_failed,passed,failed,tests,r1;
	struct gameState g,reset;
	int cards[10] ={estate,duchy,province,copper,silver,gold,adventurer,great_hall,minion,steward};

	for( i=0; i < Limit; i++)
	{
		Players = 2 + (rand() % (int)(MAX_PLAYERS - 2 + 1));
		//printf("	Round %d with Players: %d\n",i,Players);
		initializeGame(Players, cards, Seed, &g);

		for(k=0; k< Limit/2;k++)
		{

			for (j = 0; j < Players; j++)
			{
				r1 = rand()%2;
				before=after=0;
				//printf("		Player %d\n",j);
				//printf("			Before HandCount... %d\n",g.handCount[j]);


				before=g.handCount[j];
				adventureCard(j,&g);
				//printf("			After HandCount... %d\n",g.handCount[j]);
				after=g.handCount[j];
				endTurn(&g);
				is_failed=myassert( ((before-after) == 1) ||((after - before) == 2) ||((after - before) == 1)||((after - before) == 0),"Test Failed: The difference in handcount before and after using adventurer card is more or less than 2 cards.");
				if(r1)
				{
					// This case will help to bring the total branch coverage to 100%
					g.deckCount[j]=0;
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


			}
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

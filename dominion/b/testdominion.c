#include "dominion.h"
#include "interface.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>
#define Limit 50
int isExist(int c, int *arr);
void randCard(int *k);
int main (int argc, char** argv) {
	struct gameState G,g;
	struct gameState *p = &G;
	//srand (time(NULL));
	int k[10];
	int money = 0;
	int i,j=i=0;
	int turn = 0;
	int loop;
	int num = 0;
	int cardsrand =0;
	int Seed = atoi(argv[1]);
	int winner[MAX_PLAYERS];
	int randomBuy = 0;
	int buycard = 1;
	SelectStream(1);
	PutSeed(Seed);
	for(loop = 0; loop <Limit;loop++)
	{
		randCard(k);
		num = 2 + (Random()* (int)(MAX_PLAYERS - 2 + 1));
		printf("Number of players in this game: %d\n",num);
		initializeGame(num, k, Seed, p);
		money = 0;
		i=0;
		turn = 0;
		while (!isGameOver(p)) {
			money = 0;

			printf("	#######START#######\n");
			printHand(turn,p);
			for (i = 0; i < numHandCards(p); i++) {
				if (handCard(i, p) == copper)
					money++;
				else if (handCard(i, p) == silver)
					money += 2;
				else if (handCard(i, p) == gold)
					money += 3;
			}

			for(i = 0; i < numHandCards(p); i++)
			{
				if (handCard(i, p) == smithy)
				{
					printf("	%d: smithy played from position %d\n", turn,i);
					playCard(i, 1, 1, 1, p);break;
				}

				else if (handCard(i, p) == adventurer)
				{
					printf("	%d: adventurer played from position %d\n", turn,i);
					playCard(i, -1, -1, -1, p);break;
				}
				else if (handCard(i, p) == council_room)
				{
					printf("	%d: council_room played from position %d\n", turn,i);
					playCard(i, -1, -1, -1, p);break;
				}
				else if (handCard(i, p) == village)
				{
					printf("	%d: village played from position %d\n", turn,i);
					playCard(i, 1, 1, 1, p);break;
				}
				else if (handCard(i, p) == gardens)
				{
					printf("	%d: gardens played from position %d\n", turn,i);
					playCard(i, 1, 1, 1, p);break;
				}
				else if (handCard(i, p) == embargo)
				{
					printf("	%d: embargo played from position %d\n", turn,i);
					playCard(i, 1, 1, 1, p);break;
				}
				else if (handCard(i, p) == minion)
				{
					printf("	%d: minion played from position %d\n", turn,i);
					playCard(i, 1, 1, 1, p);break;
				}
				else if (handCard(i, p) == mine)
				{
					printf("	%d: mine played from position %d\n", turn,i);
					playCard(i, 1, 1, 1, p);break;
				}
				else if (handCard(i, p) == cutpurse)
				{
					printf("	%d: cutpurse played from position %d\n", turn,i);
					playCard(i, 1, 1, 1, p);break;
				}
				else if (handCard(i, p) == sea_hag)
				{
					printf("	%d: sea_hag played from position %d\n", turn,i);
					playCard(i, 1, 1, 1, p);break;
				}
				else if (handCard(i, p) == tribute)
				{
					printf("	%d: tribute played from position %d\n", turn,i);
					playCard(i, 1, 1, 1, p);break;
				}
				else if (handCard(i, p) == baron)
				{
					printf("	%d: baron played from position %d\n", turn,i);
					playCard(i, 1, 1, 1, p);break;
				}
				else if (handCard(i, p) == great_hall)
				{
					printf("	%d: great_hall played from position %d\n", turn,i);
					playCard(i, 1, 1, 1, p);break;
				}
				else if (handCard(i, p) == ambassador)
				{
					printf("	%d: ambassador played from position %d\n", turn,i);
					playCard(i, 1, 1, 1, p);break;
				}
				else if (handCard(i, p) == ambassador)
				{
					printf("	%d: ambassador played from position %d\n", turn,i);
					playCard(i, 1, 1, 1, p);break;
				}
			}

			if(money >=8)
			{
				printf("	%d: bought province\n",turn);
				buyCard(province, p);
			}
			else if(money >=6)
			{
				randomBuy = Random() * 2;
				if(randomBuy==0)
				{
					printf("	%d: bought gold\n",turn);
					buyCard(gold, p);
				}
				else
				{
					printf("	%d: bought adventurer\n",turn);
					buyCard(adventurer, p);
				}
			}
			else if(money >=5)
			{
				randomBuy = Random() * 5;
				if(randomBuy==0)
				{
					printf("	%d: bought duchy\n",turn);
					buyCard(duchy, p);
				}
				else if(randomBuy==1)
				{
					printf("	%d: bought council_room\n",turn);
					buyCard(council_room, p);
				}
				else if(randomBuy==2)
				{
					printf("	%d: bought mine\n",turn);
					buyCard(mine, p);
				}
				else if(randomBuy==3)
				{
					printf("	%d: bought minion\n",turn);
					buyCard(minion, p);
				}
				else if(randomBuy==4)
				{
					printf("	%d: bought tribute\n",turn);
					buyCard(tribute, p);
				}
				else
				{
					printf("	%d: bought outpost\n",turn);
					buyCard(outpost, p);
				}
			}
			else if(money >=4)
			{
				randomBuy = Random() * 8;
				if(randomBuy==0)
				{
					printf("	%d: bought feast\n",turn);
					buyCard(feast, p);
				}
				else if(randomBuy==1)
				{
					printf("	%d: bought gardens\n",turn);
					buyCard(gardens, p);
				}
				else if(randomBuy==2)
				{
					printf("	%d: bought remodel\n",turn);
					buyCard(remodel, p);
				}
				else if(randomBuy==3)
				{
					printf("	%d: bought smithy\n",turn);
					buyCard(smithy, p);
				}
				else if(randomBuy==4)
				{
					printf("	%d: bought baron\n",turn);
					buyCard(baron, p);
				}
				else if(randomBuy==5)
				{
					printf("	%d: bought cutpurse\n",turn);
					buyCard(cutpurse, p);
				}
				else if(randomBuy==6)
				{
					printf("	%d: bought salvager\n",turn);
					buyCard(salvager, p);
				}
				else if(randomBuy==7)
				{
					printf("	%d: bought sea_hag\n",turn);
					buyCard(sea_hag, p);
				}
				else
				{
					printf("	%d: bought treasure_map\n",turn);
					buyCard(treasure_map, p);
				}
			}
			else if(money>=3)
			{
				randomBuy = Random() * 4;
				if(randomBuy==0)
				{
					printf("	%d: bought silver\n",turn);
					buyCard(silver, p);
				}
				else if(randomBuy==1)
				{
					printf("	%d: bought village\n",turn);
					buyCard(village, p);
				}
				else if(randomBuy==2)
				{
					printf("	%d: bought great_hall\n",turn);
					buyCard(great_hall, p);
				}
				else if(randomBuy==3)
				{
					printf("	%d: bought ambassador\n",turn);
					buyCard(ambassador, p);
				}


			}
			else if(money>=2)
			{
				randomBuy = Random() * 2;
				if(randomBuy==0)
				{
					printf("	%d: bought estate\n",turn);
					buyCard(estate, p);
				}
				else if(randomBuy==1)
				{
					printf("	%d: bought embargo\n",turn);
					buyCard(embargo, p);
				}
			}
			else
			{
				randomBuy = Random() * 2;
				if(randomBuy==0)
				{
					printf("	%d: bought curse\n",turn);
					buyCard(curse, p);
				}
				else if(randomBuy==1)
				{
					printf("	%d: bought copper\n",turn);
					buyCard(copper, p);
				}
			}
			printf("	randomBuy %d: \n",randomBuy);
			printf("	money %d: \n",money);

			printf("	player %d: end turn\n",turn);

			printf ("	Player %d: score:%d\n",turn, scoreFor(turn, p));
			printHand(turn,p);
			endTurn(p);
			printf("	#######END#######\n\n\n\n");
			turn = turn + 1;
			if(turn == (num))
			{
				turn = 0;
			}

		} // end of While

		getWinners(winner, p);
		printf ("	Finished game.\n");
		for(j = 0; j < num; j++)
		{
			printf ("	Player %d: %d, ",j, scoreFor(j, p));

		}
		printf("\n");
		for(j = 0; j < num; j++)
		{
			if(winner[j]==1)
				printf ("winner player %d\n",j);

		}


		memcpy ( &G, &g, sizeof(struct gameState) );
	}

	return 0;
}
int isExist(int c, int *arr) {

	int i;

	for (i = 0; i < 10; i++) {
		if (c == arr[i])
			return 1;
	}
	return 0;
}
void randCard(int *k) {
	int a,c;
	int i;
	for (i = 0; i < 10; i++) {
		do
		{
			c = (Random() * 20) + 8;
			//printf("a:%d, c:%d\n",a,c);
		}
		while (isExist(c,k));
		k[i] = c;
	}
}

#!/bin/bash

CFLAGS = -Wall -fpic -coverage -lm -fprofile-arcs -ftest-coverage

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

myassert.o: myassert.c
	gcc -c myassert.c -g $(CFLAGS)

unittest1: unittest1.c
	gcc -o unittest1 myassert.c unittest1.c dominion.o rngs.o interface.o $(CFLAGS)

unittest2: unittest2.c
	gcc -o unittest2 myassert.c unittest2.c dominion.o rngs.o interface.o $(CFLAGS)

unittest3: unittest3.c
	gcc -o unittest3 myassert.c unittest3.c dominion.o rngs.o interface.o $(CFLAGS)

unittest4: unittest4.c
	gcc -o unittest4 myassert.c unittest4.c dominion.o rngs.o interface.o $(CFLAGS)

cardtest1: cardtest1.c
	gcc -o cardtest1 myassert.c cardtest1.c dominion.o rngs.o interface.o $(CFLAGS)

cardtest2: cardtest2.c
	gcc -o cardtest2 myassert.c cardtest2.c dominion.o rngs.o interface.o $(CFLAGS)

cardtest3: cardtest3.c
	gcc -o cardtest3 myassert.c cardtest3.c dominion.o rngs.o interface.o $(CFLAGS)

cardtest4: cardtest4.c
	gcc -o cardtest4 myassert.c cardtest4.c dominion.o rngs.o interface.o $(CFLAGS)

randomtestadventurer: randomtestadventurer.c
	gcc -o randomtestadventurer myassert.c randomtestadventurer.c dominion.o rngs.o interface.o $(CFLAGS)

randomtestcard1: randomtestcard1.c
	gcc -o randomtestcard1 myassert.c randomtestcard1.c dominion.o rngs.o interface.o $(CFLAGS)

randomtestcard2: randomtestcard2.c
	gcc -o randomtestcard2 myassert.c randomtestcard2.c dominion.o rngs.o interface.o $(CFLAGS)

unittests: unittest1 unittest2 unittest3 unittest4
cardtests: cardtest1 cardtest2 cardtest3 cardtest4

unittestresults.out: unittests cardtests
	rm -f unittestresults.out
	echo "initializeGame unit tests" >> unittestresults.out
	./unittest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	echo "shuffle unit tests" >> unittestresults.out
	./unittest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	echo "playCard unit tests" >> unittestresults.out
	./unittest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	
	echo "fullDeckCount unit tests" >> unittestresults.out
	./unittest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "smithy unit tests" >> unittestresults.out
	./cardtest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "village unit tests" >> unittestresults.out	
	gcov dominion.c >> unittestresults.out
	./cardtest2 >> unittestresults.out
	
	echo "great_hall unit tests" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./cardtest3 >> unittestresults.out
	
	echo "council_roomCard unit tests" >> unittestresults.out
	./cardtest4 >> unittestresults.out
	gcov dominion.c -b -c >> unittestresults.out
		
randomtestadventurer.out: randomtestadventurer
	rm -f randomtestadventurer.out
	echo "randomtestadventurer random tests" >> randomtestadventurer.out
	./randomtestadventurer 42>> randomtestadventurer.out
	gcov dominion.c -b >> randomtestadventurer.out
	
randomtestcard1.out: randomtestcard1
	rm -f randomtestcard1.out
	echo "randomtestcard1 random tests" >> randomtestcard1.out
	./randomtestcard1 42>> randomtestcard1.out
	gcov dominion.c -b >> randomtestcard1.out

randomtestcard2.out: randomtestcard2
	rm -f randomtestcard2.out
	echo "randomtestcard2 random tests" >> randomtestcard2.out
	./randomtestcard2 42>> randomtestcard2.out
	gcov dominion.c -b >> randomtestcard2.out
			
all: playdom player

clean:
	rm -f *.o playdom.exe playdom test.exe test player randomtestcard1 randomtestcard2 randomtestadventurer unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe unittestresults.out *.out *.gcov *.gcda *.gcno *.so *.a *.dSYM

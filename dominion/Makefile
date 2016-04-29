CFLAGS = -Wall -fpic -coverage -lm

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

unittests: unittest1 unittest2 unittest3 unittest4
cardtests: cardtest1 cardtest2 cardtest3 cardtest4

unittestresults.out: unittests
	rm -f unittestresults.out
	./unittest1 >> unittestresults.out
	echo "TEST" >> unittestresults.out
	./unittest2 >> unittestresults.out
	echo "TEST" >> unittestresults.out
	./unittest3 >> unittestresults.out
	echo "TEST" >> unittestresults.out
	./unittest3 >> unittestresults.out
	echo "TEST" >> unittestresults.out
	./unittest4 >> unittestresults.out
	echo "TEST" >> unittestresults.out
		
all: playdom player

clean:
	rm -f *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe unittestresults.out *.gcov *.gcda *.gcno *.so *.a *.dSYM

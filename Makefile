F = -std=c++20 -Wall -Wextra -Wpedantic -Wfatal-errors
P = main

LADDER = src/ladder.cpp src/ladder_main.cpp

ladder: $(LADDER)
	g++ $F $(LADDER) -o main

clean:
	/bin/rm -f $P

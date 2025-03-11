F = -std=c++20 -Wall -Wextra -Wpedantic -Wfatal-errors
P = main

LADDER = src/ladder.cpp src/ladder_main.cpp
MST = src/dijkstras.cpp src/dijkstras_main.cpp

ladder: $(LADDER)
	g++ $F $(LADDER) -o main

mst: $(MST)
	g++ $F $(MST) -o main

clean:
	/bin/rm -f $P

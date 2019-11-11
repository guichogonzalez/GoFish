


go_fish: go_fish.o card.o deck.o player.o
	g++ -o -std=c++11 go_fish.o card.o deck.o player.o
 
go_fish.o: go_fish.cpp
	g++ -c -std=c++11 go_fish.cpp

card.o: card.cpp
	g++ -c -std=c++11 card.cpp

deck.o: deck.cpp
	g++ -c -std=c++11 deck.cpp

player.o: player.cpp
	g++ -c -std=c++11 player.cpp

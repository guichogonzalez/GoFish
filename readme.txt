Go Fish
Luis Gonzalez
LMG2482


instructions:
1. unzip file into an empty directory
2. type "make"
3. type "./a.out"

program will randomly determine the number of players in the game and will create an output file called
"results.txt" containing a play-by-play of the game, displaying each player's hand and book when a card request between players is successful.

rules/logic:

-number of players per game is random
-player 0 goes first, and turns progress linearly
-each player on their turn will check their own hand for books
-asking player chooses target card randomly from their hand
-asking player chooses target player randomly from the other players
-if target player has cards of the target rank that player will surrender all of those cards
-surrendered cards will be added to asker's collection of books,
-upon a successful request, both players' hands and books will be displayed
-game ends when the deck is empty and any player empties their hand.
-upon game-over, all extant books will be counted and the winner declared. 

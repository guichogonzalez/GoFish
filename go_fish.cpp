
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "stdlib.h"
#include "deck.h"
#include "player.h"
#include <ctime>
#include <fstream>

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);
int oneTurn(Player &p1, Player &p2, Deck &d, ofstream &m);



int main( )
{

    unsigned int currentTime =  (unsigned)time(0);
    srand(currentTime);  //seed the random number generator
    Deck d;
    d.shuffle();
	
    ofstream myfile;
    myfile.open ("results.txt");
   
   
    
    int numCards;
    vector<string> names = {"Jose", "Consuela", "Jesse" , "Marcelo" , "Dontel" , "Jessica" , "Shawna"};  //vector of names
    int numPlayers = (rand()%6)+2;							//# players chosen at random
    myfile << "Go Fish: Number of Players: " << numPlayers << endl;			//display number
    if (numPlayers == 2){	
        numCards = 7;
    }else{										//set cards #
        numCards = 5;
    }

    vector<Player> thePlayers;								//players are stored in a vector

    for (int i=0;i<numPlayers;i++){							//and generated
        string playerName = names[i];
        Player t = Player(playerName);
        dealHand(d, t, numCards);
        thePlayers.push_back(t);
    }
    //begin game:
    //first player = 0;

    bool finished = 0;
    auto it = thePlayers.begin();							//create iterators
    auto it2 = thePlayers.begin()+1;


    while (!finished) {

        if ((it->getHandSize()==0)&&(d.size()==0)){ 
            finished=1;						 //exit condition, if deck & any player's hand =empty 
            int max = 0;
            string winner;		
            for (int i=0;i<numPlayers;i++){			//traverse players vector to find biggest book
                if (thePlayers[i].getBookSize()) {
                    myfile << thePlayers[i].getName() << "'s book: " << thePlayers[i].showBooks() << endl;

                    if (thePlayers[i].getBookSize() > max) {
                        max = thePlayers[i].getBookSize();
                        winner = thePlayers[i].getName();
                    }
                }
            }
            myfile << winner << " wins!" << endl;
        }

        if (!(oneTurn(*it, *it2, d, myfile))) {  		//take a turn
            it++;						//if last turn unsuccessful, iterate to next
            if (it == thePlayers.end()) {			// mod
                it = thePlayers.begin();
            }
        }
        it2=it;							//
        while (it2==it) {					//randomize second iterator, make sure != first
            it2 = (thePlayers.begin() + rand() % numPlayers);
        }
    }
    return EXIT_SUCCESS;
}

int oneTurn(Player &p1,Player &p2,Deck &d, ofstream &myfile) { 			//a single turn
    if (p1.getHandSize() == 0) {
        if (d.size()) {
            p1.addCard(d.dealCard());						//if hand empty, draw a card
            myfile << p1.getName() << " draws a card." << endl;			//only if possible
        }else
            return 1;
    }
    Card check1;
    Card check2;
    if (p1.checkHandForPair(check1,check2)){					//check for pairs at beginning of turn
        p1.bookCards(p1.removeCardFromHand(check1),p1.removeCardFromHand(check2));	
        myfile << p1.getName() << " finds a pair in their hand." << endl;
    }
    if (p1.getHandSize() == 0) {						//if that emptied your hand, draw again
        if (d.size()==0) {							//otherwise, game over
            return 1;
        }else{									//
            p1.addCard(d.dealCard());
            myfile << p1.getName() << " draws a card." << endl;
        }
    }
    Card c1 = p1.chooseCardFromHand();
    myfile << p1.getName() << " asks " << p2.getName() << ": Do you have any " << c1.getRank() << "'s?" << endl;



    if(p2.rankInHand(c1)){
        myfile << p2.getName() << " says: Yes!" << endl;  //say yes
        for (int i = 0; i < 4; i++) {                               //iterate through the suits
            Card temp(c1.getRank(), Card::Suit(i));//checking with same rank and all 4 suits
            if (p2.cardInHand(temp)) {                      //if p2 has the card
                //if (p1.cardInHand(c1))
                //   p1.bookCard(p1.removeCardFromHand(c1));
                //if (p1.cardInHand(temp))
                //   p1.bookCard(p1.removeCardFromHand(temp));
                //p1.bookCard(p2.removeCardFromHand(temp));//add it to p1's hand

                p1.bookCards(p1.removeCardFromHand(c1),p2.removeCardFromHand(temp));

                if (p1.getHandSize())
                    myfile << p1.getName() << " has hand: " << p1.showHand() << endl;
                if (p1.getBookSize())
                    myfile << p1.getName() << " has book: " << p1.showBooks() << endl;
                if (p2.getHandSize())
                    myfile << p2.getName() << " has hand: " << p2.showHand() << endl;
                if (p2.getBookSize())
                    myfile << p2.getName()  << " has book: " << p2.showBooks() << endl;
                return 1;
            }

        }



    }else {                                //if no matches were found,
        myfile << p2.getName() << " says: Go Fish!" << endl;
        if (d.size()) {
            Card newCard = d.dealCard();//player draws a card
            myfile << p1.getName() << " draws a card." << endl;
            if (p1.checkHandForPair(c1, newCard)) {
                p1.bookCards(c1, newCard);
                myfile << p1.getName() << " finds a match in their hand." << endl;
                return 1;
            } else {
                p1.addCard(newCard);
                return 0;
            }
        }
    }

}


void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}


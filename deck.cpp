#include "deck.h"


using namespace std;

Deck::Deck(){
    unsigned int currentTime =  (unsigned)time(0);
    srand(currentTime);  //seed the random number generator
    myIndex=0;
    for (int i=0;i<4;i++) {
        for (int j = 1; j < 14; j++) {
            myCards[myIndex] = Card(j, Card::Suit(i));
            myIndex++;
        }

    }
}
int Deck::size() const{
    return myIndex;

    /*    int i=0;
    while((this->myCards[i].getRank())!=0){
        i++;
    }
    return i;
*/
}

void Deck::shuffle() {
    int holdchek = myIndex;
    for (int i = 0; i < (SIZE * 4); i++) {

        int idx1 = (rand() % SIZE);
        int idx2 = (rand() % SIZE);
        Card temp = myCards[idx1];
        myCards[idx1] = myCards[idx2];
        myCards[idx2] = temp;
    }
    myIndex = holdchek;
}

Card Deck::dealCard(){
    if (myIndex>=0){
        Card temp(myCards[myIndex-1]);
        myIndex--;
        return temp;
    }
}
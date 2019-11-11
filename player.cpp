#include "player.h"
#include "deck.h"
#include <vector>


using namespace std;

Player::Player(){
    myName = "Player";
    unsigned int currentTime =  (unsigned)time(0);
    srand(currentTime);  //seed the random number generator
}

void Player::addCard(Card c){
    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2){
    myBook.push_back(c1);
    myBook.push_back(c2);
}

void Player::bookCard(Card c){
    myBook.push_back(c);
}

Card Player::chooseCardFromHand() const{
    int idx = (rand()%myHand.size());
    return myHand[idx];
}

bool Player::checkHandForPair(Card &c1, Card &c2){
    for (int i=0;i<(this->getHandSize()-1);i++){
        for (int j=i+1;j<this->getHandSize();j++){
            if (myHand[i].getRank()==myHand[j].getRank()) {
                c1 = myHand[i];
                c2 = myHand[j];
                return true;
            }
        }
    }
    return false;
}

bool Player::cardInHand(Card c) const{
    int ctr = 0;
    for (int i=0;i<myHand.size();i++){
        if (myHand[i]==c){
            ctr++;
        }
    }
    if (ctr)
        return true;
    else
        return false;
}

bool Player::rankInHand(Card c) const{
    for(int i=0; i<myHand.size();i++){
        if (c.getRank()==myHand[i].getRank()){
            return true;
        }
    }return false;
}

string Player::showHand() const{
    string Result = myHand[0].toString();
    for (int i=1; i<myHand.size();i++){
        Result.append(myHand[i].toString());
    }
    return Result;
}
string Player::showBooks() const{
    string Result = myBook[0].toString();
    for (int i=1;i<myBook.size();i++){
        Result.append(myBook[i].toString());
    }
    return Result;
}
bool Player::sameRankInHand(Card c) const{
    for (int i=0;i<myHand.size();i++){
        if (myHand[i].getRank()==c.getRank()){
            return true;
        }
    }return false;
}

Card Player::removeCardFromHand(Card c) {
    for (vector<Card>::iterator it = myHand.begin();
         it != myHand.end(); it++) {
        if (*it==c){
            it = myHand.erase(it);
            return c;
        }
    }
}






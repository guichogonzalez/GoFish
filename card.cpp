
#include "card.h"
#include <string>

using namespace std;
//default constructor
Card::Card(){
    myRank=1;
    mySuit=spades;
}
//second constructor
Card::Card(int rank, Suit s){
    myRank=rank;
    mySuit=s;
}

bool Card::sameSuitAs(const Card &c) const{
    return(this->mySuit==c.mySuit);
}

bool Card::operator == (const Card& rhs) const{
    return((this->myRank==rhs.myRank)&&(this->mySuit==rhs.mySuit));
}
bool Card::operator != (const Card& rhs) const{
    return((this->myRank!=rhs.myRank)||(this->mySuit!=rhs.mySuit));
}
string Card::suitString(Suit s)      const {   // return "s", "h",...
    string result;
    if (s == Suit(0))
        result = "s";
    if (s == Suit(1))
        result = "h";
    if (s == Suit(2))
        result = "d";
    if (s == Suit(3))
        result = "c";
    return result;
}

string Card::rankString(int r)     const {
    string result;
    if (r == 1)
        result = "A";
    else if (r == 2)
        result = "2";
    else if (r == 3)
        result = "3";
    else if (r == 4)
        result = "4";
    else if (r == 5)
        result = "5";
    else if (r == 6)
        result = "6";
    else if (r == 7)
        result = "7";
    else if (r == 8)
        result = "8";
    else if (r == 9)
        result = "9";
    else if (r == 10)
        result = "10";
    else if (r == 11)
        result = "J";
    else if (r == 12)
        result = "Q";
    else if (r == 13)
        result = "K";

    return result;
}

string Card::toString() const{
    string result;
    result = rankString(this->myRank);
    result.append(suitString(this->mySuit));
    return result;
}

Card::Card(const Card &C2){
    this->myRank = C2.myRank;
    this->mySuit = C2.mySuit;

}
//Card::~Card(){

//};

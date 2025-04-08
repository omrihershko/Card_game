//
// Created by omri_hershkovich on 2/10/24.
// need to check when  need to do const
#include "Card.h"
#include <istream>


 Card::Card(char r, char s) : rank(r), sign(s) {
    setValue();
    set_suit();
}




void Card::set_suit() {
    switch(sign) {
        case 'C':
            sign_value=CLUBS;
            break;
        case 'S':
            sign_value = SPADES;
            break;
        case 'H':
            sign_value = HEARTS;
            break;
        case 'D':
            sign_value = DIAMONDS;
            break;
    }


}

void Card::setValue() {
    switch(rank) {
        case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
            value = rank - '0';
            break;
        case 'T':
            value = 10;
            break;
        case 'J':
            value = 10;
            break;
        case 'Q':
            value = 15;
            break;
        case 'K':
            value = 20;
            break;
        case 'A':
            value = 1;
            break;
    }
}
char Card::get_rank() const {return rank;};
int Card::get_value() const {return value;};
char Card::get_sign() const {return sign;};
Card::Suit Card::get_Suit() const {return sign_value; };



bool Card::operator==(const Card &other) const {
    if(rank==other.rank && sign==other.sign){
        return true;
    }
    return false;
}

bool Card::operator!=(const Card &other) const {
    return !(*this == other);
}

bool Card:: operator<(const Card &other)const{
    if(value==other.value && rank==other.rank){
        return sign_value<other.sign_value;
    }
    if(rank=='T' && other.rank=='J'){
        return true;
    }
    if(rank=='J' && other.rank=='T'){
        return false;
    }
    return value<other.value;
}

bool Card::operator<=(const Card &other) const {
    return *this<other || *this==other;
}


bool Card::operator>(const Card &other)const{
    if(value==other.value && rank==other.rank){
        return sign_value>other.sign_value;
    }
    if(rank=='T' && other.rank=='J'){
        return false;
    }
    if(rank=='J' && other.rank=='T'){
        return true;
    }
    return value>other.value;
}

bool Card::operator>=(const Card &other) const {
    return *this>other || *this==other;
}

Card& Card::operator=(const Card &other){
    if(this==&other){
        return *this;
    }
    this->value=other.value;
    this->sign_value=other.sign_value;
    this->rank=other.rank;
    this->sign=other.sign;
    return *this;
}
ostream& operator<<(ostream& os, const Card& card){
    os<<""<<card.rank<<card.sign;
    return os;
}




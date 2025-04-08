//
// Created by omri_hershkovich on 2/29/24.
//
#include "Set_card.h"

#include <utility>


bool Set_card::is_valid_set() {
    if (my_set.empty()) {
        return false;
    }

    if (my_set.size() == 1) {
        return true; // Any single card is a valid set.
    }

    if (my_set.size() == 2) {
        bool hasFaceCardOrTen = false;
        bool hasAce = false;
        for (const Card* card : my_set) {
            int cardRank = card->get_value(); // Assuming get_rank distinguishes Ace (1) from others and returns 11, 12, 13 for J, Q, K respectively.

            if (cardRank == 1) {
                hasAce = true;
            }
        }
        if (hasAce) {
            return true;
        }
    }

    int sum = 0;
    bool containsAce = false;
    int rank = -1;

    for (const Card* card : my_set) {
        int cardRank = card->get_value(); // Assuming get_rank distinguishes Ace (1) from others.

        // Check for Ace
        if (cardRank == 1) {
            if (containsAce) {
                return false; // Invalid if more than one Ace.
            }
            containsAce = true;
            continue;
        }

        // Ensure all non-Ace cards have the same rank
        if (rank == -1) {
            rank = cardRank;
        } else if (rank != cardRank) {
            return false; // Invalid if ranks differ.
        }

        // Sum the value of non-Ace cards
        sum += card->get_value(); // Assuming get_value returns the card's face value.
    }

    // The sum must be 10 or less for non-Ace cards of the same rank
    if (rank >= 2 && rank <= 5 && sum <= 10) {
        return true; // Valid if all non-Ace cards have the same rank and their sum is 10 or less.
    }

    return false; // Default case if none of the above conditions are met.
}

Set_card::Set_card(vector<Card*> my_set) {
    this->my_set=my_set;
    set_atack();
    set_get_less_damage();
    set_heall_character();
    check_if_double_attack();
  //  set_double_atack();

}



void Set_card::set_double_atack(){
    if(double_atack== true){
        atack=atack*2;
        heall_character=heall_character*2;
        get_less_damage=get_less_damage*2;
    }


}

void Set_card::set_get_less_damage() {
    for(int i=0;i<this->my_set.size();i++){
        if(my_set[i]->get_sign()=='D'){
            this->get_less_damage=atack;
        }
    }

}

void Set_card::set_heall_character() {
    for(int i=0;i<this->my_set.size();i++){
        if(my_set[i]->get_sign()=='H'){
            this->heall_character=atack;
        }
    }
}

void Set_card::set_atack() {
    for(int i=0;i<this->my_set.size();i++){
            this->atack+=my_set[i]->get_value();
        }
}


void Set_card::check_if_double_attack() {
   bool check_if_c= false;
   bool check_if_s=false;

   for(int i=0;i<this->my_set.size();i++) {
       if (my_set[i]->get_sign() == 'C') {
           check_if_c = true;
       }
   }
    for(int i=0;i<this->my_set.size();i++) {
        if (my_set[i]->get_sign() == 'S') {
            check_if_s = true;
        }
    }

    if(check_if_c && check_if_s){
        double_atack= true;
        return;
    }

    double_atack= false;


}

int Set_card::get_heall_character() {
    return heall_character;
}

int Set_card::get_atack() {
    return atack;
}

int Set_card::get_get_less_damage() {
    return get_less_damage;
}

bool Set_card::get_double_atack() {
    return double_atack;
}
set<Card::Suit> Set_card::get_types()
{

    set<Card::Suit> types;
    for(int i=0; i<my_set.size(); i++)
    {
        types.insert(my_set[i]->get_Suit());
    }
    return  types;
}

vector<Card*> Set_card::get_vector() {
    return my_set;
}


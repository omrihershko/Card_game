//
// Created by omri_hershkovich on 2/11/24.
//
#include "Deck.h"
#include <iostream>
#include <istream>
using namespace std;

bool Deck:: add_package(Card *other){

    Card **temp=new Card* [length_package+1];
    if(temp== nullptr){
        return false;
    }
    for(int i=0;i<length_package;i++){
        temp[i+1]=package_array_pointer[i];
    }
    temp[0]=new Card(other->get_rank(),other->get_sign());
    if(temp[0]== nullptr){
        delete[] package_array_pointer;
        return false;
    }
    delete[] package_array_pointer;
    package_array_pointer = temp;
    length_package++;
    return true;
}




Deck::~Deck(){
    if(package_array_pointer!= nullptr){
        for(int i=0;i<length_package;i++){
            delete package_array_pointer[i];
        }
    }

    delete[] package_array_pointer;
}

void Deck:: peak_to_first_n_cards(int how_mach_to_see){
    if(how_mach_to_see<0){
        std::cout << "Invalid number" << std::endl;
        return;
    }
    int min_to_to_need_see;
    min_to_to_need_see= min(how_mach_to_see,length_package);
    //std::cout << "[";
    for (int i = length_package-1; i >= length_package-min_to_to_need_see; --i) {
        std::cout << *(package_array_pointer[i])<<std::endl;
    }
}

Deck& Deck::operator-=(int how_mach_to_throw) {
    if(how_mach_to_throw<0){
        std::cout << "Invalid number" << std::endl;
        return *this;
    }
    int how_mach=min(how_mach_to_throw,length_package);
    Card **temp;
    int new_length=length_package-how_mach;
    temp=new Card *[new_length];
    for(int i=0;i<new_length;i++){
        temp[i]=package_array_pointer[i];
    }
    for(int j=new_length;j<length_package;j++){
        delete package_array_pointer[j];
    }
    delete[]package_array_pointer;
    package_array_pointer=temp;
    length_package=new_length;
    return *this;
}
Card& Deck::operator[](int index){
    if(index<0 || length_package<=index){
        std::cout << "Invalid number" << std::endl;
        return *package_array_pointer[0];
    }
    return *package_array_pointer[index];
}


ostream &operator<<(ostream &os, const Deck &Deck){
    if(Deck.length_package==0){
      //  std::cout << "[]" << std::endl;
        return os;
    }
    //std::cout << "[";
    for (int i = 0; i < Deck.length_package; ++i) {
        std::cout << *(Deck.package_array_pointer[i]);
        std::cout << " ";

        if (i < Deck.length_package - 1) {
     //       std::cout << ",";
        }
    }
   // std::cout << "]";
    return os;
}

Deck& Deck::operator+=(Card* cards){
    if(cards== nullptr){
        return *this;
    }
    int i = 0;
    while (true) {
        if(cards[i].get_rank()=='\000'){
            break;
        }
        add_package(&cards[i]);
        ++i;
    }
    return *this;
}

Deck& Deck:: operator+=(Deck &dk){
    for(int i=0;i<dk.length_package;i++){
        add_package(dk.package_array_pointer[i]);
    }
return *this;
}


int Deck::get_length() const{
    return length_package;
}
Card** Deck:: get_package_array_pointer(){
    return package_array_pointer;
}


void Deck::free(){
    if(package_array_pointer!= nullptr){
        for(int i=0;i<length_package;i++){
            delete package_array_pointer[i];
        }
    }
    delete[] package_array_pointer;
}

Card* Deck::pop_top() {
    if (length_package == 0) {
        return nullptr; // Deck is empty
    }

    Card* top_card = package_array_pointer[length_package - 1]; // Get the top card
    package_array_pointer[length_package - 1] = nullptr; // Remove the reference to the top card
    length_package--; // Decrease the length of the deck

    // Create a new array to hold the remaining cards

    Card** temp = new Card*[length_package];
    for (int i = 0; i < length_package; ++i) {
        temp[i] = package_array_pointer[i];
    }

    // Delete the previous array and assign the new array to the deck

    delete[] package_array_pointer;
    package_array_pointer = temp;

    return top_card;
}

Deck& Deck::remove_element( Card& card_to_remove) {
    for(int i = 0; i < length_package; i++) {
        if(package_array_pointer[i]->get_rank() == card_to_remove.get_rank() &&
           package_array_pointer[i]->get_sign() == card_to_remove.get_sign()) {
            // Found the card to remove

            delete package_array_pointer[i]; // Deallocate memory for the card
            // Shift remaining cards to fill the gap
            for(int j = i; j < length_package-1; j++) {//check -1
                package_array_pointer[j] = package_array_pointer[j + 1];
            }
            length_package--; // Decrease the length of the deck

            break; // Exit the loop as the card is found and removed
        }
    }
}

Card * Deck::get_top_card() {
    return ((this->package_array_pointer[length_package-1]));
}

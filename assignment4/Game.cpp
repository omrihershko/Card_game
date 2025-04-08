//
// Created by omri_hershkovich on 3/1/24.
//

#include "Game.h"
#include <sstream>
#include <tuple>
#include <list>

Game::Game() {
    initializer_deck();
}


// need to be * card

vector<Card *> Game::input_to_me_hand_player(Characters* My_player) {
    vector<Card*> my_hand;
    int mini = min(My_player->get_deck_number(),my_deck.get_length());
    for (int i = 0; i < mini; i++) {
        Card* card = my_deck.pop_top(); // Assuming you have a function pop_top() to remove and return the top card
        if (card != nullptr) {
            my_hand.insert(my_hand.begin(),card);
        }
    }

    return my_hand;
}

Set_card* Game::insert_to_set_card(vector<Card*>& my_player) {
    cout<<"Insert card set to play"<<endl;
    vector<Card*> set;
    string input_set_string;
    getline(std::cin, input_set_string);

    istringstream iss(input_set_string);
    string card_name;
    while (iss >> card_name) {
        if(card_name=="exit")
            return nullptr;
        Card *found_card = find_card(my_player, card_name);
        if (found_card->get_rank() != '0') { // Check if a valid card was found
            set.push_back(found_card);
        }
    }

    return new Set_card(set);
}

void Game::printHealths(Enemies* enemy, Characters* character)
{
    cout<<"Player health: "<<character->gat_live()<<endl;

    cout<<"Enemy health: "<<enemy->gat_live()<<endl;


}


Card* Game::find_card(vector<Card*>& my_hand_deck, const std::string& card_name) {
    for (int i = 0; i < my_hand_deck.size(); i++) {
        if (card_name[0] == my_hand_deck[i]->get_rank() && card_name[1] == (my_hand_deck)[i]->get_sign()) {
            return (my_hand_deck)[i];
        }
    }
}



void Game::initializer_deck(){
    cout<<"Initialize deck"<<endl;
    while (true){
        string card_to_input;
        getline(cin,card_to_input);
        if(card_to_input=="00"){
            break;
        }
        Card new_card=  Card(card_to_input[0],card_to_input[1]);//_______NEED TO CHECK
        my_deck.add_package(&new_card);

    }
}

Characters* Game::chooseCharacter() {
    int choice;
    std::cout << "Choose player character:"<<endl;
    std::cout<<"(1) Fighter (2) Sorcerer (3) Ranger"<<endl;
    std::cin >> choice;
    std::cin.ignore(); // Ignore newline character after number input.

    switch(choice) {
        case 1: return new Fighter();
        case 2: return new Wizard();
        case 3: return new Bow_man();
    }
}



Enemies* Game::chooseEnemies() {
    int choice;
    std::cout << "Choose enemy character:"<<endl;
    std::cout << "(1) Troll (2) Ghost (3) Dragon"<<endl;
    std::cin >> choice;
    std::cin.ignore(); // Ignore newline character after number input.

    switch(choice) {
        case 1: return new Troll();
        case 2: return new Ghost();
        case 3: return new Dragon();
    }
}




Set_card* Game::choseSetCards(vector<Card*>&my_hand) {
    cout<<"Player hand"<<endl;
    for(int i=0;i<my_hand.size();i++){
        std::cout<<*my_hand[i]<<" ";
    }
    std::cout<<std::endl;
    Set_card* validSet;
    while (true)
    {
        validSet = insert_to_set_card(my_hand);
        if(validSet== nullptr){
            return nullptr;
        }
        if(validSet->is_valid_set())
        {
            break;
        }
        delete validSet;
        cout<<"Card set is not valid"<<endl;
    }
    return validSet;
}

Deck &Game::get_deak_of_start_of_game() {
    return my_deck;
}



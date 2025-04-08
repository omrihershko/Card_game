//
// Created by omri_hershkovich on 3/1/24.
//

#ifndef EX_4_GAME_H
#define EX_4_GAME_H

#include <map>
#include <list>

#include "Set_card.h"

#include "Characters.h"
#include "Fighter.h"
#include "Wizard.h"
#include "Bow_man.h"

#include "Enemies.h"
#include "Troll.h"
#include "Ghost.h"
#include "Dragon.h"

class Game {


public:
    Game();
    Characters*  chooseCharacter();
    Enemies* chooseEnemies();
    vector<Card *> input_to_me_hand_player(Characters* My_player);
    Set_card* insert_to_set_card(vector<Card*>& my_player);
    void printHealths(Enemies* enemy, Characters* character);
    Set_card* choseSetCards(vector<Card*>& my_hand);
    Deck& get_deak_of_start_of_game();



private:

    void initializer_deck();
    Card* find_card(vector<Card*>&, const std::string& card_name);


    Deck my_deck;

};


#endif //EX_4_GAME_H

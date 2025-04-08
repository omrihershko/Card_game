#include "Card.h"
#include "Deck.h"
#include "Characters.h"
#include "Enemies.h"
#include "Set_card.h"
#include "Game.h"
#include <list>
#include <algorithm>
#include "Memory_Error.h"
using namespace std;





void delete_my_set_from_my_hand(Set_card &my_set, std::vector<Card*>& my_hand) {
    // Iterate through each card in my_set
    for (Card* cardToRemove : my_set.get_vector()) {


        // Use erase-remove idiom with remove_if and a lambda for custom comparison
        my_hand.erase(std::remove_if(my_hand.begin(), my_hand.end(),
                                     [cardToRemove](Card* cardInHand) {
                                         return *cardInHand == *cardToRemove;
                                     }),
                      my_hand.end());
        delete cardToRemove;//____________from guy amzulg
    }
}


bool insert_to_Deck_main_to_my_hand(std::vector<Card*>& my_hand, Deck &the_main_deck, int max_cards_character) {

    int size=my_hand.size();

    if(size==0){
        std::cout << "Deck ran out" << std::endl;
        return false;
    }

    // Determine the number of cards needed to fill the hand up to the max size or 2, whichever is smaller.
    int neededCards = std::min(max_cards_character - size, 2);

    if (the_main_deck.get_length() < neededCards) {
        std::cout << "Deck ran out" << std::endl;
        return false;
    }

    for (int i = 0 ; i < neededCards; i++) {
        Card *card_to_add=the_main_deck.pop_top();
        my_hand.insert(my_hand.begin(),card_to_add);
    }
    return true;
}


int main()
{
    Game game;
    Enemies* enemy;
    Characters* character;
   vector<Card*> myHand ;
    Set_card *my_set;
    bool flage_1= true;
    bool flage_2= true;


//chose a player
    try {
        character = game.chooseCharacter();
        if(character== nullptr){
            throw Memory_Error() ;
        }

    }
    catch (exception &E){
        E.what();
        return 1;
    }

    //chose a enemy

    try {
        enemy = game.chooseEnemies();
        if(enemy== nullptr){
            throw Memory_Error() ;
        }

    }
    catch (exception &E) {
        E.what();
        delete character;
        return 1;
    }

    //insert the card to my hand form the deck
    myHand = game.input_to_me_hand_player(character);

//if the size of the card is not enangh we exit the program
    if(myHand.size()<(character->get_deck_number())){
        std::cout<<"Deck run out"<<std::endl;
        for(int i=0;i<myHand.size();i++){
            delete myHand[i];
        }
        delete character;
        delete enemy;
        return 0;
    }


//start the game
    while(true)
    {

        try {
            game.printHealths(enemy, character);
            my_set = game.choseSetCards(myHand);
            if (my_set == nullptr)
                break;
            flage_1 = character->fight(enemy, *my_set);
            if (!flage_1)
                break;
            delete_my_set_from_my_hand(*my_set, myHand);
            flage_2 = insert_to_Deck_main_to_my_hand(myHand, game.get_deak_of_start_of_game(),
                                                     character->get_deck_number());
            if (!flage_2)
                break;
            delete my_set;
            my_set = nullptr;
        }

        catch (exception &E) {
            E.what();
            for(int i=0;i<myHand.size();i++){
                delete myHand[i];
            }
            delete character;
            delete enemy;
            delete my_set;
            return 1;
        }

    }

//clean the memory
    for(int i=0;i<myHand.size();i++){
        delete myHand[i];
    }
    delete my_set;
    delete character;
    delete enemy;
}


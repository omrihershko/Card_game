//
// Created by omri_hershkovich on 2/29/24.
//
#include <utility>
#include <vector>
#include <set>
#include "Card.h"
#ifndef EX_4_SET_CARD_H
#define EX_4_SET_CARD_H
using namespace std;



/**
 * @class Set_card
 * @brief Represents a set of cards used in a game.
 */
class Set_card {
private:
    vector<Card*> my_set;
    int get_less_damage = 0;
    int heall_character = 0;
    int atack = 0;
    bool double_atack;
public:
/**
     * @brief Constructor for the Set_card class.
     * @param my_set A vector containing pointers to Card objects.
     */
    Set_card(vector<Card*> my_set);

    /**
     * @brief Sets the attack value.
     */

    void set_atack();
    /**
     * @brief Sets the flag for double attack.
     */
    void set_double_atack();
    /**
        * @brief Sets the less damage value.
     */
    void set_get_less_damage();
    /**
        * @brief Sets the heal character value.
        */
    void set_heall_character();
    /**
       * @brief Checks if double attack is enabled.
     */
    void check_if_double_attack();

/**
     * @brief Checks if the set is valid.
     * @return True if the set is valid, false otherwise.
     */
    bool is_valid_set();
/**
     * @brief Gets the types of cards in the set.
     * @return A set containing the types of cards.
     */
    int get_heall_character() ;
    /**
        * @brief Gets the vector of cards in the set.
        * @return A vector containing pointers to Card objects.
        */

    // Accessor functions
    int get_atack();
    int get_get_less_damage();
    bool get_double_atack();
    set<Card::Suit> get_types();
    vector<Card*> get_vector();


};








#endif //EX_4_SET_CARD_H

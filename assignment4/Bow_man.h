//
// Created by omri_hershkovich on 2/25/24.
//

#ifndef EX_4_BOW_MAN_H
#define EX_4_BOW_MAN_H
#include "Characters.h"


class Bow_man: public Characters{
    /**
 * @class Bow_man
 * @brief Represents a bowman character in the game.
 */


public:
    /**
  * @brief Constructor for the Bow_man class.
  * Initializes the Bow_man with specific health and attack values.
  */
    Bow_man(): Characters(50,7){}

    /**
 * @brief Performs a fight between the bowman and an enemy.
 * @param enemy A pointer to the enemy character.
 * @param my_set A reference to the set of cards used in the fight.
 * @return True if the bowman wins the fight, false otherwise.
 */
    virtual bool  fight(Enemies *enemy,Set_card &my_set);
    /**
     * @brief Gets the maximum live enemy value.
     * @return The maximum live enemy value.
     */
    const virtual  int get_max_live_enemy();

};










#endif //EX_4_BOW_MAN_H

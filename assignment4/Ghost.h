//
// Created by omri_hershkovich on 2/25/24.
//

#ifndef EX_4_GHOST_H
#define EX_4_GHOST_H

#include "Enemies.h"
class Characters;
class Set_card;
/**
 * @class Ghost
 * @brief Represents a ghost enemy in the game.
 */
class Ghost: public Enemies{
public:
    /**
     * @brief Constructor for the Ghost class.
     * Initializes the Ghost with specific health and attack values.
     */
    Ghost(): Enemies(50,15){}
    /**
        * @brief Fights against a fighter character.
        * @param characters A pointer to the fighter character.
        * @param my_set A reference to the set of cards used in the fight.
        * @return True if the Ghost wins the fight, false otherwise.
        */
    virtual  bool fight_aginst_figther(Characters *characters,Set_card &my_set);

    /**
   * @brief Fights against a bowman character.
   * @param characters A pointer to the bowman character.
   * @param my_set A reference to the set of cards used in the fight.
   * @return True if the Ghost wins the fight, false otherwise.
   */
    virtual  bool fight_aginst_bow_man(Characters *characters,Set_card &my_set);
    /**
        * @brief Fights against a wizard character.
        * @param characters A pointer to the wizard character.
        * @param my_set A reference to the set of cards used in the fight.
        * @return True if the Ghost wins the fight, false otherwise.
        */
    virtual  bool fight_aginst_wizard(Characters *characters,Set_card &my_set);



};


#endif //EX_4_GHOST_H

/**
 * @file Wizard.h
 * @brief Declaration of the Wizard class.
 */

#ifndef EX_4_WIZARD_H
#define EX_4_WIZARD_H

#include "Characters.h"

/**
 * @class Wizard
 * @brief Represents a wizard character in the game.
 */
class Wizard : public Characters {
public:
    /**
     * @brief Default constructor for the Wizard class.
     * Initializes the wizard with default health and power values.
     */
    Wizard(): Characters(40, 8) {}

    /**
     * @brief Performs a fight between the wizard and an enemy.
     * @param enemy A pointer to the enemy character.
     * @param my_set A reference to the set of cards used in the fight.
     * @return True if the wizard wins the fight, false otherwise.
     */
    virtual bool fight(Enemies *enemy, Set_card &my_set);

    /**
     * @brief Gets the maximum live enemy value.
     * @return The maximum live enemy value.
     */
    const virtual int get_max_live_enemy();
};

#endif //EX_4_WIZARD_H

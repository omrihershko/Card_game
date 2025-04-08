//
// Created by omri_hershkovich on 2/25/24.
//

#ifndef EX_4_CHARACTERS_H
#define EX_4_CHARACTERS_H
#include "Card.h"
#include "Deck.h"

class Enemies;
class Set_card;

/**
 * @class Characters
 * @brief Represents a generic character in the game.
 */

class Characters{

public:
    /**
       * @brief Constructor for the Characters class.
       * @param live_point The initial live points of the character.
       * @param my_deck The number of the character's deck.
       */
    Characters(int live_point,int my_deck);
    /**
        * @brief Destructor for the Characters class.
        */
    void set_live_point(int new_point);
    /**
       * @brief Sets the live points of the character.
       * @param new_point The new live points of the character.
       */
    virtual ~Characters();

    /**
     * @brief Retrieves the live points of the character.
     * @return The live points of the character.
     */
    int  gat_live() const;
    /**
       * @brief Retrieves the deck number of the character.
       * @return The deck number of the character.
       */
    int get_deck_number() const;
    /**
       * @brief Virtual function representing a fight between the character and an enemy.
       * @param enemy A pointer to the enemy character.
       * @param my_set A reference to the set of cards used in the fight.
       * @return True if the character wins the fight, false otherwise.
       */
    virtual bool  fight(Enemies *enemy,Set_card &my_set)=0;

    /**
     * @brief Virtual function to get the maximum live enemy value.
     * @return The maximum live enemy value.
     */
    const virtual  int get_max_live_enemy()=0;




protected:
    int my_deck_number;
    int live_points;


};





#endif //EX_4_CHARACTERS_H
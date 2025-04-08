//
// Created by omri_hershkovich on 2/25/24.
//




#ifndef EX_4_FIGHTER_H
#define EX_4_FIGHTER_H
#include "Characters.h"

class Fighter: public Characters{
public:
    /**
     * @brief Constructor for the Fighter class.
     * Initializes the Fighter with specific health and attack values.
     */
    Fighter(): Characters(60,6){}
    /**
        * @brief Performs a fight between the fighter and an enemy.
        * @param enemy A pointer to the enemy character.
        * @param my_set A reference to the set of cards used in the fight.
        * @return True if the fighter wins the fight, false otherwise.
        */
    virtual bool  fight(Enemies *enemy,Set_card &my_set);
    /**
        * @brief Gets the maximum live enemy value.
        * @return The maximum live enemy value.
        */
    const virtual  int get_max_live_enemy();






};



#endif //EX_4_FIGHTER_H

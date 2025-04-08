//
// Created by omri_hershkovich on 2/25/24.
//

#ifndef EX_4_ENEMIES_H
#define EX_4_ENEMIES_H
#include "Card.h"
class Set_card;
class Characters;
class Enemies{
/**
 * @class Enemies
 * @brief Represents a generic enemy in the game.
 */
public:
/**
     * @brief Constructor for the Enemies class.
     * @param live_point The initial live points of the enemy.
     * @param point_damage The damage points of the enemy.
     */
    Enemies(int live_point,int point_damage);
    /**
       * @brief Destructor for the Enemies class.
       */
        virtual ~Enemies();
/**
     * @brief Retrieves the live points of the enemy.
     * @return The live points of the enemy.
     */
        int  gat_live() const;
/**
     * @brief Retrieves the damage points of the enemy.
     * @return The damage points of the enemy.
     */
        int get_point_damage() const;
/**
     * @brief Virtual function representing fight against a fighter character.
     * @param characters A pointer to the fighter character.
     * @param my_set A reference to the set of cards used in the fight.
     * @return True if the enemy wins the fight, false otherwise.
     */
        virtual  bool fight_aginst_figther(Characters *characters,Set_card &my_set)=0;
/**
     * @brief Virtual function representing fight against a bowman character.
     * @param characters A pointer to the bowman character.
     * @param my_set A reference to the set of cards used in the fight.
     * @return True if the enemy wins the fight, false otherwise.
     */
         virtual  bool fight_aginst_bow_man(Characters *characters,Set_card &my_set)=0;

    /**
     * @brief Virtual function representing fight against a wizard character.
     * @param characters A pointer to the wizard character.
     * @param my_set A reference to the set of cards used in the fight.
     * @return True if the enemy wins the fight, false otherwise.
     */
         virtual  bool fight_aginst_wizard(Characters *characters,Set_card &my_set)=0;
/**
     * @brief Sets the live points of the enemy.
     * @param new_live The new live points of the enemy.
     */

         void set_live_point(int new_live);


protected:
        int point_damage;
        int live_points;

};





#endif //EX_4_ENEMIES_H

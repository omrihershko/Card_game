//
// Created by omri_hershkovich on 3/1/24.
//
#include "Troll.h"
#include "Characters.h"
#include "Set_card.h"
#include <iostream>





bool Troll::fight_aginst_figther(Characters *characters,Set_card &my_set) {
    int damageDealt = my_set.get_atack();
    int less_damage=my_set.get_get_less_damage();
    if (my_set.get_double_atack()) {
        damageDealt *= 2;
        less_damage*=2;
    }

    int newEnemyHealth = std::max(this->gat_live() - damageDealt, 0);
    this->set_live_point(newEnemyHealth);
    std::cout << "Player dealt " << damageDealt << " points of damage" << std::endl;

    if(newEnemyHealth==0){
        std::cout<<"Player won"<<std::endl;
        return false;
    }
    int damageTaken = std::max(this->point_damage - less_damage, 0);
    int newCharacterHealth = std::max(characters->gat_live() - damageTaken, 0);
    characters->set_live_point(newCharacterHealth);
    std::cout << "Player took " << damageTaken << " points of damage" << std::endl;

    if(characters->gat_live()==0){
        std::cout<<"Player lost"<<std::endl;
        return false;
    }
    return true;
}






bool Troll::fight_aginst_bow_man(Characters *characters,Set_card &my_set) {


    int newEnemyHealth = std::max(this->gat_live() - my_set.get_atack(), 0);
    this->set_live_point(newEnemyHealth);
    std::cout << "Player dealt " << my_set.get_atack() << " points of damage" << std::endl;
    if (newEnemyHealth == 0) {
        std::cout << "Player won" << std::endl;
        return false;
    }

    int old_live = characters->gat_live();
    int new_live = std::min(characters->gat_live() + my_set.get_heall_character(), characters->get_max_live_enemy());
    characters->set_live_point(new_live);
    if (new_live != old_live) {
        std::cout << "Player healed " << (new_live - old_live) << " points of damage" << std::endl;
    }

        int damageTaken = std::max(this->point_damage - my_set.get_get_less_damage(), 0);
        int newCharacterHealth = std::max(characters->gat_live() - damageTaken, 0);
        characters->set_live_point(newCharacterHealth);
        std::cout << "Player took " << damageTaken << " points of damage" << std::endl;

        if (characters->gat_live() == 0) {
            std::cout << "Player lost" << std::endl;
            return false;
        }

    return true;
    }












bool Troll::fight_aginst_wizard(Characters *characters,Set_card &my_set) {
    int damageDealt = my_set.get_atack();
    int heal_characters=my_set.get_heall_character();
    if (my_set.get_double_atack()) {
        damageDealt *= 2;
        heal_characters*=2;
    }

    int newEnemyHealth = std::max(this->gat_live() - damageDealt, 0);
    this->set_live_point(newEnemyHealth);
    std::cout << "Player dealt " << damageDealt << " points of damage" << std::endl;
    if(newEnemyHealth==0){
        std::cout<<"Player won"<<std::endl;
        return false;
    }
    int old_live=characters->gat_live();
    int new_live=std::min(characters->gat_live()+heal_characters,characters->get_max_live_enemy());
    if(new_live!=old_live){
        std::cout << "Player healed " << (new_live-old_live) << " points of damage" << std::endl;

    }

    int newCharacterHealth = std::max(characters->gat_live() - this->point_damage, 0);
    characters->set_live_point(newCharacterHealth);
    std::cout << "Player took " << this->point_damage << " points of damage" << std::endl;
    if(characters->gat_live()==0){
        std::cout<<"Player lost"<<std::endl;
        return false;
    }

    return true;
}


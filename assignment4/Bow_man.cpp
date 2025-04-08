//
// Created by omri_hershkovich on 3/1/24.
//
#include "Bow_man.h"
#include "Enemies.h"

bool Bow_man::fight(Enemies *enemy,Set_card &my_set) {

    enemy->fight_aginst_bow_man(this,my_set);

}

const int Bow_man::get_max_live_enemy() {
    return 50;
}
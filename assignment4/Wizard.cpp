//
// Created by omri_hershkovich on 3/1/24.
//
#include "Wizard.h"
#include "Enemies.h"

bool Wizard::fight(Enemies *enemy,Set_card &my_set) {
    enemy->fight_aginst_wizard(this,my_set);
}


const int Wizard::get_max_live_enemy() {
    return 40;
}
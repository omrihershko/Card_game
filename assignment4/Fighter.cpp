//
// Created by omri_hershkovich on 3/1/24.
//
#include "Fighter.h"
#include "Enemies.h"



bool Fighter::fight(Enemies *enemy,Set_card &my_set) {

    enemy->fight_aginst_figther(this,my_set);

}


const int Fighter::get_max_live_enemy() {
    return 60;
}
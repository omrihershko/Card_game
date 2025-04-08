//
// Created by omri_hershkovich on 2/25/24.
//
#include "Characters.h"

Characters::Characters(int live_point,int my_deck):live_points(live_point),my_deck_number(my_deck) {}

Characters::~Characters() {}

int Characters::gat_live() const {
    return live_points;
}

int Characters::get_deck_number() const {
    return my_deck_number;
}

void Characters::set_live_point(int new_point) {

    live_points=new_point;
}







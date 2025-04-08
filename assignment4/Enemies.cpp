//
// Created by omri_hershkovich on 2/25/24.
//

#include "Enemies.h"

Enemies::Enemies(int live_point, int point_damage):live_points(live_point),point_damage(point_damage) {}


Enemies:: ~Enemies(){};

int Enemies::gat_live() const {
    return live_points;
}

int Enemies::get_point_damage() const {
    return point_damage;
}

void Enemies::set_live_point(int new_live) {
    this->live_points=new_live;
}
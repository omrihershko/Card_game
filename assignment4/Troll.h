// Created by omri_hershkovich on 2/25/24.

#ifndef EX_4_TROLL_H
#define EX_4_TROLL_H

#include "Enemies.h" // Including the header file for the base class

class Characters; // Forward declaration of the Characters class
class Set_card; // Forward declaration of the Set_card class

class Troll: public Enemies { // Declaration of the Troll class inheriting from Enemies
public:
    Troll(): Enemies(100, 5) {} // Constructor initializing Troll with specific values

    // Declaration of functions for fighting against different character types
    virtual bool fight_aginst_figther(Characters *characters, Set_card &my_set);
    virtual bool fight_aginst_bow_man(Characters *characters, Set_card &my_set);
    virtual bool fight_aginst_wizard(Characters *characters, Set_card &my_set);
};

#endif //EX_4_TROLL_H

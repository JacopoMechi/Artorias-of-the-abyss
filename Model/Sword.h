#ifndef _SWORD_H
#define _SWORD_H

#include "Weapon.h"
class Sword : public Weapon
{
    explicit Sword(int damage = 1, int level = 1); //TODO choose default damage value
    ~Sword();
};

#endif //_SWORD_H
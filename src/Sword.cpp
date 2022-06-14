#include "Sword.h"

void Sword::setLevel(int level) //TODO Choose damage for every level
{
    this->level = level;
    if (level == 1)
        damage = 5;
    else if (level == 2)
        damage = 10;
    else if (level == 3)
        damage = 15;
}

Sword::Sword(int level) : Weapon(level) {}

Sword::~Sword() {}

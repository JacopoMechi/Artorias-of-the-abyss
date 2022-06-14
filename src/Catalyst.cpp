#include "Catalyst.h"

void Catalyst::setLevel(int level) //TODO Choose damage for every level
{
    this->level = level;
    if (level == 1)
        damage = 5;
    else if (level == 2)
        damage = 10;
    else if (level == 3)
        damage = 15;
}

Catalyst::Catalyst(int level) : Weapon(level) {}

Catalyst::~Catalyst() {}
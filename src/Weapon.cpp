#include "Weapon.h"

int Weapon::getDamage()
{
    return damage;
}

int Weapon::getLevel()
{
    return level;
}

Weapon::Weapon(int level) : level(level) {}

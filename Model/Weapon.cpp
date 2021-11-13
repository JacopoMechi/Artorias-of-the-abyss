#include "Weapon.h"

Weapon::Weapon(int level)
{
    Weapon::setLevel(level);
}
Weapon::~Weapon() {}

int Weapon::getDamage()
{
    return damage;
}

int Weapon::getLevel()
{
    return level;
}

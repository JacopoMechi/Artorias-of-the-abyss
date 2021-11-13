#include "Weapon.h"

int Weapon::getDamage()
{
    return damage;
}

void Weapon::setDamage(int damage)
{
    this->damage = damage;
}

int Weapon::getLevel()
{
    return level;
}

void Weapon::setLevel(int level)
{
    this->level = level;
}
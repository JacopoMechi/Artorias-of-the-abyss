#include "Weapon.h"

Weapon::Weapon(int damage, int level) : damage(damage), level(level) {}

Weapon::~Weapon() {}

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
#include "Weapon.h"

int Weapon::getDamage()
{
    return damage;
}

int Weapon::getLevel()
{
    return level;
}

<<<<<<< HEAD
Weapon::Weapon(int level) : level(level) {}

Weapon::~Weapon() {}
=======
Weapon::Weapon(int level)
{
    Weapon::setLevel(level);
}
//Weapon::~Weapon() { }//check if this is fixed
>>>>>>> 8a9dce599861ef94850872a6940996529cd82323

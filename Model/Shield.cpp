#include "Shield.h"

int Shield::getDefence()
{
    return defence;
}

int Shield::getLevel()
{
    return level;
}

void Shield::setLevel(int level) //TODO Choode defence levels for each level
{
    this->level = level;
    if (level == 1)
        defence = 5;
    else if (level == 2)
        defence = 10;
    else if (level == 3)
        defence = 15;
}

Shield::Shield(int level) : level(level) {}

Shield::~Shield() {}

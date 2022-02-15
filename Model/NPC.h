#ifndef _NPC_H
#define _NPC_H

#include "GameCharacter.h"


class NPC: public GameCharacter {
public:

explicit NPC(std::string type, const sf::Vector2f& pos, int hp = 100, int armor = 0, int cash = 0, float movementSpeed = 0);

virtual void receiveDamage(int points) = 0;//to be unkillable

void sellItems();
};

#endif
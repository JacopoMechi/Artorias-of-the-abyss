#ifndef _NPC_H
#define _NPC_H

#include "GameCharacter.h"


class NPC: public GameCharacter {
public:

NPC(int type, const sf::Vector2f& pos, int hp = 100, int armor = 0, int cash = 0, float movementSpeed = 0);
~NPC();

void receiveDamage() = delete;//to be unkillable

void sellItems();
};

#endif
#ifndef _NPC_H
#define _NPC_H

#include "GameCharacter.h"


class NPC: public GameCharacter {
public:

virtual void receiveDamage(int points) = 0;

void sellItems();
};

#endif
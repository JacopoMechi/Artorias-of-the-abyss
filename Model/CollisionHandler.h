#ifndef _COLLISIONHANDLER_H
#define _COLLISIONHANDLER_H

#include "Hero.h"
#include "NPC.h"
#include "RoomElement.h"

class CollisionHandler{
public:
    CollisionHandler(Hero &hero);
    //handling collision with map elements
    void handleElement(RoomElement &element);
    //handling collisions with npcs
    void handleNPC(NPC &npc);
    //setter for enemies collision //TODO

private:
    Hero &hero;
};
#endif
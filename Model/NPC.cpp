#include "NPC.h"

NPC::NPC(std::string type, const sf::Vector2f& pos, int hp, int armor, int cash, float movementSpeed) : 
    GameCharacter(pos, hp, armor, cash, movementSpeed){

}

void NPC::sellItems() {

}

#include "Room.h"

Room::Room(int level, sf::RenderWindow &window): level(level), window(window){

}

void Room::spawnEntity(RoomElement *roomElement)
{
    roomElementsVector.emplace_back(roomElement);
}

bool Room::getisClear()
{
    return isClear;
}
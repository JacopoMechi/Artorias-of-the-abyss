#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <memory>

#include "Room.h"

void Room::spawnEntity(RoomElement *roomElement)
{
    roomElementsVector.emplace_back(roomElement);
}

bool Room::getisClear()
{
    return isClear;
}
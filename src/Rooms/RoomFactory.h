#ifndef _ROOMFACTORY_H
#define _ROOMFACTORY_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include <vector>

#include "Room.h"
#include "StartRoom.h"
#include "MiddleRoom.h"
#include "FinalRoom.h"


class RoomFactory{
public:
    RoomFactory(){}

    std::unique_ptr<Room> makeRoom(std::string type, sf::RenderWindow &window, int roomLevel) const;

    std::unique_ptr<Room> createRoom(std::string type, sf::RenderWindow &window, int roomLevel) const;
};
#endif
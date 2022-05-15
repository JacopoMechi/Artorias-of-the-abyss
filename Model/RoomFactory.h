#ifndef _ROOMFACTORY_H
#define _ROOMFACTORY_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include <vector>

#include "Room.h"
#include "StartRoom.h"
#include "SecondRoom.h"
#include "ThirdRoom.h"
#include "FourthRoom.h"
#include "FinalRoom.h"


class RoomFactory{
protected:
    RoomFactory(){}

public:
    virtual ~RoomFactory() = 0;//FIXME maybe

    Room* makeRoom(std::string type, sf::RenderWindow &window, int roomLevel) const;

    Room* createRoom(std::string type, sf::RenderWindow &window, int roomLevel) const;
};
#endif
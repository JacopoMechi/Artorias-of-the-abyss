#ifndef _ROOMFACTORY_H
#define _ROOMFACTORY_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include <vector>

#include "Room.h"

class RoomFactory{
protected:
    RoomFactory(){}

public:
    virtual ~RoomFactory() = 0;//FIXME maybe

    Room* makeRoom(std::string type) const;

    Room* createRoom(std::string type) const;
};
#endif
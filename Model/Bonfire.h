#ifndef _BONFIRE_H
#define _BONFIRE_H

#include "MapElement.h"
#include <SFML/System.hpp>
#include <string>
#include <vector>

class Bonfire : public MapElement
{
public:
    void resetHp(); //TODO to be implemented

    void setSpawnPoint(); //TODO to be implemented

    void respawnEnemies(); //TODO to be implemented

    Bonfire(std::vector<int> &spriteDimension, sf::Vector2f &position, std::string &mapElementFilePath);

    ~Bonfire();
};

#endif //_BONFIRE_H
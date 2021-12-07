#ifndef _BONFIRE_H
#define _BONFIRE_H

#include <SFML/System.hpp>
#include <string>
#include <vector>

#include "MapElement.h"

class Bonfire : public MapElement
{
public:
    void draw(sf::RenderWindow &window);

    void resetHp(); // TODO to be implemented

    void setSpawnPoint(); // TODO to be implemented

    void respawnEnemies(); // TODO to be implemented

    Bonfire(std::vector<int> spriteDimension, sf::Vector2f position, std::string mapElementFilePath);

    ~Bonfire();
};

#endif //_BONFIRE_H
#ifndef _BONFIRE_H
#define _BONFIRE_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

#include "RoomElement.h"

class Bonfire : public RoomElement
{
public:
    void resetHp(); // TODO to be implemented

    void setSpawnPoint(); // TODO to be implemented

    void respawnEnemies(); // TODO to be implemented

    Bonfire(sf::RenderWindow &window, const sf::Vector2f &position,
            const std::vector<sf::IntRect> &spriteFrames = {{2, 522, 189, 298}, {191, 522, 189, 298}, {380, 522, 189, 298}},
            const std::string &roomElementFilePath = "../Textures/Textures.png");

    ~Bonfire();
};

#endif //_BONFIRE_H
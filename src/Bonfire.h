#ifndef _BONFIRE_H
#define _BONFIRE_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

#include "Rooms/RoomElement.h"

class Bonfire : public RoomElement
{
public:
    void resetHp(); // TODO to be implemented

    void setSpawnPoint(); // TODO to be implemented

    void respawnEnemies(); // TODO to be implemented

    Bonfire(sf::RenderWindow &window, const sf::Vector2f &position,
            const std::vector<sf::IntRect> &spriteFrames = {{1, 520, 184, 297}, {191, 540, 203, 277}, {405, 521, 176, 293}},
            const std::string &roomElementFilePath = "../Textures/Textures.png");

    ~Bonfire();
};

#endif //_BONFIRE_H
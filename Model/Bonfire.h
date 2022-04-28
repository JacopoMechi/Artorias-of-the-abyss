#ifndef _BONFIRE_H
#define _BONFIRE_H

#include <SFML/System.hpp>
#include <vector>

#include "RoomElement.h"

class Bonfire : public RoomElement
{
public:
    void draw(sf::RenderWindow &window);

    void resetHp(); // TODO to be implemented

    void setSpawnPoint(); // TODO to be implemented

    void respawnEnemies(); // TODO to be implemented

    Bonfire(sf::Vector2f position,
            std::vector<sf::IntRect> spriteFrames = {{250, 0, 189, 298}, {439, 0, 189, 298}, {628, 0, 189, 298}},
            const std::string roomElementFilePath = "../Textures/Textures.png");

    ~Bonfire();
};

#endif //_BONFIRE_H
#ifndef _BONFIRE_H
#define _BONFIRE_H

#include <SFML/System.hpp>
#include <vector>

#include "MapElement.h"

class Bonfire : public MapElement
{
public:
    void draw(sf::RenderWindow &window);

    void resetHp(); // TODO to be implemented

    void setSpawnPoint(); // TODO to be implemented

    void respawnEnemies(); // TODO to be implemented

    Bonfire(sf::Vector2f position,
            std::vector<sf::IntRect> spriteFrames = {{250, 0, 189, 298}, {439, 0, 189, 298}, {628, 0, 189, 298}},
            const std::string mapElementFilePath = "../Textures/Textures.png");

    ~Bonfire();
};

#endif //_BONFIRE_H
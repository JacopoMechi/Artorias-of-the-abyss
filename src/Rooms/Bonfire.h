#ifndef _BONFIRE_H
#define _BONFIRE_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>

#include "Rooms/RoomElement.h"
#include "GameCharacters/Hero.h"

class Bonfire : public RoomElement
{
public:
    bool closeToHero(sf::Vector2f heroPos);

    Bonfire(sf::RenderWindow &window, const sf::Vector2f &position,
            const std::vector<sf::IntRect> &spriteFrames = {{firstBonfireX, firstBonfireY, firstBonfireWidth, firstBonfireHeight}, {secondBonfireX, secondBonfireY, secondBonfireWidth, secondBonfireHeight}, {thirdBonfireX, thirdBonfireY, thirdBonfireWidth, thirdBonfireHeight}},
            const std::string &roomElementFilePath = "Textures/Textures.png");

    ~Bonfire();
};

#endif //_BONFIRE_H
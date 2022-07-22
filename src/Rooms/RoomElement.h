#ifndef _ROOMELEMENT_H
#define _ROOMELEMENT_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include <vector>
#include <iostream>
#include "Constants.h"

class RoomElement
{
public:
    void draw();
    sf::Vector2f getPos() const;
    void setPos(sf::Vector2f &newPos);
    sf::Vector2f getSize() const;
    void setDelayTime(float dt);
    sf::Sprite getSprite() const;
    RoomElement(sf::RenderWindow &window, const std::string &roomElementFilePath = "Textures/Textures.png");
    RoomElement(sf::RenderWindow &window, const sf::Vector2f &position, const std::vector<sf::IntRect> &spriteFrames,
                const std::string &roomElementFilePath = "Textures/Textures.png");
    virtual ~RoomElement();

protected:
    sf::Texture roomElementTexture;
    sf::Sprite roomElementSprite;
    std::vector<sf::IntRect> spriteFrames;
    sf::RenderWindow &window;
    int frame = 0;
    float dt = 0;
    float animationTime = 0.0f;
    float animationHolding = roomElementHoldTime;
};
#endif
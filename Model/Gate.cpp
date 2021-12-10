#include <iostream>
#include <cmath>

#include "Gate.h"

bool Gate::getisOpen()
{
    return isOpen;
}

void Gate::setisOpen(bool isOpen)
{
    this->isOpen = isOpen;
    if (isOpen)
    {
        spriteFrames[0].left = spriteFrames[0].left + abs(spriteFrames[0].width);
    }
    else
    {
        spriteFrames[0].left = spriteFrames[0].left - abs(spriteFrames[0].width);
    }
    mapElementSprite.setTextureRect(spriteFrames[0]);
}

Gate::Gate(sf::Vector2f position, std::vector<sf::IntRect> spriteFrames,
           const std::string mapElementFilePath, bool isOpen) : MapElement(position, spriteFrames, mapElementFilePath), isOpen(isOpen)
{
    if (isOpen)
    {
        this->spriteFrames[0].left = this->spriteFrames[0].left + abs(this->spriteFrames[0].width);
    }
    mapElementSprite.setTextureRect(this->spriteFrames[0]);
    mapElementSprite.setPosition(position);
}

Gate::~Gate() {}
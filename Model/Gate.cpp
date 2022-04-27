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

Gate::Gate(sf::Vector2f position, bool isMirrored, bool isOpen, std::vector<sf::IntRect> spriteFrames,
           const std::string mapElementFilePath) : MapElement(position, spriteFrames, mapElementFilePath), isOpen(isOpen)
{
    if (isMirrored)
        this->spriteFrames = this->mirroredSpriteFrames;
    else
        this->spriteFrames = this->notMirroredSpriteFrames;

    if (isOpen)
    {
        this->spriteFrames[0].left = this->spriteFrames[0].left + abs(this->spriteFrames[0].width);
    }
    mapElementSprite.setTextureRect(this->spriteFrames[0]);
    mapElementSprite.setPosition(position);
}

Gate::~Gate() {}
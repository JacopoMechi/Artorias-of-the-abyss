#include <iostream>
#include <cmath>

#include "Gate.h"

const sf::Vector2f Gate::leftPosition = {158.0f, 425.0f};
const sf::Vector2f Gate::rightPosition = {1626.0f, 425.0f};

bool Gate::getisOpen() const
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
    roomElementSprite.setTextureRect(spriteFrames[0]);
}

Gate::Gate(sf::RenderWindow &window, bool isMirrored, bool isOpen) : RoomElement(window), isOpen(isOpen)
{

    if (isMirrored)
    {
        spriteFrames = SpriteFrames;
        spriteFrames[0].left += spriteFrames[0].width;
        spriteFrames[0].width = -spriteFrames[0].width;
        roomElementSprite.setPosition(rightPosition);
    }

    else
    {
        spriteFrames = SpriteFrames;
        roomElementSprite.setPosition(leftPosition);
    }

    if (isOpen)
    {
        spriteFrames[0].left = spriteFrames[0].left + abs(spriteFrames[0].width);
    }
    roomElementSprite.setTextureRect(spriteFrames[0]);
}

Gate::~Gate() {}
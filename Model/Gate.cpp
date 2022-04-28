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
    roomElementSprite.setTextureRect(spriteFrames[0]);
}

Gate::Gate(bool isMirrored, bool isOpen) : RoomElement(), isOpen(isOpen)
{

    if (isMirrored)
    {
        spriteFrames = mirroredSpriteFrames;
        roomElementSprite.setPosition(mirroredPosition);
    }

    else
    {
        spriteFrames = notMirroredSpriteFrames;
        roomElementSprite.setPosition(notMirroredPosition);
    }

    if (isOpen)
    {
        spriteFrames[0].left = spriteFrames[0].left + abs(spriteFrames[0].width);
    }
    roomElementSprite.setTextureRect(spriteFrames[0]);
}

Gate::~Gate() {}
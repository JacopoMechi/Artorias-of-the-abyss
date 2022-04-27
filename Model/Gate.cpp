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

Gate::Gate(bool isMirrored, bool isOpen) : MapElement(), isOpen(isOpen)
{

    if (isMirrored)
    {
        spriteFrames = mirroredSpriteFrames;
        mapElementSprite.setPosition(mirroredPosition);
    }

    else
    {
        spriteFrames = notMirroredSpriteFrames;
        mapElementSprite.setPosition(notMirroredPosition);
    }

    if (isOpen)
    {
        spriteFrames[0].left = spriteFrames[0].left + abs(spriteFrames[0].width);
    }
    mapElementSprite.setTextureRect(spriteFrames[0]);
}

Gate::~Gate() {}
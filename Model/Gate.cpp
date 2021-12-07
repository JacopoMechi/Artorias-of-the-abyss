#include "Gate.h"

#include <SFML/System.hpp>
#include <iostream>
#include <string>
#include <vector>

bool Gate::getisOpen()
{
    return isOpen;
}

void Gate::setisOpen(bool isOpen)
{
    this->isOpen = isOpen;
    if (isOpen)
    {
        spriteDimension.left = spriteDimension.left + spriteDimension.width;
    }
    else
    {
        spriteDimension.left = spriteDimension.left - spriteDimension.width;
    }
    mapElementSprite.setTextureRect(spriteDimension);
}

Gate::Gate(std::vector<int> spriteDimension, sf::Vector2f position, const std::string mapElementFilePath, bool isOpen) : MapElement(spriteDimension, position, mapElementFilePath), isOpen(isOpen)
{
    if (isOpen)
    {
        this->spriteDimension.left = this->spriteDimension.left + this->spriteDimension.width;
    }
    mapElementSprite.setTextureRect(this->spriteDimension);
    mapElementSprite.setPosition(position);
}

Gate::~Gate() {}
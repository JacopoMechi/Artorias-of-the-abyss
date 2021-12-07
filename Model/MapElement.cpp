#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include <vector>
#include <iostream>

#include "MapElement.h"

void MapElement::draw(sf::RenderWindow &window)
{
    window.draw(mapElementSprite);
}

sf::Vector2f MapElement::getPos()
{
    return mapElementSprite.getPosition();
}

void MapElement::setPos(sf::Vector2f &newPos)
{
    mapElementSprite.setPosition(newPos);
}

MapElement::MapElement(std::vector<int> &spriteDimension, sf::Vector2f &position, const std::string &mapElementFilePath)
{
    this->spriteDimension.left = spriteDimension[0];
    this->spriteDimension.top = spriteDimension[1];
    this->spriteDimension.width = spriteDimension[2];
    this->spriteDimension.height = spriteDimension[3];
    if (!mapElementTexture.loadFromFile(mapElementFilePath))
    {
        std::cout << "Error while setting MapElement texture" << std::endl;
    }
    mapElementSprite.setTexture(this->mapElementTexture);
    mapElementSprite.setTextureRect(MapElement::spriteDimension);
    mapElementSprite.setPosition(position);
}
MapElement::~MapElement() {}
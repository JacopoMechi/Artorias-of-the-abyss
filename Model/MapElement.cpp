#include "MapElement.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include <vector>
#include <iostream>

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

MapElement::MapElement(std::vector<int> &spriteDimension, sf::Vector2f &position, std::string &mapElementFilePath)
{
    if (!mapElementTexture.loadFromFile(mapElementFilePath))
    {
        std::cout << "Error while setting MapElement texture" << std::endl;
    }
    mapElementSprite.setTexture(this->mapElementTexture);
    mapElementSprite.setTextureRect(sf::IntRect(spriteDimension[0], spriteDimension[1], spriteDimension[2], spriteDimension[3]));
    mapElementSprite.setPosition(position);
}
MapElement::~MapElement() {}
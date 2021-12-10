#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include <vector>
#include <iostream>

#include "MapElement.h"

void MapElement::draw(sf::RenderWindow &window)
{
    mapElementSprite.setTextureRect(MapElement::spriteFrames[frame]);
    window.draw(mapElementSprite);
    if (spriteFrames.size() > 1)
    {
        if (frame < spriteFrames.size() - 1)
            frame++;
        else
            frame = 0;
    }

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

MapElement::MapElement(sf::Vector2f &position, std::vector<sf::IntRect> &spriteFrames, const std::string &mapElementFilePath)
{
    for (int i = 0; i < spriteFrames.size(); i++)
        MapElement::spriteFrames.push_back(spriteFrames[i]);
    if (!mapElementTexture.loadFromFile(mapElementFilePath))
    {
        std::cout << "Error while setting MapElement texture" << std::endl;
    }
    mapElementSprite.setTexture(this->mapElementTexture);
    mapElementSprite.setPosition(position);
}
MapElement::~MapElement() {}
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include <vector>
#include <iostream>

#include "RoomElement.h"

void RoomElement::draw(sf::RenderWindow &window)
{
    roomElementSprite.setTextureRect(RoomElement::spriteFrames[frame]);
    window.draw(roomElementSprite);
    if (spriteFrames.size() > 1)
    {
        if (frame < spriteFrames.size() - 1)
            frame++;
        else
            frame = 0;
    }

    window.draw(roomElementSprite);
}

sf::Vector2f RoomElement::getPos()
{
    return roomElementSprite.getPosition();
}

void RoomElement::setPos(sf::Vector2f &newPos)
{
    roomElementSprite.setPosition(newPos);
}

RoomElement::RoomElement(sf::Vector2f &position, std::vector<sf::IntRect> &spriteFrames, const std::string &roomElementFilePath)
{
    for (int i = 0; i < spriteFrames.size(); i++)
        RoomElement::spriteFrames.push_back(spriteFrames[i]);
    if (!roomElementTexture.loadFromFile(roomElementFilePath))
    {
        std::cout << "Error while setting RoomElement texture" << std::endl;
    }
    roomElementSprite.setTexture(roomElementTexture);
    roomElementSprite.setPosition(position);
}
RoomElement::RoomElement(const std::string &roomElementFilePath)
{
    if (!roomElementTexture.loadFromFile(roomElementFilePath))
    {
        std::cout << "Error while setting RoomElement texture" << std::endl;
    }
    roomElementSprite.setTexture(this->roomElementTexture);
}
RoomElement::~RoomElement() {}
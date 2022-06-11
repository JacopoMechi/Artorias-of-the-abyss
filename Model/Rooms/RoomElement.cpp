#include "Rooms/RoomElement.h"

void RoomElement::draw()
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

sf::Vector2f RoomElement::getPos() const
{
    return roomElementSprite.getPosition();
}

void RoomElement::setPos(sf::Vector2f &newPos)
{
    roomElementSprite.setPosition(newPos);
}

sf::Vector2f RoomElement::getSize() const
{
    return {this->roomElementSprite.getScale().x * spriteFrames[frame].width, this->roomElementSprite.getScale().y * spriteFrames[frame].height};
}

RoomElement::RoomElement(sf::RenderWindow &window, const std::string &roomElementFilePath) : window(window)
{
    if (!roomElementTexture.loadFromFile(roomElementFilePath))
    {
        std::cout << "Error while setting RoomElement texture" << std::endl;
    }
    roomElementSprite.setTexture(this->roomElementTexture);
}

RoomElement::RoomElement(sf::RenderWindow &window, const sf::Vector2f &position, const std::vector<sf::IntRect> &spriteFrames, const std::string &roomElementFilePath) : RoomElement(window, roomElementFilePath)
{
    for (int i = 0; i < spriteFrames.size(); i++)
        RoomElement::spriteFrames.push_back(spriteFrames[i]);
    roomElementSprite.setPosition(position);
}

RoomElement::~RoomElement() {}
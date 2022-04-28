#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

#include "Room.h"

void Room::spawnEntity(const RoomElement &roomElement)
{
    roomElementsVector.push_back(roomElement);
}

void Room::draw(sf::RenderWindow &window)
{
    roomSprite.setTextureRect(sf::IntRect(0, 0, 1920, 1080));
    window.draw(roomSprite);
    for (auto &roomElement : roomElementsVector)
        roomElement.draw(window);
}

Room::Room(const std::vector<RoomElement> &roomElementsVector, const std::string &roomFilePath)
{
    if (!roomTexture.loadFromFile(roomFilePath))
        std::cout << "Error while setting room texture" << std::endl;

    roomSprite.setTexture(this->roomTexture);

    for (int i = 0; i < roomElementsVector.size(); i++)
        this->roomElementsVector.push_back(roomElementsVector[i]);
}
Room::~Room() {}

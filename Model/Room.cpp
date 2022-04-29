#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

#include "Room.h"
#include "Gate.h"
#include "Bonfire.h"

void Room::spawnEntity(RoomElement *roomElement)
{
    roomElementsVector.emplace_back(roomElement);
}

void Room::draw(sf::RenderWindow &window)
{
    roomSprite.setTextureRect(sf::IntRect(0, 0, 1920, 1080));
    window.draw(roomSprite);
    for (auto &roomElement : roomElementsVector)
        roomElement->draw(window);
}

Room::Room(const std::vector<RoomElement *> &roomElementsVector, const Room::Type roomType)
{
    switch (roomType)
    {
    case Type::StartRoom:
        roomFilePath = this->roomPath1;
        this->roomElementsVector.emplace_back(new Gate);
        break;
    case Type::FirstLevel:
        roomFilePath = this->roomPath1;
        this->roomElementsVector.emplace_back(new Gate);
        this->roomElementsVector.emplace_back(new Gate(true, false));
        this->roomElementsVector.emplace_back(new Bonfire({500.0f, 500.0f}));
        break;
    case Type::SecondLevel:
        roomFilePath = this->roomPath2;
        this->roomElementsVector.emplace_back(new Gate);
        this->roomElementsVector.emplace_back(new Gate(true, false));
        this->roomElementsVector.emplace_back(new Bonfire({500.0f, 500.0f}));
        break;
    case Type::ThirdLevel:
        roomFilePath = this->roomPath3;
        this->roomElementsVector.emplace_back(new Gate);
        this->roomElementsVector.emplace_back(new Gate(true, false));
        this->roomElementsVector.emplace_back(new Bonfire({500.0f, 500.0f}));
        break;
    }

    if (!roomTexture.loadFromFile(roomFilePath))
        std::cout << "Error while setting room texture" << std::endl;

    roomSprite.setTexture(this->roomTexture);

    for (int i = 0; i < roomElementsVector.size(); i++)
        this->roomElementsVector.emplace_back(roomElementsVector[i]);
}
Room::~Room() {}

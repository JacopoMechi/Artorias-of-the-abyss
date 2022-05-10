#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <memory>

#include "Room.h"

void Room::spawnEntity(RoomElement *roomElement)
{
    roomElementsVector.emplace_back(roomElement);
}

void Room::draw()
{
    roomSprite.setTextureRect(sf::IntRect(0, 0, 1920, 1080));
    window.draw(roomSprite);
    if (leftGate != nullptr)
        leftGate->draw();
    if (rightGate != nullptr)
        rightGate->draw();
    if (bonfire != nullptr)
        bonfire->draw();
    for (auto &roomElement : roomElementsVector)
        roomElement->draw();
}

bool Room::getisClear()
{
    return isClear;
}

Room::Room(const std::vector<RoomElement *> &roomElementsVector, const Room::Type roomType, sf::RenderWindow &window) : window(window)
{
    switch (roomType)
    {
    case Type::StartRoom:
        roomFilePath = this->roomPath1;
        this->rightGate = std::make_unique<Gate>(window, true, false);
        break;
    case Type::FirstLevel:
        roomFilePath = this->roomPath1;
        this->leftGate = std::make_unique<Gate>(window);
        this->rightGate = std::make_unique<Gate>(window, true, false);
        this->bonfire = std::unique_ptr<Bonfire>(new Bonfire(window, {865.5f, 391.0f}));
        break;
    case Type::SecondLevel:
        roomFilePath = this->roomPath2;
        this->leftGate = std::make_unique<Gate>(window);
        this->rightGate = std::make_unique<Gate>(window, true, false);
        this->bonfire = std::unique_ptr<Bonfire>(new Bonfire(window, {865.5f, 391.0f}));
        break;
    case Type::ThirdLevel:
        roomFilePath = this->roomPath3;
        this->leftGate = std::make_unique<Gate>(window);
        this->rightGate = std::make_unique<Gate>(window, true, false);
        this->bonfire = std::unique_ptr<Bonfire>(new Bonfire(window, {865.5f, 391.0f}));
        break;
    case Type::FinalBoss:
        roomFilePath = this->roomPath3;
        this->leftGate = std::make_unique<Gate>(window);
        break;
    }

    if (!roomTexture.loadFromFile(roomFilePath))
        std::cout << "Error while setting room texture" << std::endl;

    roomSprite.setTexture(this->roomTexture);

    for (int i = 0; i < roomElementsVector.size(); i++)
        this->roomElementsVector.emplace_back(roomElementsVector[i]);
}
Room::~Room() {}

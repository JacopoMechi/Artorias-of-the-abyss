#include "Room.h"

Room::Room(Hero &hero, const std::vector<RoomElement *> &roomElementsVector, const Room::Type roomType, sf::RenderWindow &window) : window(window), hero(hero)
{
    switch (roomType)
    {
    case Type::StartRoom:
        roomFilePath = this->roomPath1;
        this->rightGate = std::make_unique<Gate>(window, true, false);
        enemyVector.emplace_back(enemyFactory.createEnemy(1, window, {500.0f, 500.0f}, 10, 10, 10, 1000.0f));
        break;
    case Type::FirstLevel:
        roomFilePath = this->roomPath1;
        this->leftGate = std::make_unique<Gate>(window);
        this->rightGate = std::make_unique<Gate>(window, true, false);
        this->bonfire = std::unique_ptr<Bonfire>(new Bonfire(window, {500.0f, 500.0f}));
        break;
    case Type::SecondLevel:
        roomFilePath = this->roomPath2;
        this->leftGate = std::make_unique<Gate>(window);
        this->rightGate = std::make_unique<Gate>(window, true, false);
        this->bonfire = std::unique_ptr<Bonfire>(new Bonfire(window, {500.0f, 500.0f}));
        break;
    case Type::ThirdLevel:
        roomFilePath = this->roomPath3;
        this->leftGate = std::make_unique<Gate>(window);
        this->rightGate = std::make_unique<Gate>(window, true, false);
        this->bonfire = std::unique_ptr<Bonfire>(new Bonfire(window, {500.0f, 500.0f}));
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

void Room::spawnEntity(RoomElement *roomElement)
{
    roomElementsVector.emplace_back(roomElement);
}

bool Room::getisClear()
{
    return isClear;
}

void Room::draw()
{
    roomSprite.setTextureRect({0, 0, 1920, 1080});
    window.draw(roomSprite);
    if (leftGate != nullptr)
        leftGate->draw();
    if (rightGate != nullptr)
        rightGate->draw();
    if (bonfire != nullptr)
    {
        bonfire->setDelayTime(dt);
        bonfire->draw();
    }
    if (npc != nullptr)
        npc->draw(window);
    enemyVector[0]->draw(window);
    enemyVector[0]->attack(hero);
    enemyVector[0]->update(dt);
}

Bonfire *Room::getBonfire()
{
    return bonfire.get();
}

NPC *Room::getNPC()
{
    return npc.get();
}

void Room::setDelayTime(float dt)
{
    this->dt = dt;
}
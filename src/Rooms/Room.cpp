#include "Room.h"

Room::Room(Hero &hero, const std::vector<RoomElement *> &roomElementsVector, const Room::Type roomType, sf::RenderWindow &window) : window(window), hero(hero)
{
    switch (roomType)
    {
    case Type::StartFirst:
        roomFilePath = this->roomPath1;
        this->rightGate = std::make_unique<Gate>(window, true, true);
        this->npc = std::unique_ptr<NPC>(new NPC(window, 1, {322.0f, 224.0f}));
        break;
    case Type::FirstFloor:
        roomFilePath = this->roomPath1;
        this->leftGate = std::make_unique<Gate>(window);
        this->rightGate = std::make_unique<Gate>(window, true, false);
        enemyVector.emplace_back(enemyFactory.createEnemy(1, window, {900.0f, 200.0f}, 10, 10, 10, 1000.0f));
        break;
    case Type::StartSecond:
        roomFilePath = this->roomPath2;
        this->leftGate = std::make_unique<Gate>(window);
        this->rightGate = std::make_unique<Gate>(window, true, false);
        this->npc = std::unique_ptr<NPC>(new NPC(window, 0, {322.0f, 224.0f}));
        break;
    case Type::SecondFloor:
        roomFilePath = this->roomPath2;
        this->leftGate = std::make_unique<Gate>(window);
        this->rightGate = std::make_unique<Gate>(window, true, false);
        enemyVector.emplace_back(enemyFactory.createEnemy(1, window, {900.0f, 200.0f}, 10, 10, 10, 1000.0f));
        break;
    case Type::StartThird:
        roomFilePath = this->roomPath3;
        this->leftGate = std::make_unique<Gate>(window);
        this->rightGate = std::make_unique<Gate>(window, true, false);
        break;
    case Type::ThirdFloor:
        roomFilePath = this->roomPath3;
        this->leftGate = std::make_unique<Gate>(window);
        this->rightGate = std::make_unique<Gate>(window, true, false);
        enemyVector.emplace_back(enemyFactory.createEnemy(1, window, {900.0f, 200.0f}, 10, 10, 10, 1000.0f));
        break;
    case Type::LastLevel:
        roomFilePath = this->roomPath3;
        this->leftGate = std::make_unique<Gate>(window);
        this->rightGate = std::make_unique<Gate>(window, true, false);
        this->bonfire = std::unique_ptr<Bonfire>(new Bonfire(window, {900.0f, 400.0f}));
        enemyVector.emplace_back(enemyFactory.createEnemy(1, window, {900.0f, 200.0f}, 10, 10, 10, 1000.0f));
        this->npc = std::unique_ptr<NPC>(new NPC(window, 3, {322.0f, 224.0f}));
        break;
    case Type::FinalBoss:
        roomFilePath = this->roomPath3;
        this->leftGate = std::make_unique<Gate>(window);
        enemyVector.emplace_back(enemyFactory.createEnemy(1, window, {900.0f, 200.0f}, 10, 10, 10, 1000.0f));
        this->npc = std::unique_ptr<NPC>(new NPC(window, 2, {322.0f, 224.0f}));
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
    if (enemyVector.size() != 0)
    {
        if (enemyVector[0]->getHp() <= 0){
            enemyVector.erase(enemyVector.begin());
            this->bonfire = std::unique_ptr<Bonfire>(new Bonfire(window, {900.0f, 400.0f}));
            if (leftGate != nullptr)
                leftGate->setisOpen(true);
            if (rightGate != nullptr)
                rightGate->setisOpen(true);
        }else
        {
            enemyVector[0]->draw(window);
            enemyVector[0]->attack(hero, dt);
            enemyVector[0]->update(dt);
            hero.dealDamage(*enemyVector[0].get());
        }
    }
    else
    {
        if (bonfire != nullptr)
        {
            bonfire->setDelayTime(dt);
            bonfire->draw();
        }
        if (npc != nullptr)
            npc->draw(window);
    }
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
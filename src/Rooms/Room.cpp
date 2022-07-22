#include "Room.h"

Room::Room(Hero &hero, const std::vector<RoomElement *> &roomElementsVector, const Room::Type roomType, sf::RenderWindow &window) : window(window), hero(hero)
{
    switch (roomType)
    {
    case Type::StartFirst:
        roomFilePath = this->roomPath1;
        this->rightGate = std::make_unique<Gate>(window, true, true);
        this->npc = std::unique_ptr<NPC>(new NPC(window, 1, {npcSpawnX, npcSpawnY}));
        break;
    case Type::FirstFloor:
        roomFilePath = this->roomPath1;
        this->leftGate = std::make_unique<Gate>(window);
        this->rightGate = std::make_unique<Gate>(window, true, false);
        enemyVector.emplace_back(enemyFactory.createEnemy(1, window, {enemySpawnX, enemySpawnY}, 10, 0, 1000, 1000.0f));
        break;
    case Type::StartSecond:
        roomFilePath = this->roomPath2;
        this->leftGate = std::make_unique<Gate>(window, false, true);
        this->rightGate = std::make_unique<Gate>(window, true, true);
        this->npc = std::unique_ptr<NPC>(new NPC(window, 0, {npcSpawnX, npcSpawnY}));
        break;
    case Type::SecondFloor:
        roomFilePath = this->roomPath2;
        this->leftGate = std::make_unique<Gate>(window);
        this->rightGate = std::make_unique<Gate>(window, true, false);
        enemyVector.emplace_back(enemyFactory.createEnemy(1, window, {enemySpawnX, enemySpawnY}, 10, 0, 1000, 1000.0f));
        break;
    case Type::StartThird:
        roomFilePath = this->roomPath3;
        this->leftGate = std::make_unique<Gate>(window, false, true);
        this->rightGate = std::make_unique<Gate>(window, true, true);
        break;
    case Type::ThirdFloor:
        roomFilePath = this->roomPath3;
        this->leftGate = std::make_unique<Gate>(window);
        this->rightGate = std::make_unique<Gate>(window, true, false);
        enemyVector.emplace_back(enemyFactory.createEnemy(1, window, {enemySpawnX, enemySpawnY}, 10, 0, 1000, 1000.0f));
        break;
    case Type::LastLevel:
        roomFilePath = this->roomPath3;
        this->leftGate = std::make_unique<Gate>(window);
        this->rightGate = std::make_unique<Gate>(window, true, false);
        this->bonfire = std::unique_ptr<Bonfire>(new Bonfire(window, {bonfireSpawnX, bonfireSpawnY}));
        enemyVector.emplace_back(enemyFactory.createEnemy(1, window, {enemySpawnX, enemySpawnY}, 10, 0, 1000, 1000.0f));
        this->npc = std::unique_ptr<NPC>(new NPC(window, 3, {npcSpawnX, npcSpawnY}));
        break;
    case Type::FinalBoss:
        roomFilePath = this->roomPath3;
        this->leftGate = std::make_unique<Gate>(window);
        enemyVector.emplace_back(enemyFactory.createEnemy(1, window, {enemySpawnX, enemySpawnY}, 10, 0, 1000, 1000.0f));
        this->npc = std::unique_ptr<NPC>(new NPC(window, 2, {npcSpawnX, npcSpawnY}));
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

void Room::draw(int level)
{
    roomSprite.setTextureRect({roomX, roomY, roomWidth, roomHeight});
    window.draw(roomSprite);
    if (leftGate != nullptr)
        leftGate->draw();
    if (rightGate != nullptr)
        rightGate->draw();
    if (enemyVector.size() != 0)
    {
        if (enemyVector[0]->getHp() <= 0)
        {
            // drop money and give to hero
            hero.setCash(hero.getCash() + enemyVector[0]->getCash());

            // removing enemy
            enemyVector.erase(enemyVector.begin());

            // spawing bonfire because fight is over
            this->bonfire = std::unique_ptr<Bonfire>(new Bonfire(window, {bonfireSpawnX, bonfireSpawnY}));

            // open gates because the fight is over
            if (leftGate != nullptr)
                leftGate->setisOpen(true);
            if (rightGate != nullptr)
                rightGate->setisOpen(true);
        }
        else
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
        if (level == secondFloor)
            hero.changeLevel(1);
        else if (level == thirdFloor)
            hero.changeLevel(2);
        if (achivementObserver != nullptr)
            achivementObserver->update("Defeated Enemy");
    }
}

void Room::attach(AchivementsObserver &achivementsObserver)
{
    this->achivementObserver = std::unique_ptr<AchivementsObserver>(&achivementsObserver);
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
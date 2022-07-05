
#include "Room.h"

Room::Room(int level, sf::RenderWindow &window) : level(level), window(window)
{
}

void Room::spawnEntity(RoomElement *roomElement)
{
    roomElementsVector.emplace_back(roomElement);
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
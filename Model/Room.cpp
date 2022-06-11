
#include "Room.h"

Room::Room(int level, sf::RenderWindow &window) : level(level), window(window)
{
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
    enemy->draw(window);
    if (leftGate != nullptr)
        leftGate->draw();
    if (rightGate != nullptr)
        rightGate->draw();
    if (bonfire != nullptr)
        bonfire->draw();
}

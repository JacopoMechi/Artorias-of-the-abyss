#include "StartRoom.h"

StartRoom::StartRoom(int level, sf::RenderWindow &window) : Room(level, window)
{
    roomFilePath = roomPath1;
    rightGate = std::make_unique<Gate>(window, true, true);
    roomTexture.loadFromFile(roomFilePath);
    roomSprite.setTexture(roomTexture);
}
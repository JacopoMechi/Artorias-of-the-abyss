#ifndef _ROOM_H
#define _ROOM_H

#include <vector>
#include <SFML/Graphics.hpp>

#include "RoomElement.h"

class Room
{
public:
    Room(const std::vector<RoomElement> &roomElementsVector, const std::string &roomFilePath);
    ~Room();
    void spawnEntity(const RoomElement &roomElement);
    void draw(sf::RenderWindow &window);

private:
    std::vector<RoomElement> roomElementsVector;
    sf::Texture roomTexture;
    sf::Sprite roomSprite;
};
#endif
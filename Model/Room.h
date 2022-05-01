#ifndef _ROOM_H
#define _ROOM_H

#include <vector>
#include <SFML/Graphics.hpp>

#include "RoomElement.h"

class Room
{
public:
    enum class Type
    {
        StartRoom,
        FirstLevel,
        SecondLevel,
        ThirdLevel
    };
    Room(const std::vector<RoomElement *> &roomElementsVector, const Room::Type roomType, sf::RenderWindow &window);
    ~Room();
    void spawnEntity(RoomElement *roomElement);
    void draw();

private:
    std::vector<std::unique_ptr<RoomElement>> roomElementsVector;
    sf::Texture roomTexture;
    sf::Sprite roomSprite;
    std::string roomFilePath;
    std::string roomPath1 = "../Textures/Lvl1.png";
    std::string roomPath2 = "../Textures/Lvl2.png";
    std::string roomPath3 = "../Textures/Lvl3.png";
    sf::RenderWindow &window;
};
#endif
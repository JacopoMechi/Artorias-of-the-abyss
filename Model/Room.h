#ifndef _ROOM_H
#define _ROOM_H

#include <vector>
#include <SFML/Graphics.hpp>

#include "RoomElement.h"
#include "Gate.h"
#include "Bonfire.h"

class Room
{
public:
    enum class Type
    {
        StartRoom,
        FirstLevel,
        SecondLevel,
        ThirdLevel,
        FinalBoss
    };
    Room(const std::vector<RoomElement *> &roomElementsVector, const Room::Type roomType, sf::RenderWindow &window);
    ~Room();
    void spawnEntity(RoomElement *roomElement);
    void draw();
    bool getisClear();

private:
    std::vector<std::unique_ptr<RoomElement>> roomElementsVector;
    std::unique_ptr<Gate> entranceGate;
    std::unique_ptr<Gate> exitGate;
    std::unique_ptr<Bonfire> bonfire;
    std::string roomFilePath;
    std::string roomPath1 = "../Textures/Lvl1.png";
    std::string roomPath2 = "../Textures/Lvl2.png";
    std::string roomPath3 = "../Textures/Lvl3.png";
    sf::Texture roomTexture;
    sf::Sprite roomSprite;
    sf::RenderWindow &window;
    bool isClear = true; // TODO Default should be false, true for testing
};
#endif
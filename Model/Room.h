#ifndef _ROOM_H
#define _ROOM_H

#include <vector>
#include <SFML/Graphics.hpp>

#include "RoomElement.h"
#include "Gate.h"
#include "Bonfire.h"

class Room{
public:

    std::unique_ptr<Gate> leftGate;
    std::unique_ptr<Gate> rightGate;
    
    Room(int level, sf::RenderWindow &window);

    virtual ~Room() = 0;
    void spawnEntity(RoomElement *roomElement);
    void draw();
    bool getisClear();

protected:
    std::vector<std::unique_ptr<RoomElement>> roomElementsVector;
    std::unique_ptr<Bonfire> bonfire;
    std::string roomFilePath;
    const std::string roomPath1 = "../Textures/Lvl1.png";
    const std::string roomPath2 = "../Textures/Lvl2.png";
    const std::string roomPath3 = "../Textures/Lvl3.png";
    sf::Texture roomTexture;
    sf::Sprite roomSprite;
    sf::RenderWindow &window;
    bool isClear = true; // TODO Default should be false, true for testing
};
#endif
#ifndef _ROOM_H
#define _ROOM_H

#include <vector>
#include <SFML/Graphics.hpp>
#include <string>
#include <memory>
#include <iostream>

#include "RoomElement.h"
#include "Gate.h"
#include "Bonfire.h"
#include "GameCharacters/Enemies/Enemy.h"
#include "GameCharacters/NPC.h"

class Room
{
public:
    Room(int level, sf::RenderWindow &window);

    std::unique_ptr<Gate> leftGate;
    std::unique_ptr<Gate> rightGate;

    void spawnEntity(RoomElement *roomElement);
    void draw();

    Bonfire *getBonfire();
    NPC *getNPC();
    void setDelayTime(float dt);

protected:
    std::vector<std::unique_ptr<RoomElement>> roomElementsVector;
    std::vector<std::unique_ptr<Enemy>> enemyVector;
    std::unique_ptr<Bonfire> bonfire;
    std::unique_ptr<NPC> npc;
    std::string roomFilePath;
    const std::string roomPath1 = "../Textures/Lvl1.png";
    const std::string roomPath2 = "../Textures/Lvl2.png";
    const std::string roomPath3 = "../Textures/Lvl3.png";
    sf::Texture roomTexture;
    sf::Sprite roomSprite;
    sf::RenderWindow &window;
    int level;
    float dt = 0; // to take delay time for bonfire animation
};
#endif
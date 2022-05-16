#ifndef _GAME_H
#define _GAME_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Room.h"
#include "Menu.h"
#include "Hero.h"
#include "HUD.h"
#include "RoomFactory.h"

class Game
{
public:
    enum class Status
    {
        MainMenu,
        InGameMenu,
        Inventory,
        Interacting,
        Playing
    };
    void setStatus(Game::Status gameStatus);
    void gameLoop();
    Game(sf::RenderWindow &window);

private:
    //int level = 0;
    int levelReached = 0;
    float dt = 0.0f;
    bool NPCInteraction = false;//to block character when is interacting with an NPC
    RoomFactory* gameRooms = new RoomFactory();
    Room* room;
    //std::vector<std::unique_ptr<Room>> levels;
    Status gameStatus = Game::Status::MainMenu;
    Menu mainMenu;
    Menu inGameMenu;
    sf::RenderWindow &window;
    Hero hero;
    HUD hud;
    sf::Clock clock;
    sf::Event event;
};

#endif //_GAME_H
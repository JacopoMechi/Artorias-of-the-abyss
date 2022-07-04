#ifndef _GAME_H
#define _GAME_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Rooms/Room.h"
#include "Menu.h"
#include "GameCharacters/Hero.h"
#include "HUD.h"
#include "Rooms/RoomFactory.h"
#include "GameCharacters/NPC.h"

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
    void changeRoom();
    Game(sf::RenderWindow &window);

private:
    // to manage rooms and levels
    int level = 1; // current level
    int levelReached = 10;

    float dt = 0.0f;
    bool NPCInteraction = false; // to block character when is interacting with an NPC

    // for room factory creation
    std::unique_ptr<RoomFactory> roomsFactory;
    std::unique_ptr<Room> room;

    Status gameStatus = Game::Status::MainMenu;
    Menu mainMenu;
    Menu inGameMenu;
    sf::RenderWindow &window;
    Hero hero;
    HUD hud;
    NPC npc;
    sf::Clock clock;
    sf::Event event;
};

#endif //_GAME_H
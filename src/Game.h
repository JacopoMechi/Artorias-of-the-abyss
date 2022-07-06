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
#include "Inventory.h"
#include "CharacterInputs.h"
#include "Shop.h"

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
    void swapRoom(std::string tracker, int floor);
    Game(sf::RenderWindow &window);

private:
    //to manage rooms and floors
    std::string roomType[5];//array of room names
    int roomTracker = 0;//for tracking what room needs to be spawned
    int level = 1;//for floors

    int levelReached = 0;
    float dt = 0.0f;
    bool entityInteraction = false;//to block character when is interacting with a bonfire
    bool NPCInteraction = false;//to block character when is interacting with an NPC

    //for room factory creation
    std::unique_ptr<RoomFactory> gameRooms;
    std::unique_ptr<Room> room;

    Status gameStatus = Game::Status::MainMenu;
    Menu mainMenu;
    Menu inGameMenu;
    sf::RenderWindow &window;
    Hero hero;
    HUD hud;
    Inventory inventory;
    Shop shop;
    sf::Clock clock;
    sf::Event event;
    CharacterInputs inputs;
};

#endif //_GAME_H
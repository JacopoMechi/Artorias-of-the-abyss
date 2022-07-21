#ifndef _GAME_H
#define _GAME_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Rooms/Room.h"
#include "GUI/Menu.h"
#include "GameCharacters/Hero.h"
#include "GUI/HUD.h"
#include "GameCharacters/NPC.h"
#include "GUI/Inventory.h"
#include "CharacterInputs.h"
#include "GUI/Shop.h"
#include "Constants.h"

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
    // to manage rooms and floors
    int level = 0;
    int respawnLevel = 0;
    std::vector<std::unique_ptr<Room>> levels;

    float dt = 0.0f;
    bool entityInteraction = false; // to block character when is interacting with a bonfire
    bool NPCInteraction = false;    // to block character when is interacting with an NPC

    Status gameStatus = Game::Status::MainMenu;
    Menu mainMenu;
    Menu inGameMenu;
    sf::RenderWindow &window;
    std::unique_ptr<Hero> hero;
    std::unique_ptr<HUD> hud;
    Inventory inventory;
    Shop shop;
    sf::Clock clock;
    sf::Event event;
    std::unique_ptr<CharacterInputs> inputs;
};

#endif //_GAME_H
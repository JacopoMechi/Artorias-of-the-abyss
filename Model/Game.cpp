#include "Game.h"

void Game::setStatus(Game::Status gameStatus)
{
    this->gameStatus = gameStatus;
}

void Game::gameLoop()
{
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            inGameMenu.updateEvent(event);
            if (event.type == sf::Event::Closed)
                window.close();
            hud.updateEvent(event);
        }
        hero.updateDelayAndInputs(event, dt);
        hud.gettingDelayTime(dt);
        window.clear(sf::Color::Black);
        room -> draw();
        if (gameStatus == Game::Status::MainMenu)
        {
            mainMenu.launch();
            if (mainMenu.getStartGame())
                gameStatus = Game::Status::Playing;
        }
        else if (gameStatus == Game::Status::InGameMenu)
        {
            inGameMenu.launch();
            if (inGameMenu.getStartGame())
                gameStatus = Game::Status::Playing;
        }
        else if (gameStatus == Game::Status::Playing)
        {
            if (!inGameMenu.getStartGame() && mainMenu.getStartGame())
                gameStatus = Game::Status::InGameMenu;
            else
            {
                if (room->rightGate != nullptr)
                {
                    if (room->rightGate->getisOpen() &&
                        hero.getPos().x + hero.getSize().x > room->rightGate->getPos().x &&
                        hero.getPos().y + hero.getSize().y / 2 > room->rightGate->getPos().y &&
                        hero.getPos().y + hero.getSize().y / 2 < room->rightGate->getPos().y + room->rightGate->getSize().y)
                    {
                        hero.setPos(Gate::leftPosition + sf::Vector2f{hero.getSize().x, 0});

                        //switching to next room
                        roomTracker++;
                        this -> swapRoom(roomType[roomTracker], level);
                    }
                }
                if (room->leftGate != nullptr)
                {
                    if (room->leftGate->getisOpen() &&
                        hero.getPos().x < room->leftGate->getPos().x + room->leftGate->getSize().x &&
                        hero.getPos().y + hero.getSize().y / 2 > room->leftGate->getPos().y &&
                        hero.getPos().y + hero.getSize().y / 2 < room->leftGate->getPos().y + room->leftGate->getSize().y)
                    {
                        hero.setPos(Gate::rightPosition - sf::Vector2f{hero.getSize().x, 0});
                        
                        //switching to previous room
                        roomTracker--;
                        this -> swapRoom(roomType[roomTracker], level);
                    }
                }
                hud.setTextPool(npc.getTextPool());
                hud.setNPCType(npc.getNPCType());
                NPCInteraction = hud.getIsInteraction();
                hero.movement(hud.getInvIsOpen(), NPCInteraction);
                hero.update(dt);
                hero.draw(window);
                npc.draw(window);
                hud.checkNPCAggro(npc);
                hud.draw();
                hud.displayHealthAndEffects(hero);
                hud.displayMoneyCounter(hero);
            }
        }
        window.display();
        dt = clock.getElapsedTime().asSeconds();
        clock.restart();
    }
}

void Game::swapRoom(std::string tracker, int floor){
    room = gameRooms -> makeRoom(tracker, window, floor);
}

Game::Game(sf::RenderWindow &window) : mainMenu(window, 1), inGameMenu(window, 0), window(window), hero(true, {500.0f, 500.0f}, 1, 20, 0, 500.0f), hud(window, hero), 
    room(gameRooms -> makeRoom("startingroom", window, 1)), roomType{std::string("startroom"),std::string("secondroom"), std::string("thirdroom"), std::string("fourthroom"), std::string("finalroom")},
    npc(window, 1, {300, 300})
{
    
}

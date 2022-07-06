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
            inputs.updateInputs(event);
        }
        inputs.setEntityCollision(room -> getBonfire());
        inputs.moveHero(event);
        if(room -> getNPC() != 0 ){//calling function in case NPC doesn't exists
            shop.setNPCType(room -> getNPC() -> getNPCType());
            hud.setType(room -> getNPC() -> getNPCType());
            inputs.setEntityCollision(room -> getNPC());
            NPCInteraction = room -> getNPC() -> closeToHero(hero);
            hud.setTextPool(room -> getNPC() -> getTextPool());
        }
        if(room -> getBonfire() != 0 ){//calling function in case bonfire doesn't exists
            entityInteraction = room -> getBonfire() -> closeToHero(hero.getPos());
            inputs.setEntityCollision(room -> getBonfire());
        }
        hud.setAggro(entityInteraction, NPCInteraction);
        window.clear(sf::Color::Black);
        room -> setDelayTime(dt);
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
                        swapRoom(roomType[roomTracker], level);
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
                        swapRoom(roomType[roomTracker], level);
                    }
                }
                //teleporting hero at respawn point in case he's dead or he used an homeward bone
                if(inventory.receiveItem(2) -> getIsRespawn() || hero.getHp() == 0){
                    if(hero.getSpawnPoint().x == 500.0f){//which means if spawn spoint is set to starting room
                        roomTracker = 0;
                        swapRoom(roomType[roomTracker], level);
                    }else{//if hero interacted with a bonfire
                        roomTracker = 1;//for the moment because middleroom must be in the middle of the level
                        swapRoom(roomType[roomTracker], level);
                    }
                    hero.setPos(hero.getSpawnPoint());
                    hero.setHp(100);//reset hero's hp
                    inventory.receiveItem(0) -> setItemCount(5 -  inventory.receiveItem(0) -> getItemCount());//reset estus flask amount
                    inventory.receiveItem(2) -> setIsRespawn(false);
                }
                inputs.setHeroEntityAggro(NPCInteraction, entityInteraction);
                hero.movement(false, entityInteraction);//for the moment
                hero.update(dt);
                hero.draw(window);
                hud.draw();
                hud.displayHealthAndEffects(hero);
                hud.displayMoneyCounter(hero);
                shop.draw();
                hero.updateDelay(dt);
                hud.gettingDelayTime(dt);
            }
        }
        window.display();
        dt = clock.getElapsedTime().asSeconds();
        clock.restart();
    }
}

void Game::swapRoom(std::string tracker, int floor){
    room = gameRooms -> makeRoom(tracker, window, floor);
    //setting spawn point for hero in case it changes level and he's in the first room
    if(roomType[roomTracker] == "startingRoom")
        hero.setSpawnPoint({500.0f, 500.f});
}

Game::Game(sf::RenderWindow &window) : mainMenu(window, 1), inventory(window), inGameMenu(window, 0), window(window), hero(true, {500.0f, 500.0f}, 1, 20, 0, 500.0f), hud(window, hero, inventory), 
    room(gameRooms -> makeRoom("startingroom", window, 1)), roomType{std::string("startingroom"),std::string("middleroom"), std::string("room"), std::string("room"), std::string("room")},
    shop(window), inputs(inventory, hud, hero, shop)
{
    
}

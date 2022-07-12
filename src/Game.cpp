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
        inputs.moveHero(event);
        hud.setAggro(entityInteraction, NPCInteraction);
        window.clear(sf::Color::Black);
        levels[level]->draw();
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
                if (levels[level]->rightGate != nullptr)
                {
                    if (levels[level]->rightGate->getisOpen() &&
                        hero.getPos().x + hero.getSize().x > levels[level]->rightGate->getPos().x &&
                        hero.getPos().y + hero.getSize().y / 2 > levels[level]->rightGate->getPos().y &&
                        hero.getPos().y + hero.getSize().y / 2 < levels[level]->rightGate->getPos().y + levels[level]->rightGate->getSize().y)
                    {
                        hero.setPos(Gate::leftPosition + sf::Vector2f{hero.getSize().x, 0});

                        // switching to next room
                        level++;
                        levelReached++;
                    }
                }
                if (levels[level]->leftGate != nullptr)
                {
                    if (levels[level]->leftGate->getisOpen() &&
                        hero.getPos().x < levels[level]->leftGate->getPos().x + levels[level]->leftGate->getSize().x &&
                        hero.getPos().y + hero.getSize().y / 2 > levels[level]->leftGate->getPos().y &&
                        hero.getPos().y + hero.getSize().y / 2 < levels[level]->leftGate->getPos().y + levels[level]->leftGate->getSize().y)
                    {
                        hero.setPos(Gate::rightPosition - sf::Vector2f{hero.getSize().x, 0});

                        // switching to previous room
                        level--;
                    }
                }
                // teleporting hero at respawn point in case he's dead or he used an homeward bone
                if (inventory.receiveItem(2)->getIsRespawn() || hero.getHp() == 0)
                {
                    if (hero.getSpawnPoint().x == 500.0f)
                    { // which means if spawn spoint is set to starting room
                        level = 0;
                    }
                    else
                    {              // if hero interacted with a bonfire
                        level = 1; // for the moment because middleroom must be in the middle of the level
                    }
                    hero.setPos(hero.getSpawnPoint());
                    hero.setHp(100);                                                                      // reset hero's hp
                    inventory.receiveItem(0)->setItemCount(5 - inventory.receiveItem(0)->getItemCount()); // reset estus flask amount
                    inventory.receiveItem(2)->setIsRespawn(false);
                }

                inputs.setHeroEntityAggro(NPCInteraction, entityInteraction);
                hero.movement(false, entityInteraction); // for the moment
                hero.update(dt);
                hero.draw(window);
                hero.attack(window);
                hud.draw();
                hud.displayHealthAndEffects(hero);
                hud.displayMoneyCounter(hero);
                shop.draw();
                hero.updateDelay(dt);
                hud.gettingDelayTime(dt);
                levels[level]->setDelayTime(dt);
            }
        }
        window.display();
        dt = clock.getElapsedTime().asSeconds();
        clock.restart();
    }
}

Game::Game(sf::RenderWindow &window) : mainMenu(window, 1), inventory(window), inGameMenu(window, 0), window(window), hero(window, true, {500.0f, 500.0f}, 1, 20, 0, 500.0f), hud(window, hero, inventory),
                                       shop(window), inputs(inventory, hud, hero, shop)
{
    this->levels.emplace_back(new Room(hero, {}, Room::Type::StartRoom, window));
    for (int i = 0; i <= 3; i++)
        this->levels.emplace_back(new Room(hero, {}, Room::Type::FirstLevel, window));
    for (int i = 0; i <= 3; i++)
        this->levels.emplace_back(new Room(hero, {}, Room::Type::SecondLevel, window));
    for (int i = 0; i <= 2; i++)
        this->levels.emplace_back(new Room(hero, {}, Room::Type::ThirdLevel, window));
    this->levels.emplace_back(new Room(hero, {}, Room::Type::FinalBoss, window));
}

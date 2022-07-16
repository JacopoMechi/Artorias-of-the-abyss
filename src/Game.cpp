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
            if (inputs != nullptr)
                inputs->updateInputs(event);
        }
        if (inputs != nullptr)
            inputs->moveHero(event);
        if (hud != nullptr)
            hud->setAggro(entityInteraction, NPCInteraction);
        window.clear(sf::Color::Black);
        levels[level]->draw();
        if (gameStatus == Game::Status::MainMenu)
        {
            mainMenu.launch();
            if (mainMenu.getStartGame())
            {
                gameStatus = Game::Status::Playing;
                hero = std::unique_ptr<Hero>(new Hero(window, mainMenu.getIsKnight(), {500.0f, 500.0f}, 100, 0, 500.0f));
                hud = std::unique_ptr<HUD>(new HUD(window, *hero.get(), inventory));
                inputs = std::unique_ptr<CharacterInputs>(new CharacterInputs(inventory, *hud.get(), *hero.get(), shop));
                inGameMenu.setStartGame(true);
            }
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
                        hero->getPos().x + hero->getSize().x > levels[level]->rightGate->getPos().x &&
                        hero->getPos().y + hero->getSize().y / 2 > levels[level]->rightGate->getPos().y &&
                        hero->getPos().y + hero->getSize().y / 2 < levels[level]->rightGate->getPos().y + levels[level]->rightGate->getSize().y)
                    {
                        hero->setPos(Gate::leftPosition + sf::Vector2f{hero->getSize().x, 0});
                        // clearing pointers of npc and bonfire
                        inputs->deleteEntity();
                        inputs->deleteNPC();
                        // switching to next room
                        level++;
                        levelReached++;
                    }
                }
                if (levels[level]->leftGate != nullptr)
                {
                    if (levels[level]->leftGate->getisOpen() &&
                        hero->getPos().x < levels[level]->leftGate->getPos().x + levels[level]->leftGate->getSize().x &&
                        hero->getPos().y + hero->getSize().y / 2 > levels[level]->leftGate->getPos().y &&
                        hero->getPos().y + hero->getSize().y / 2 < levels[level]->leftGate->getPos().y + levels[level]->leftGate->getSize().y)
                    {
                        hero->setPos(Gate::rightPosition - sf::Vector2f{hero->getSize().x, 0});
                        // clearing pointers of npc and bonfire
                        inputs->deleteEntity();
                        inputs->deleteNPC();
                        // switching to previous room
                        level--;
                    }
                }
                // teleporting hero at respawn point in case he's dead or he used an homeward bone
                if (inventory.receiveItem(2)->getIsRespawn() || hero->getHp() == 0)
                {
                    if (hero->getSpawnPoint().x == 500.0f)
                    { // which means if spawn spoint is set to starting room
                        level = 0;
                    }
                    else
                    {              // if hero interacted with a bonfire
                        level = 1; // for the moment because middleroom must be in the middle of the level
                    }
                    hero->setPos(hero->getSpawnPoint());
                    hero->setHp(100);                                                                     // reset hero's hp
                    inventory.receiveItem(0)->setItemCount(5 - inventory.receiveItem(0)->getItemCount()); // reset estus flask amount
                    inventory.receiveItem(2)->setIsRespawn(false);
                }
                if (levels[level]->getBonfire() != nullptr)
                {
                    entityInteraction = levels[level]->getBonfire()->closeToHero(hero->getPos());
                    inputs->setEntityCollision(levels[level]->getBonfire());
                }
                else
                    entityInteraction = false;

                if (levels[level]->getNPC() != nullptr)
                {
                    shop.setNPCType(levels[level]->getNPC()->getNPCType());
                    hud->setType(levels[level]->getNPC()->getNPCType());
                    hud->setTextPool(levels[level]->getNPC()->getTextPool());
                    NPCInteraction = levels[level]->getNPC()->closeToHero(*hero.get());
                    inputs->setEntityCollision(levels[level]->getNPC());
                }
                else
                    NPCInteraction = false;
                inputs->setHeroEntityAggro(NPCInteraction, entityInteraction); // for buttons interactions
                hud->setAggro(entityInteraction, NPCInteraction);              // to obscure interact button
                hero->movement(false, entityInteraction);                      // for the moment
                hero->update(dt);
                hero->draw(window);
                hero->attack(window);
                hud->draw();
                hud->displayHealthAndEffects(*hero.get());
                hud->displayMoneyCounter(*hero.get());
                shop.draw();
                hero->updateDelay(dt);
                hud->gettingDelayTime(dt);
                levels[level]->setDelayTime(dt);
            }
        }
        window.display();
        dt = clock.getElapsedTime().asSeconds();
        clock.restart();
    }
}

Game::Game(sf::RenderWindow &window) : mainMenu(window, 1), inventory(window), inGameMenu(window, 0), window(window), shop(window)
{
    this->levels.emplace_back(new Room(*hero.get(), {}, Room::Type::StartFirst, window));
    for (int i = 0; i < 3; i++)
        this->levels.emplace_back(new Room(*hero.get(), {}, Room::Type::FirstFloor, window));

    this->levels.emplace_back(new Room(*hero.get(), {}, Room::Type::StartSecond, window));
    for (int i = 0; i < 3; i++)
        this->levels.emplace_back(new Room(*hero.get(), {}, Room::Type::SecondFloor, window));

    this->levels.emplace_back(new Room(*hero.get(), {}, Room::Type::StartThird, window));
    for (int i = 0; i < 2; i++)
        this->levels.emplace_back(new Room(*hero.get(), {}, Room::Type::ThirdFloor, window));
    this->levels.emplace_back(new Room(*hero.get(), {}, Room::Type::LastLevel, window));

    this->levels.emplace_back(new Room(*hero.get(), {}, Room::Type::FinalBoss, window));
}

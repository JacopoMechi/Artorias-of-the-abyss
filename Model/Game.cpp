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
            hero.updateDelayAndInputs(event, dt);
            if (event.type == sf::Event::Closed)
                window.close();
            hud.updateEvent(event, NPCInteraction);
        }
        window.clear(sf::Color::Black);
        //levels[level]->draw();
        room -> draw();//FIXME
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
                        //level++;
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
                        //level--;
                        //std::cout << level << std::endl;
                    }
                }
                hero.movement(hud.getInvIsOpen(), NPCInteraction);
                hero.update(dt);
                hero.draw(window);
                hud.draw();
                hud.displayHealth(hero);
            }
        }
        window.display();
        dt = clock.getElapsedTime().asSeconds();
        clock.restart();
    }
}

Game::Game(sf::RenderWindow &window) : mainMenu(window, 1), inGameMenu(window, 0), window(window), hero(false, {500.0f, 500.0f}, 1, 20, 0, 500.0f), hud(window, hero), room(gameRooms -> makeRoom("startingroom", window, 1))
{
    /*this->levels.emplace_back(new Room({}, Room::Type::StartRoom, window));
    for (int i = 0; i <= 3; i++)
        this->levels.emplace_back(new Room({}, Room::Type::FirstLevel, window));
    for (int i = 0; i <= 3; i++)
        this->levels.emplace_back(new Room({}, Room::Type::SecondLevel, window));
    for (int i = 0; i <= 2; i++)
        this->levels.emplace_back(new Room({}, Room::Type::ThirdLevel, window));
    this->levels.emplace_back(new Room({}, Room::Type::FinalBoss, window));*/
}

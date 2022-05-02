#include "Game.h"
#include "Room.h"
#include "Menu.h"

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
        }
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
                hero.movement(hud.getInvIsOpen(), false);
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

Game::Game(sf::RenderWindow &window) : mainMenu(window, 1), inGameMenu(window, 0), window(window), hero(true, {150.0f, 3.0f}, 1, 20, 0, 100.0f), hud(window, hero)
{
    this->levels.emplace_back(new Room({}, Room::Type::StartRoom, window));
    for (int i = 0; i <= 3; i++)
        this->levels.emplace_back(new Room({}, Room::Type::FirstLevel, window));
    for (int i = 0; i <= 3; i++)
        this->levels.emplace_back(new Room({}, Room::Type::SecondLevel, window));
    for (int i = 0; i <= 3; i++)
        this->levels.emplace_back(new Room({}, Room::Type::ThirdLevel, window));
}

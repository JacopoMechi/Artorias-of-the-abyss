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
            hud.updateEvent(event, false);
            // update inputs event for Hero
            hero.updateDelayAndInputs(event, dt);

            // close window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        levels[level]->draw();
        hero.movement(hud.getInvIsOpen(), false);
        hero.update(dt);
        hero.draw(window);
        hud.draw();
        hud.displayHealth(hero);
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

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

#include "Menu.h"

void Menu::launch()
{
    window.draw(menuSprite);
    // Start Game button check
    if (sf::Mouse::getPosition(window).x <= 1139 && sf::Mouse::getPosition(window).x >= 780 && sf::Mouse::getPosition(window).y <= 454 && sf::Mouse::getPosition(window).y >= 383)
    {
        higlightSprite.setPosition({764.f, 375.f});
        window.draw(higlightSprite);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            shadowSprite.setPosition({764.f, 375.f});
            window.draw(shadowSprite);
            startGame = true;
        }
    }
    // Settings button check
    else if (sf::Mouse::getPosition(window).x <= 1139 && sf::Mouse::getPosition(window).x >= 780 && sf::Mouse::getPosition(window).y <= 574 && sf::Mouse::getPosition(window).y >= 503)
    {
        higlightSprite.setPosition({764.f, 495.f});
        window.draw(higlightSprite);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            shadowSprite.setPosition({764.f, 375.f});
            window.draw(shadowSprite);
            // TODO add action for settings opening
        }
    }
    // Quit to Desktop button check
    else if (sf::Mouse::getPosition(window).x <= 1139 && sf::Mouse::getPosition(window).x >= 780 && sf::Mouse::getPosition(window).y <= 694 && sf::Mouse::getPosition(window).y >= 623)
    {
        higlightSprite.setPosition({764.f, 615.f});
        window.draw(higlightSprite);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            shadowSprite.setPosition({764.f, 375.f});
            window.draw(shadowSprite);
            window.close();
        }
    }
}

void Menu::updateEvent(sf::Event keyInput)
{
    // handling inputs
    if (keyInput.type == sf::Event::KeyPressed && keyInput.key.code == sf::Keyboard::Escape)
    {
        startGame = !startGame;
    }
}

bool Menu::getStartGame()
{
    return startGame;
}

Menu::Menu(sf::RenderWindow &window, bool mainMenu, const std::string &buttonEffectsFilePath) : window(window), mainMenu(mainMenu)
{
    if (mainMenu)
    {
        if (!menuTexture.loadFromFile("../Textures/mainMenu.png"))
            std::cout << "Error while setting menu texture" << std::endl;
        menuSprite.setTexture(this->menuTexture);
        menuSprite.setTextureRect(sf::IntRect(0, 0, 1920, 1080));
    }
    else
    {
        if (!menuTexture.loadFromFile("../Textures/Menu.png"))
            std::cout << "Error while setting menu texture" << std::endl;
        menuSprite.setTexture(this->menuTexture);
        menuSprite.setTextureRect(sf::IntRect(0, 0, 1920, 1080));
    }

    if (!shadowTexture.loadFromFile(buttonEffectsFilePath))
        std::cout << "Error while setting menu shadow texture" << std::endl;
    shadowSprite.setTexture(this->shadowTexture);
    shadowSprite.setTextureRect(sf::IntRect(8, 825, 390, 92));

    if (!higlightTexture.loadFromFile(buttonEffectsFilePath))
        std::cout << "Error while setting menu highlight texture" << std::endl;
    higlightSprite.setTexture(this->higlightTexture);
    higlightSprite.setTextureRect(sf::IntRect(401, 827, 390, 92));
}

Menu::~Menu() {}
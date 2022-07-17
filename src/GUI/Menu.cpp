#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

#include "Menu.h"

void Menu::launch()
{
    window.draw(menuSprite);
    window.draw(knightText);
    window.draw(mageText);
    if (mainMenu)
    {
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
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(window).x <= 957 && sf::Mouse::getPosition(window).x >= 760 && sf::Mouse::getPosition(window).y <= 584 && sf::Mouse::getPosition(window).y >= 495)
        {
            knightText.setColor(sf::Color::Red);
            mageText.setColor(sf::Color::White);
            isKnight = true;
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(window).x <= 1155 && sf::Mouse::getPosition(window).x >= 959 && sf::Mouse::getPosition(window).y <= 584 && sf::Mouse::getPosition(window).y >= 495)
        {
            knightText.setColor(sf::Color::White);
            mageText.setColor(sf::Color::Red);
            isKnight = false;
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
    else
    {
        // Start Game button check
        if (sf::Mouse::getPosition(window).x <= 1161 && sf::Mouse::getPosition(window).x >= 771 && sf::Mouse::getPosition(window).y <= 543 && sf::Mouse::getPosition(window).y >= 453)
        {
            higlightSprite.setPosition({771.f, 453.f});
            window.draw(higlightSprite);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                shadowSprite.setPosition({771.f, 453.f});
                window.draw(shadowSprite);
                startGame = true;
            }
        }
        // Quit to Desktop button check
        else if (sf::Mouse::getPosition(window).x <= 1161 && sf::Mouse::getPosition(window).x >= 771 && sf::Mouse::getPosition(window).y <= 657 && sf::Mouse::getPosition(window).y >= 569)
        {
            higlightSprite.setPosition({771.f, 570.f});
            window.draw(higlightSprite);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                shadowSprite.setPosition({771.f, 570.f});
                window.draw(shadowSprite);
                window.close();
            }
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

void Menu::setStartGame(bool state)
{
    startGame = state;
}

bool Menu::getIsKnight()
{
    return isKnight;
}

Menu::Menu(sf::RenderWindow &window, bool mainMenu, const std::string &buttonEffectsFilePath) : window(window), mainMenu(mainMenu)
{
    if (mainMenu)
    {
        if (!menuTexture.loadFromFile("Textures/mainMenu.png"))
            std::cout << "Error while setting menu texture" << std::endl;
        menuSprite.setTexture(this->menuTexture);
        menuSprite.setTextureRect(sf::IntRect(0, 0, 1920, 1080));
        knightText.setFont(font);
        mageText.setFont(font);
        knightText.setCharacterSize(30);
        mageText.setCharacterSize(30);
        knightText.setPosition(805.f, 543.f);
        mageText.setPosition(1015.f, 543.f);
        knightText.setString("Knight");
        mageText.setString("Mage");
        knightText.setColor(sf::Color::Red);
    }
    else
    {
        if (!menuTexture.loadFromFile("Textures/Menu.png"))
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

    if (!font.loadFromFile("Fonts/pixelFont.ttf"))
        std::cout << "Error on loading font for the item" << std::endl;
}

Menu::~Menu() {}
#include "Menu.h"

void Menu::launch()
{
    window.draw(menuSprite);
    window.draw(knightText);
    window.draw(mageText);
    if (mainMenu)
    {
        // Start Game button check
        if (sf::Mouse::getPosition(window).x <= rightStartBound && sf::Mouse::getPosition(window).x >= leftStartBound && sf::Mouse::getPosition(window).y <= topStartBound && sf::Mouse::getPosition(window).y >= bottomStartBound)
        {
            higlightSprite.setPosition({colorStartX, colorStartY});
            window.draw(higlightSprite);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                shadowSprite.setPosition({colorStartX, colorStartY});
                window.draw(shadowSprite);
                startGame = true;
            }
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(window).x <= rightKnightChooseBound && sf::Mouse::getPosition(window).x >= leftKnightChooseBound && sf::Mouse::getPosition(window).y <= topHeroChooseBound && sf::Mouse::getPosition(window).y >= bottomHeroChooseBound)
        {
            knightText.setColor(sf::Color::Red);
            mageText.setColor(sf::Color::White);
            isKnight = true;
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(window).x <= rightMageChooseBound && sf::Mouse::getPosition(window).x >= leftMageChooseBound && sf::Mouse::getPosition(window).y <= topHeroChooseBound && sf::Mouse::getPosition(window).y >= bottomHeroChooseBound)
        {
            knightText.setColor(sf::Color::White);
            mageText.setColor(sf::Color::Red);
            isKnight = false;
        }
        // Quit to Desktop button check
        else if (sf::Mouse::getPosition(window).x <= rightQuitBound && sf::Mouse::getPosition(window).x >= leftQuitBound && sf::Mouse::getPosition(window).y <= topQuitBound && sf::Mouse::getPosition(window).y >= bottomQuitBound)
        {
            higlightSprite.setPosition({coloredQuitX, highlightQuitY});
            window.draw(higlightSprite);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                shadowSprite.setPosition({coloredQuitX, obscureQuitY});
                window.draw(shadowSprite);
                window.close();
            }
        }
    }
    else
    {
        // Start Game button check
        if (sf::Mouse::getPosition(window).x <= rightIGMenuBound && sf::Mouse::getPosition(window).x >= leftIGMenuBound && sf::Mouse::getPosition(window).y <= topResumeBound && sf::Mouse::getPosition(window).y >= bottomResumeBound)
        {
            higlightSprite.setPosition({resumeColorPosX, resumeColorPosY});
            window.draw(higlightSprite);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                shadowSprite.setPosition({resumeColorPosX, resumeColorPosY});
                window.draw(shadowSprite);
                startGame = true;
            }
        }
        // Quit to Desktop button check
        else if (sf::Mouse::getPosition(window).x <= rightIGMenuBound && sf::Mouse::getPosition(window).x >= leftIGMenuBound && sf::Mouse::getPosition(window).y <= topIGQuitBound && sf::Mouse::getPosition(window).y >= bottomIGQuitBound)
        {
            higlightSprite.setPosition({igQuitColorPosX, igQuitColorPosY});
            window.draw(higlightSprite);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                shadowSprite.setPosition({igQuitColorPosX, igQuitColorPosY});
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
        menuSprite.setTextureRect(sf::IntRect(menuX, menuY, menuWidth, menuHeight));
        knightText.setFont(font);
        mageText.setFont(font);
        knightText.setCharacterSize(30);
        mageText.setCharacterSize(30);
        knightText.setPosition(knightTextPosX, knightTextPosY);
        mageText.setPosition(mageTextPosX, mageTextPosY);
        knightText.setString("Knight");
        mageText.setString("Mage");
        knightText.setColor(sf::Color::Red);
    }
    else
    {
        if (!menuTexture.loadFromFile("Textures/Menu.png"))
            std::cout << "Error while setting menu texture" << std::endl;
        menuSprite.setTexture(this->menuTexture);
        menuSprite.setTextureRect(sf::IntRect(menuX, menuY, menuWidth, menuHeight));
    }

    if (!shadowTexture.loadFromFile(buttonEffectsFilePath))
        std::cout << "Error while setting menu shadow texture" << std::endl;
    shadowSprite.setTexture(this->shadowTexture);
    shadowSprite.setTextureRect(sf::IntRect(shadowX, shadowY, shadowWidth, shadowHeight));

    if (!higlightTexture.loadFromFile(buttonEffectsFilePath))
        std::cout << "Error while setting menu highlight texture" << std::endl;
    higlightSprite.setTexture(this->higlightTexture);
    higlightSprite.setTextureRect(sf::IntRect(highlightX, highlightY, highlightWidth, highlightHeight));

    if (!font.loadFromFile("Fonts/pixelFont.ttf"))
        std::cout << "Error on loading font for the item" << std::endl;
}

Menu::~Menu() {}
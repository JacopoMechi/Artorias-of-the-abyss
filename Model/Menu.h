#ifndef _MENU_H
#define _MENU_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class Menu
{
public:
    void launch();

    bool getMenuIsOpen();

    bool getStartGame();

    void updateEvent(sf::Event keyInput);

    Menu(sf::RenderWindow &window, bool mainMenu, const std::string &buttonEffectsFilePath = "../Textures/Textures.png");
    ~Menu();

protected:
    bool menuIsOpen;
    sf::RenderWindow &window;
    sf::Texture menuTexture;
    sf::Sprite menuSprite;
    sf::Texture shadowTexture;
    sf::Sprite shadowSprite;
    sf::Texture higlightTexture;
    sf::Sprite higlightSprite;
    bool mainMenu;
    bool startGame = false;
};
#endif

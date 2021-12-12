#ifndef _MENU_H
#define _MENU_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class Menu
{
public:
    void launch(sf::RenderWindow &window);

    bool getStartGame();

    Menu(const std::string &menuFilePath = "../Textures/Menu.png", const std::string &buttonEffectsFilePath = "../Textures/Textures.png");
    ~Menu();

protected:
    sf::Texture menuTexture;
    sf::Sprite menuSprite;
    sf::Texture shadowTexture;
    sf::Sprite shadowSprite;
    sf::Texture higlightTexture;
    sf::Sprite higlightSprite;

    bool startGame = false;
};
#endif

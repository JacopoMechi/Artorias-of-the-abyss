#ifndef _MAPELEMENT_H
#define _MAPELEMENT_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include <vector>

class MapElement
{
public:
    void draw(sf::RenderWindow &window);

    sf::Vector2f getPos();
    void setPos(sf::Vector2f &newPos);

    MapElement(sf::Vector2f &position, std::vector<sf::IntRect> &spriteFrames,
               const std::string &mapElementFilePath = "../Textures/Textures.png");
    ~MapElement();

protected:
    sf::Texture mapElementTexture;
    sf::Sprite mapElementSprite;
    std::vector<sf::IntRect> spriteFrames;
    int frame = 0;
};
#endif
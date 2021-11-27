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

    MapElement(std::vector<int> &spriteDimension, sf::Vector2f &position, std::string &mapElementFilePath);
    ~MapElement();

protected:
    sf::Texture mapElementTexture;
    sf::Sprite mapElementSprite;
};
#endif
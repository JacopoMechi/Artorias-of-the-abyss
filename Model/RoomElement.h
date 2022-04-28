#ifndef _ROOMELEMENT_H
#define _ROOMELEMENT_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include <vector>

class RoomElement
{
public:
    void draw(sf::RenderWindow &window);

    sf::Vector2f getPos();
    void setPos(sf::Vector2f &newPos);

    RoomElement(sf::Vector2f &position, std::vector<sf::IntRect> &spriteFrames,
                const std::string &roomElementFilePath = "../Textures/Textures.png");
    RoomElement(const std::string &roomElementFilePath = "../Textures/Textures.png");
    ~RoomElement();

protected:
    sf::Texture roomElementTexture;
    sf::Sprite roomElementSprite;
    std::vector<sf::IntRect> spriteFrames;
    int frame = 0;
};
#endif
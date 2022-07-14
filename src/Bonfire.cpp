#include <SFML/System.hpp>
#include <vector>

#include "Bonfire.h"

void Bonfire::resetHp() // TODO to be implemented
{
}

bool Bonfire::closeToHero(sf::Vector2f heroPos)
{
    if (std::abs(sqrt(((heroPos.x - roomElementSprite.getPosition().x) * (heroPos.x - roomElementSprite.getPosition().x)) +
                      ((heroPos.y - roomElementSprite.getPosition().y) * (heroPos.y - roomElementSprite.getPosition().y)))) < 190)
        return true;
    else
        return false;
}

Bonfire::Bonfire(sf::RenderWindow &window, const sf::Vector2f &position,
                 const std::vector<sf::IntRect> &spriteFrames,
                 const std::string &roomElementFilePath) : RoomElement(window, position, spriteFrames, roomElementFilePath)
{
    roomElementSprite.setScale(0.7f, 0.7f);
}
Bonfire::~Bonfire() {}
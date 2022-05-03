#include <SFML/System.hpp>
#include <vector>

#include "Bonfire.h"

void Bonfire::resetHp() // TODO to be implemented
{
}

void Bonfire::setSpawnPoint() // TODO to be implemented
{
}

void Bonfire::respawnEnemies() // TODO to be implemented
{
}

Bonfire::Bonfire(sf::RenderWindow &window, const sf::Vector2f &position,
                 const std::vector<sf::IntRect> &spriteFrames,
                 const std::string &roomElementFilePath) : RoomElement(window, position, spriteFrames, roomElementFilePath) {}
Bonfire::~Bonfire() {}
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

Bonfire::Bonfire(sf::Vector2f position,
                 std::vector<sf::IntRect> spriteFrames,
                 const std::string roomElementFilePath) : RoomElement(position, spriteFrames, roomElementFilePath) {}
Bonfire::~Bonfire() {}
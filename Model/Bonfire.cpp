#include "Bonfire.h"
#include <SFML/System.hpp>
#include <string>
#include <vector>

void Bonfire::resetHp() //TODO to be implemented
{
}

void Bonfire::setSpawnPoint() //TODO to be implemented
{
}

void Bonfire::respawnEnemies() //TODO to be implemented
{
}

Bonfire::Bonfire(std::vector<int> &spriteDimension, sf::Vector2f &position, std::string &mapElementFilePath) : MapElement(spriteDimension, position, mapElementFilePath) {}
Bonfire::~Bonfire() {}
#include "Map.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

void Map::spawnEntities(const std::vector<MapElement> &mapElementsVector)
{
    //for (int i = 0; i < mapElementsVector.size(); i++)
    //TODO add function to spawn elements
}
void Map::drawMap(sf::RenderWindow &window)
{
    mapSprite.setTextureRect(sf::IntRect(0, 0, 1920, 1080));
    window.draw(mapSprite);
}

Map::Map(const std::vector<MapElement> &mapElementsVector, std::string &mapFilePath) : mapFilePath(mapFilePath)
{
    if (!mapTexture.loadFromFile(mapFilePath))
    {
        std::cout << "Error while displaying map" << std::endl;
    }
    mapSprite.setTexture(this->mapTexture);

    for (int i = 0; i < mapElementsVector.size(); i++)
    {
        this->mapElementsVector[i] = mapElementsVector[i];
    }
}
Map::~Map() {}

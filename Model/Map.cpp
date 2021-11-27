#include "Map.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

void Map::spawnEntity(const MapElement &mapElement) //TODO currently not working
{
    mapElementsVector.push_back(mapElement);
}
void Map::draw(sf::RenderWindow &window)
{
    mapSprite.setTextureRect(sf::IntRect(0, 0, 1920, 1080));
    window.draw(mapSprite);
    for (auto &mapElement : mapElementsVector)
        mapElement.draw(window);
}

Map::Map(const std::vector<MapElement> &mapElementsVector, const std::string &mapFilePath)
{
    if (!mapTexture.loadFromFile(mapFilePath))
        std::cout << "Error while setting map texture" << std::endl;

    mapSprite.setTexture(this->mapTexture);

    for (int i = 0; i < mapElementsVector.size(); i++)
        this->mapElementsVector.push_back(mapElementsVector[i]);
}
Map::~Map() {}

#ifndef _MAP_H
#define _MAP_H
#include "MapElement.h"
#include <vector>
#include <SFML/Graphics.hpp>

class Map
{
public:
    Map(const std::vector<MapElement> &mapElementsVector, const std::string &mapFilePath);
    ~Map();
    void spawnEntity(const MapElement &mapElement);
    void draw(sf::RenderWindow &window);

private:
    std::vector<MapElement> mapElementsVector;
    sf::Texture mapTexture;
    sf::Sprite mapSprite;
};
#endif
#ifndef _MAP_H
#define _MAP_H
#include "MapElement.h"
#include <vector>
#include <SFML/Graphics.hpp>

class Map
{
public:
    Map(const std::vector<MapElement> &mapElementsVector, std::string &mapFilePath);
    ~Map();
    void spawnEntities(const std::vector<MapElement> &mapElementsVector);
    void drawMap(sf::RenderWindow &window);

protected:
    std::vector<MapElement> mapElementsVector;
    sf::Texture mapTexture;
    sf::Sprite mapSprite;
    std::string mapFilePath;
};
#endif
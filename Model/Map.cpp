#include "Map.h"
#include <iostream>

void Map::spawnEntities(const std::vector<MapElements> &mapElementsVector)
{
    for (int i = 0; i < mapElementsVector.size(); i++)
    //TODO add function to spawn elements
}

Map::Map(const std::vector<MapElements> &mapElementsVector, int dimX, int dimY)
{
    this->dimX = dimX;
    this->dimY = dimY;
    for (int i = 0; i < mapElementsVector.size(); i++)
    {
        this->mapElementsVector[i] = mapElementsVector[i];
    }
}
Map::~Map() {}

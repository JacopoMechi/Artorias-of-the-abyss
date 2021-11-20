#include "Map.h"
#include <iostream>

void Map::spawnEntities(const std::vector<MapElement> &mapElementsVector)
{
    for (int i = 0; i < mapElementsVector.size(); i++)
    //TODO add function to spawn elements
}

Map::Map(const std::vector<MapElement> &mapElementsVector, int dimX, int dimY) : dimX(dimX), dimY(dimY)
{
    for (int i = 0; i < mapElementsVector.size(); i++)
    {
        this->mapElementsVector[i] = mapElementsVector[i];
    }
}
Map::~Map() {}

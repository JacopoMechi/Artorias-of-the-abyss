#ifndef _MAP_H
#define _MAP_H
#include "MapElements.h"
#include <vector>

class Map
{
public:
    void spawnEntities(const std::vector<MapElements> &mapElementsVector);

protected:
    Map(const std::vector<MapElements> &mapElementsVector, int dimX, int dimY);
    ~Map();
    int dimX;
    int dimY;
    std::vector<MapElements> mapElementsVector;
};

#endif //_MAP_H
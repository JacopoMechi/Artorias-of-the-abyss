#ifndef _MAP_H
#define _MAP_H
#include "MapElement.h"
#include <vector>

class Map
{
public:
    void spawnEntities(const std::vector<MapElement> &mapElementsVector);

protected:
    Map(const std::vector<MapElement> &mapElementsVector, int dimX, int dimY);
    ~Map();
    int dimX; //TODO I'm not sure that dimX and dimY are really useful
    int dimY;
    std::vector<MapElement> mapElementsVector;
};

#endif //_MAP_H
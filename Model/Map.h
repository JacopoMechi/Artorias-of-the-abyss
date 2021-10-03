/**
 * Project Untitled
 */


#ifndef _MAP_H
#define _MAP_H

class Map {
public: 
    
void spawnEntities();
    
void spawnBonfire();
protected: 
    int[2] dim;
    int mapHeight;
    MapElements& mapElementList[];
};

#endif //_MAP_H
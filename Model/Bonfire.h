/**
 * Project Untitled
 */


#ifndef _BONFIRE_H
#define _BONFIRE_H

#include "MapElements.h"


class Bonfire: public MapElements {
public: 
    
void resetHp();
    
void setSpawnPoint();
    
void respawnEnemies();
};

#endif //_BONFIRE_H
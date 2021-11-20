#ifndef _BONFIRE_H
#define _BONFIRE_H

#include "MapElement.h"

class Bonfire : public MapElement
{
public:
    void resetHp();

    void setSpawnPoint();

    void respawnEnemies();

protected:
    Bonfire(float posX, float posY);

    ~Bonfire();
};

#endif //_BONFIRE_H
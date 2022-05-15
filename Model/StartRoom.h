#ifndef _STARTROOM_H
#define _STARTROOM_H

#include "Room.h"

class StartRoom: public Room{
public:
    StartRoom(int level, sf::RenderWindow &window);
};

#endif
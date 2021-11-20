#ifndef _GATE_H
#define _GATE_H

#include "MapElement.h"

class Gate : public MapElement
{
public:
    bool getisOpen();

    void setisOpen(bool isOpen);

protected:
    Gate(float posX, float posY, bool isOpen = false);

    ~Gate();

    bool isOpen;
};

#endif //_GATE_H
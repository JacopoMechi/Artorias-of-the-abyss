#ifndef _GATE_H
#define _GATE_H

#include <SFML/System.hpp>
#include <string>
#include <vector>

#include "MapElement.h"

class Gate : public MapElement
{
public:
    bool getisOpen();

    void setisOpen(bool isOpen);

    Gate(std::vector<int> spriteDimension, sf::Vector2f position, const std::string mapElementFilePath, bool isOpen = false);

    ~Gate();

protected:
    bool isOpen;
};

#endif //_GATE_H
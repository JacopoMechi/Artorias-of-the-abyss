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

    Gate(sf::Vector2f position, std::vector<sf::IntRect> spriteFrames = {{0, 0, 113, 196}},
         const std::string mapElementFilePath = "../Textures/Textures.png", bool isOpen = false);

    ~Gate();

protected:
    bool isOpen;
};

#endif //_GATE_H
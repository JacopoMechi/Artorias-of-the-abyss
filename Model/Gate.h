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

    Gate(sf::Vector2f position, bool isMirrored = true, bool isOpen = false, std::vector<sf::IntRect> spriteFrames = {{260, 308, -120, 195}}, // 140,308,120,195
         const std::string mapElementFilePath = "../Textures/Textures.png");

    ~Gate();

protected:
    bool isOpen;
    bool isMirrored;

private:
    std::vector<sf::IntRect> mirroredSpriteFrames = {{260, 308, -120, 195}};
    std::vector<sf::IntRect> notMirroredSpriteFrames = {{140, 308, 120, 195}};
};

#endif //_GATE_H
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

    Gate(bool isMirrored = false, bool isOpen = false);

    ~Gate();

protected:
    bool isOpen;
    bool isMirrored;

private:
    std::vector<sf::IntRect> mirroredSpriteFrames = {{260, 308, -120, 195}};
    std::vector<sf::IntRect> notMirroredSpriteFrames = {{140, 308, 120, 195}};
    sf::Vector2f notMirroredPosition = {158.0f, 425.0f};
    sf::Vector2f mirroredPosition = {1626.0f, 425.0f};
};

#endif //_GATE_H
#ifndef _GATE_H
#define _GATE_H

#include <SFML/System.hpp>
#include <string>
#include <vector>

#include "Rooms/RoomElement.h"

class Gate : public RoomElement
{
public:
    static const sf::Vector2f leftPosition;
    static const sf::Vector2f rightPosition;

    bool getisOpen() const;

    void setisOpen(bool isOpen);

    Gate(sf::RenderWindow &window, bool isMirrored = false, bool isOpen = false);

    ~Gate();

protected:
    bool isOpen;
    bool isMirrored;

private:
    std::vector<sf::IntRect> SpriteFrames = {{doorX, doorY, doorWidth, doorHeight}};
};

#endif //_GATE_H
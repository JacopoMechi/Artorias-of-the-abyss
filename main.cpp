#include <SFML/Graphics.hpp>
#include <string>

#include "GameCharacter.h"
#include "Gate.h"
#include "Map.h"

#define MAPPATH "../Textures/Lvl1.png"
#define TEXTURESPATH "../Textures/Textures.png"

int main()
{
    // defining sprite options
    std::vector<int> gateDimension = {0, 0, 123, 194};
    std::vector<int> mirroredGateDimension = {123, 0, -123, 194};
    sf::Vector2f leftGatePosition(150.f, 450.f);
    sf ::Vector2f rightGatePosition(1630.f, 450.f);
    // initializing objects
    Gate leftGate(gateDimension, leftGatePosition, TEXTURESPATH, false);
    Gate rightGate(mirroredGateDimension, rightGatePosition, TEXTURESPATH, false);
    rightGate.setisOpen(true);
    std::vector<MapElement> porte = {leftGate, rightGate};
    Map map(porte, MAPPATH);

    // create window
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Hallway of the abyss");

    // starting the game loop
    while (window.isOpen())
    {
        // process event
        sf::Event event;
        while (window.pollEvent(event))
        {
            // close window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear screen
        window.clear(sf::Color::Black);

        // draw map
        map.draw(window);

        // update the window
        window.display();
    }
    return EXIT_SUCCESS;
}
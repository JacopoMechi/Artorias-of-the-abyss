#include <SFML/Graphics.hpp>
#include <string>

#include "GameCharacter.h"
#include "Map.h"

#define MAPPATH "../Textures/Lvl1.png"

int main()
{
    // initializin objects
    Map map({}, MAPPATH);

    // create window
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Artoryas of the abyss");

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
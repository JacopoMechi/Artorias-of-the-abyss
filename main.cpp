#include <SFML/Graphics.hpp>
#include "Model/Map.h"
#include <string>

int main()
{
    bool vSync = true;
    int fpsLimit = 60;
    std::string mapFilePath = "../1098024.png";

    Map map({}, mapFilePath);

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Artoryas of the abyss", sf::Style::Default);
    window.setVerticalSyncEnabled(vSync);
    if (vSync == false)
    {
        window.setFramerateLimit(fpsLimit);
    }
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);

        map.drawMap(window);

        window.display();
    }

    return 0;
}
#include <SFML/Graphics.hpp>
#include <string>

//#include "Game.h"

int main()
{
    // create window
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Hallway of the abyss");
    window.setFramerateLimit(60);
    // disable multiple input from a single key
    window.setKeyRepeatEnabled(false);

    //Game game(window);
    //game.gameLoop();
}
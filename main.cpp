#include <SFML/Graphics.hpp>
#include <string>

#include "Bonfire.h"
#include "GameCharacter.h"
#include "Gate.h"
#include "HUD.h"
#include "MapElement.h"
#include "Map.h"
#include "Menu.h"

#define MAPPATH "../Textures/Lvl1.png"
#define TEXTURESPATH "../Textures/Textures.png"

int main()
{
    // defining sprite options

    // initializing objects
    // gate

    // map
    Map map({}, MAPPATH);

    // creating event
    sf::Event event;

    // create window
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Hallway of the abyss");
    window.setFramerateLimit(60);

    // disable multiple input from a single key
    window.setKeyRepeatEnabled(false);

    // menu
    Menu mainMenu(window, 1);
    Menu inGameMenu(window, 0);

    // hud
    HUD hud(window);
    // gamecharacter
    GameCharacter test(100, 20, 0, 100.0f, {150.0f, 3.0f});

    // creating clock for dt
    sf::Clock clock;

    // creating dt
    float dt = 0.0f;

    // starting the game loop
    while (window.isOpen())
    {

        // process event
        while (window.pollEvent(event))
        {
            // update inputs event in HUD
            hud.updateEvent(event);
            inGameMenu.updateEvent(event);

            // close window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear screen
        window.clear(sf::Color::Black);

        // draw map
        map.draw(window);

        if (!mainMenu.getStartGame())
            mainMenu.launch();
        else
        {
            // handle player input
            test.movement(hud.getInvIsOpen(), inGameMenu.getMenuIsOpen());

            // update character model
            test.update(dt);

            // draw the sprite
            test.draw(window);

            // hud handling
            if (hud.getInvIsOpen())
            {
                hud.drawInventory();
            }
            hud.draw();
            hud.displayHealth(test);

            // in game menu handling
            if (inGameMenu.getMenuIsOpen())
            {
                inGameMenu.launch();
            }
        }

        // update the window
        window.display();

        dt = clock.getElapsedTime().asSeconds();
        clock.restart();
        // TODO can be useful later:hud.updateDelayTime(dt);
    }
    return EXIT_SUCCESS;
}
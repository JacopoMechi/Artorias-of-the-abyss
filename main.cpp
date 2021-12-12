#include <SFML/Graphics.hpp>
#include <string>
#include <chrono>

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
    // hud
    HUD hud(false, true, 0);
    // menu
    Menu menu;
    // gamecharacter
    GameCharacter test(100, 20, 0, 100.0f, {150.0f, 3.0f});

    // create window
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Hallway of the abyss");
    window.setFramerateLimit(60);

    // timepoint for delta time measurement
    auto tp = std::chrono::steady_clock::now();

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

        // get dt
        float dt;
        {
            const auto new_tp = std::chrono::steady_clock::now();
            dt = std::chrono::duration<float>(new_tp - tp).count();
            tp = new_tp;
        }

        // clear screen
        window.clear(sf::Color::Black);

        if (!menu.getStartGame())
            menu.launch(window);
        else
        {
            // draw map
            map.draw(window);
            // handle player input
            test.movement(hud.getInvIsOpen());
            hud.openCloseInv();

            // update character model
            test.update(dt);

            // draw the sprite
            test.draw(window);
            if (hud.getInvIsOpen())
            {
                hud.drawInventory(window);
            }
            hud.draw(window);
            hud.displayHealth(test, window);
        }
        // update the window
        window.display();
    }
    return EXIT_SUCCESS;
}
#include <SFML/Graphics.hpp>
#include <string>

#include "Bonfire.h"
#include "GameCharacter.h"
#include "Hero.h"
#include "Gate.h"
#include "HUD.h"
#include "MapElement.h"
#include "Map.h"
#include "Menu.h"
#include "NPC.h"

#define MAPPATH "../Textures/Lvl1.png"
#define TEXTURESPATH "../Textures/Textures.png"

int main()
{
    // defining sprite options

    // initializing objects
    // gate

    // map
    Map map({}, MAPPATH);

    //menu
    Menu menu;

    //creating event
    sf::Event event;

    // create window
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Hallway of the abyss");
    window.setFramerateLimit(60);

    //disable multiple input from a single key
    window.setKeyRepeatEnabled(false);

    //hud
    HUD hud(window);
    //gamecharacter
    Hero test(true, {150.0f,3.0f}, 100, 20, 0, 100.0f);
    //npc
    NPC test1(window, 2, {300.0f, 3.0f});

    //creating clock for dt
    sf::Clock clock;

    //creating dt
    float dt = 0.0f;

    // starting the game loop
    while (window.isOpen())
    {    

        // process event
        while (window.pollEvent(event))
        {
            //update inputs event in HUD
            hud.updateEvent(event);

            //update inputs event for Hero
            test.updateDelayAndInputs(event, dt);

            //handling the inputs for the npc
            test1.updateInputs(event);

            // close window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear screen
        window.clear(sf::Color::Black);

        if (!menu.getStartGame())
            menu.launch(window);
        else
        {

            // draw map
            map.draw(window);

            //handle player input
            test.movement(hud.getInvIsOpen());//TODO implement a method stop the caracter moving when interacting

            // update character model
            test.update(dt);
            
            // draw npc model
            test1.draw(window);

            // player interact with npc
            test1.interact(test);

            //draw the sprite
            test.draw(window);
            if (hud.getInvIsOpen()){
                hud.drawInventory();//FIXME adjust tracker for items
            }
            hud.draw(); 
            hud.displayHealth(test);
        }

        // update the window
        window.display();

        dt = clock.getElapsedTime().asSeconds();
        clock.restart();
    }
    return EXIT_SUCCESS;
}
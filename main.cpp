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
    Gate nextRoomGate(true);
    Gate previewsRoomGate;

    // map
    Map map({nextRoomGate, previewsRoomGate}, MAPPATH);

    // creating event
    sf::Event event;

    // create window
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Hallway of the abyss");
    window.setFramerateLimit(60);

    // disable multiple input from a single key
    window.setKeyRepeatEnabled(false);

    // initialising
    //  menu
    Menu mainMenu(window, 1);
    Menu inGameMenu(window, 0);
    // gamecharacter
    Hero test(true, {150.0f, 3.0f}, 1, 20, 0, 100.0f); // 100
    // hud
    HUD hud(window, test);
    // npc
    NPC test1(window, 3, {300.0f, 3.0f});

    // creating clock for dt
    sf::Clock clock;

    // creating dt
    float dt = 0.0f;

    // to block the character when is interacting with an npc
    bool NPCInteraction = false;

    // starting the game loop
    while (window.isOpen())
    {

        // process event
        while (window.pollEvent(event))
        {
            // update inputs event in HUD
            hud.updateEvent(event, NPCInteraction);

            // update inputs event for Hero
            test.updateDelayAndInputs(event, dt);

            // handling the inputs for the npc
            test1.updateInputs(event);

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

            // draw map
            map.draw(window);

            // setting bool value of interaction
            NPCInteraction = test1.getIsInteraction();

            // handle player input
            test.movement(hud.getInvIsOpen(), NPCInteraction);

            // update character model
            test.update(dt);

            // draw npc model
            test1.draw(window);

            // player interact with npc
            test1.interact(test);

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
    }
    return EXIT_SUCCESS;
}
#include <SFML/Graphics.hpp>
#include <string>

#include "GameCharacter.h"
#include "Gate.h"
#include "Map.h"
#include "HUD.h"

#define MAPPATH "../Textures/Lvl1.png"
#define TEXTURESPATH "../Textures/Textures.png"

int main()
{
    // defining sprite options
    
    // initializing objects
    //gate

    //map
    Map map({}, MAPPATH);

    //creating event
    sf::Event event;

    // create window
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Hallway of the abyss");
    window.setFramerateLimit(60);

    //disable multiple input from a single key
    window.setKeyRepeatEnabled(false);

    //hud
    HUD hud(false, true, 0, window);
    //gamecharacter
    GameCharacter test(100, 20, 0, 100.0f, {150.0f,3.0f});

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

            // close window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear screen
        window.clear(sf::Color::Black);

        // draw map
        map.draw(window);

        //handle player input
        test.movement(hud.getInvIsOpen());
        hud.openCloseInv();

        //update character model
        test.update(dt);

        //draw the sprite
        test.draw(window);
        if (hud.getInvIsOpen()){
            hud.drawInventory();
        }
        hud.draw(window); 
        hud.displayHealth(test, window);

        // update the window
        window.display();

        dt = clock.getElapsedTime().asSeconds();
        clock.restart();
        //TODO can be useful later:hud.updateDelayTime(dt);
    }
    return EXIT_SUCCESS;
}
#ifndef _NPC_H
#define _NPC_H

#include <SFML/Graphics.hpp>

#include "GameCharacter.h"
#include "Item.h"
#include "Hero.h"
#include "HomewardBone.h"
#include "Pendant.h"
#include "GreenBlossom.h"


class NPC: public GameCharacter {

public:

    NPC(sf::RenderWindow &window, int type, const sf::Vector2f& pos, int hp = 100, int armor = 0, int cash = 0, float movementSpeed = 0);
    ~NPC();

    void receiveDamage() = delete;//to be unkillable

    void sellItems(Hero &hero);

    //handling inputs
    void updateInputs(sf::Event keyInput);

private:

    //getting window from main
    sf::RenderWindow &window;

    //loading hud textures
    sf::Texture hudTexture;

    //shop sprite declaration
    sf::Sprite shopSprite;

    //interaction sprite declaration
    sf::Sprite interactionBoxSprite;

    //text for "press Q to interact" box 
    sf::Text interactText;
    sf::Font interactFont;

    //switch for open shop
    bool openShop = false;

    //switch for interaction menu
    bool aggro = false;

    //for tracking character type
    int type;

    //items selling list
    Item* merch[3] = {new GreenBlossom(), new HomewardBone(), new Pendant()};
};

#endif
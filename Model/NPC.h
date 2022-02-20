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

    void interact(Hero &hero);

    //handling inputs
    void updateInputs(sf::Event keyInput);

    //drawing text for all menus 
    void drawText(std::string text, sf::Vector2f textPos);

    //drawing interaction box
    void drawInteractBox(sf::Vector2f pos);

    //drawing shop box
    void drawShop(Item item1, Item item2);
    void drawShop(Item item1);

    //TODO for later
    bool getIsInteraction();

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
    bool isInteraction = false;

    //switch for interaction menu
    bool aggro = false;

    //switch for shop menu
    bool isShop = false;

    //switch for talking
    bool isTalking = false;

    //for tracking character type
    int type;

    //items selling list
    Item merch[3] = {GreenBlossom(), HomewardBone(), Pendant()};//TODO correct array declaration in other classes
};

#endif
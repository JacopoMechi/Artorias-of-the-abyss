#ifndef _CHARACTERINPUTS_H
#define _CHARACTERINPUTS_H

#include "Inventory.h"
#include "HUD.h"
#include "Hero.h"
#include "Shop.h"

class CharacterInputs{
public:
    //getting Inventory and hud from main game
    CharacterInputs(Inventory &inventory, HUD &hud, Hero &hero, Shop &shop);

    void updateInputs(sf::Event keyInputs);

    void setHeroNPCAggro(bool status);

    //setting boolean value to stop the character moving when interactiong
    void setInteraction(bool interaction);

    //getting NPC type for shop
    void setNPCType(int type);//TODO for the moment

private:
    //all the stuff needed to handle inputs
    Inventory &inventory;
    HUD &hud;
    Hero &hero;
    Shop &shop;
    int NPCType = -1;
    bool isInRange = false;
    bool isInteraction = false;
};

#endif
#ifndef _CHARACTERINPUTS_H
#define _CHARACTERINPUTS_H

#include "Inventory.h"
#include "HUD.h"
#include "Hero.h"

class CharacterInputs{
public:
    //getting Inventory and hud from main game
    CharacterInputs(Inventory &inventory, HUD &hud, Hero &hero);

    void updateInputs(sf::Event keyInputs);

    void setHeroNPCAggro(bool status);

private:
    //all the stuff needed to handle inputs
    Inventory &inventory;
    HUD &hud;
    Hero &hero;
    bool isInRange = false;
};

#endif
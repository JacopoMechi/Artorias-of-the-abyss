#ifndef _CHARACTERINPUTS_H
#define _CHARACTERINPUTS_H

#include "Inventory.h"
#include "HUD.h"

class CharacterInputs{
public:
    //getting Inventory and hud from main game
    CharacterInputs(Inventory &inventory, HUD &hud);

    void updateInputs(sf::Event keyInputs);

private:
    Inventory &inventory;
    HUD &hud;


}

#endif
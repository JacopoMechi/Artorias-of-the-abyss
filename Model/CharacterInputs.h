#ifndef _CHARACTERINPUTS_H
#define _CHARACTERINPUTS_H

#include "Inventory.h"
#include "HUD.h"
#include "Hero.h"
#include "Shop.h"
#include "GameCharacter.h"

class CharacterInputs{
public:
    //getting Inventory and hud from main game
    CharacterInputs(Inventory &inventory, HUD &hud, Hero &hero, Shop &shop);

    void updateInputs(sf::Event keyInputs);

    void moveHero(sf::Event keyInput);

    void setHeroNPCAggro(bool status);

    void setEntityCollision(GameCharacter &entityCollision);

private:
    //all the stuff needed to handle inputs
    Inventory &inventory;
    HUD &hud;
    Hero &hero;
    Shop &shop;
    GameCharacter* entityCollision;
    bool isInRange = false;
};

#endif
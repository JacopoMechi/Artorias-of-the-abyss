#ifndef _CHARACTERINPUTS_H
#define _CHARACTERINPUTS_H

#include "Inventory.h"
#include "HUD.h"
#include "Hero.h"
#include "Shop.h"
#include "GameCharacter.h"
#include "RoomElement.h"

class CharacterInputs{
public:
    //getting Inventory and hud from main game
    CharacterInputs(Inventory &inventory, HUD &hud, Hero &hero, Shop &shop);

    void updateInputs(sf::Event keyInputs);

    void moveHero(sf::Event keyInput);

    void setHeroEntityAggro(bool NPCStatus, bool entityStatus);

    void setEntityCollision(GameCharacter *entityCollision);
    void setEntityCollision(RoomElement *element);

    void solveNPCCollision();
    void solveElementCollision();

private:
    //all the stuff needed to handle inputs
    Inventory &inventory;
    HUD &hud;
    Hero &hero;
    Shop &shop;
    GameCharacter* entityCollision = nullptr;
    RoomElement* element = 0;
    bool entityInRange = false;
    bool NPCInRange = false;
};

#endif
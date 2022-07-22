#ifndef _CHARACTERINPUTS_H
#define _CHARACTERINPUTS_H

#include "GUI/Inventory.h"
#include "GUI/HUD.h"
#include "GameCharacters/Hero.h"
#include "GUI/Shop.h"
#include "GameCharacters/GameCharacter.h"
#include "Rooms/RoomElement.h"
#include "achivementsObserver.h"
#include "Constants.h"

class CharacterInputs
{
public:
    // getting Inventory and hud from main game
    CharacterInputs(Inventory &inventory, HUD &hud, Hero &hero, Shop &shop);

    void updateInputs(sf::Event keyInputs);
    int updateBonefireInputs(sf::Event keyInputs, int level);

    void moveHero(sf::Event keyInput);

    void setHeroEntityAggro(bool NPCStatus, bool entityStatus);

    void setEntityCollision(GameCharacter *entityCollision);
    void setEntityCollision(RoomElement *element);

    void attach(AchivementsObserver &achivementsObserver);

    void deleteEntity();
    void deleteNPC();

    void solveNPCCollision();
    void solveElementCollision();

private:
    // all the stuff needed to handle inputs
    Inventory &inventory;
    HUD &hud;
    Hero &hero;
    Shop &shop;
    GameCharacter *entityCollision = nullptr;
    RoomElement *element = nullptr;
    int respawnLevel = 0;
    bool entityInRange = false;
    bool NPCInRange = false;
    std::unique_ptr<AchivementsObserver> achivementObserver;
};

#endif
#ifndef _HUD_H
#define _HUD_H

#include <SFML/Graphics.hpp>

#include "GameCharacters/GameCharacter.h"
#include "Inventory.h"
#include "Items/Item.h"
#include "Items/EstusFlask.h"
#include "Items/GreenBlossom.h"
#include "Items/HomewardBone.h"
#include "Items/Pendant.h"
#include "Items/NullItem.h"
#include "GameCharacters/NPC.h"

class HUD
{

public:
    HUD(sf::RenderWindow &window, Hero &hero, Inventory &inventroy);
    ~HUD();

    // setting text pool for displaying on hud
    void setTextPool(std::vector<std::wstring> textPool);

    void draw();

    void displayHealthAndEffects(Hero &hero);

    void assignItemInQuickslot(int slot);

    // display money counter in hud
    void displayMoneyCounter(Hero &hero);

    // obscuring action buttons
    void obscureButton(sf::Vector2f pos);

    // displaying item count on quickslot
    void displayItemCount(Item *item, sf::Vector2f pos);

    // method to display interact box for interactions NPCs
    void drawInteractBox(sf::Vector2f pos);

    // drawing tracker for selecting an item to buy
    void drawShopTracker(sf::Vector2f pos);

    // drawing text for all menus
    void drawShopText(std::wstring text, sf::Vector2f textPos);

    // drawing shop box
    void drawShop(Item *item1, Item *item2);
    void drawShop(Item *item1);

    // getting delay time to display item effects
    void gettingDelayTime(float dt);

    // method to use an item
    void useItem(int nItem, Hero &hero);

    // to open/close interaction menu
    bool getInteraction() const;
    void setInteraction(bool isInteraction);

    // to get npc type
    void setType(int NPCType);

    // setting aggro to obscure interact button in case hero is not in range
    void setAggro(bool entityInRange, bool NPCInRange);

    // getter and setter for talking
    bool getIsTalking();
    void setIsTalking(bool isTalking);

    // method to go through npc's phrases
    void nextPhrase();

protected:
    // for using quickslot items
    Hero &hero;
    // font for drawing text
    sf::Font font;
    // for functions of sprites
    sf::RenderWindow &window;
    // texture and sprites for hud
    sf::Texture hudTexture;
    sf::Sprite healthSprite;
    sf::Sprite moneyCounterSprite;
    sf::Sprite quickslotSprite;
    sf::Sprite actionsSprite;
    // obscure button sprite
    sf::Sprite obscureSprite;
    // text for interactions
    sf::Text interactText;
    sf::Text text;
    sf::Text healthText;
    sf::Text moneyText;
    sf::Text itemAmountText;
    // sprite for interaction box
    sf::Sprite boxSprite;
    // getting text pool to display it
    std::vector<std::wstring> textPool;

    // boolean value to obscure interact button in case hero is not in range of npc
    bool isAggro = false;

    // switch for talking
    bool isTalking = false;

    // boolean value to ope/close interaction value
    bool isInteraction = false;

    // for tracking phrase number
    int dialogueTracker = 0;

    // npc type
    int NPCType = -1; //-1 as default

    // for displaying items in quickslot
    Item *quickSlot[3] = {new NullItem(), new NullItem(), new NullItem()};

    // inserting inventory
    Inventory &inventory;
};
#endif
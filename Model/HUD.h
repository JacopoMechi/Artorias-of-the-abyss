#ifndef _HUD_H
#define _HUD_H

#include <SFML/Graphics.hpp>

#include "GameCharacter.h"
#include "Inventory.h"
#include "Item.h"
#include "EstusFlask.h"
#include "GreenBlossom.h"
#include "HomewardBone.h"
#include "Pendant.h"
#include "NullItem.h"
#include "NPC.h"


class HUD
{

public:

    HUD(sf::RenderWindow &window, Hero &hero);
    ~HUD();

    //setting text pool for displaying on hud
    void setTextPool(std::vector<std::wstring> textPool);

    //method for blocking hero when is intercating with an NPC
    bool getIsInteraction() const;

    void draw();

    void displayHealthAndEffects(Hero &hero);


    void updateEvent(sf::Event keyInput);

    void drawQuickSlot();

    void assignItem(Item *consumable, int slot);

    void checkNPCAggro(NPC &npc);

    //display money counter in hud
    void displayMoneyCounter(Hero &hero);

    //obscuring action buttons
    void obscureButton(sf::Vector2f pos);

    //displaying item count on quickslot
    void displayItemCount(Item* item, sf::Vector2f pos);

    //method to display interact box for interactions NPCs
    void drawInteractBox(sf::Vector2f pos);

    //getting type of npc with which the player is interacting
    void setNPCType(int NPCType);

    //drawing tracker for selecting an item to buy
    void drawShopTracker(sf::Vector2f pos);

    //drawing text for all menus 
    void drawShopText(std::wstring text, sf::Vector2f textPos);

    //drawing shop box
    void drawShop(Item* item1, Item* item2);
    void drawShop(Item* item1);

    //getting delay time to display item effects
    void gettingDelayTime(float dt);

protected:
    //for using quickslot items
    Hero &hero;
    //for functions of sprites
    sf::RenderWindow &window;
    //texture and sprites for hud
    sf::Texture hudTexture;
    sf::Sprite healthSprite;
    sf::Sprite moneyCounterSprite;
    sf::Sprite quickslotSprite;
    sf::Sprite actionsSprite;
    sf::Sprite descriptionSprite;
    sf::Sprite assignSprite;
    sf::Sprite trackerSprite;
    //obscure button sprite
    sf::Sprite obscureSprite;
    //shop sprite declaration
    sf::Sprite shopSprite;
    //interactions sprite declaration
    sf::Sprite interactionBoxSprite;
    //tracker sprite for shop
    sf::Sprite shopTrackerSprite;
    //text for interactions
    sf::Text interactText;
    sf::Text text;
    sf::Text healthText;
    sf::Text moneyText;
    sf::Text itemAmountText;
    //for displaying error message when the character doesn't have enough money
    sf::Text errorMessage;
    sf::Font font;
    //for displaying error message when you dont have enough money to buy an item
    bool printErrorMessage = false;
    //getting text pool to display it
    std::vector<std::wstring> textPool;
    //for setting position of shop tracker sprite
    sf::Vector2f shopTrackerPos = {773, 340};
    //for getting NPC type
    int NPCType = -1; //because from 0 to 3 are NPCs

    bool switching = false;
    bool quickAssign = false;
    //to get NPC aggro in hud for interactions
    bool NPCAggro = false;
    //setting spell direction for hero
    int spellDirection; //it can be 1(right) or -1(left)
    //boolean value to let the character buy from merchant
    bool wantsTobuy = false;

    //switch for open shop
    bool isInteraction = false;

    //switch for shop menu
    bool isShop = false;

    //switch for talking
    bool isTalking = false;

    //for tracking phrase number
    int dialogueTracker = 0;
    
    //bool value to open buying menu
    bool isBuying = false;

    //getting price of the item for shop
    int price = 0;

    //for displaying items in quickslot
    Item* quickSlot[3] = {new NullItem(), new NullItem(), new NullItem()};

    //inserting inventory
    Inventory inventory;
};
#endif
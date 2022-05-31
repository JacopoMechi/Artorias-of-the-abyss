#ifndef _HUD_H
#define _HUD_H

#include <SFML/Graphics.hpp>

#include "GameCharacter.h"
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

    bool getInvIsOpen() const;

    //setter for setting items amount in inventory
    void setItemAmount(int itemNumber, int amount);

    void setFirstTab(bool firstTab);

    //setting text pool for displaying on hud
    void setTextPool(std::vector<std::wstring> textPool);

    //method for blocking hero when is intercating with an NPC
    bool getIsInteraction() const;

    void draw();

    void displayHealth(Hero &hero);

    void displayDescription();

    void drawInventory();

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
    sf::Sprite inventorySprite;
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

    bool isInvOpen = false;
    bool firstTab = true;
    int inventoryScroll = 0;
    int descriptionScroll = 0;
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

    //Collectible items
    Item collectibles[8] = {
        //guardiano
        {L"Anima del Guardiano", 0,L"Anima del leone alato bianco, \nprotettore del Santuario, che \ntemeva la diffusione dell'Abisso.",
         1, 1, 396, 73, 18, 22},

        //Artorias
        {L"Anima di Artorias", 0, L"Anima di un cavaliere valoroso, che \nè stato consumato dall'Abiosso. "
        L"La \nLeggenda narra che Artorias ha \nsconfitto l'Abisso, ma è solo una \nstoria raccontata a metà; "
        L"sembra \nche sia stato sconfitto e il suo onore \npreservato da un eroe non \ncelebrato, "
        L"il quale ha veramente \nsconfitto l'Abisso.", 1, 1, 440, 73, 18, 22},

        //Manus
        {L"Anima di Manus", 0 , L"Anima di manus, Padre dell'Abisso. \nChiaramente, una volta era un \nessere umano che, a causa della"
        L" \nperdita di un oggetto a lui caro, un \npendente, che lo portò alla follia, \ndivenne Padre dell'Abisso.", 1 , 1, 396, 99, 18, 22},

        //cittadino di Oolacile
        {L"Testa Cittadino \ndi Oolacile", 0, L"Creature umanoidi "
        L"corrotte \ndall'Abisso. Sono caratterizzati da \nun busto di cavallo e una folta \nbarba, con occhi di colore rosso.", 
        1, 1, 440, 96, 23, 26},  
        
        //stregone di Oolacile
        {L"Testa Stregone \ndi Oolacile", 0, L"Creature che somigliano "
        L"ai cittadini \ndi Oolacile, ma possiedono un aspetto \nfemminile.", 1, 1, 497, 47, 27, 21},

        //Scudo di Artorias(scudo grande purificatore) 
        {L"Scudo Grande \nPurificatore", 0, L"Scudo usato da Artorias, cavaliere \nche ha affrontato l'Abisso. Artorias, \nprofondamente spaventato \n"
        L"dall'Abisso, usò questo scudo per \nproteggere il suo fedele compagno \nSif dalle Disumanità. Purtroppo, \nrisulta uno scudo troppo "
        L"pesante \nper essere equipaggiato.", 1, 1, 419, 143, 22, 21},

        //Guardiano di Pietra
        {L"Testa guardiano \ndi Pietra", 0, L"Testa dei Guardiani di Pietra. In \nrealtà, questi nemici sono un corpo di \npietra "
        L"animato, armati di un'ascia di \npietra, ma senza uno scudo.", 1 , 1, 497, 24, 21, 21}, 
        
        //Disumanita'
        {L"Disumanità", 0, L"Queste creature sono una \n"
        L"rappresentazione dell'umanità come \nun'entità non ancora formatasi. A \ndifferenza degli altri nemici, non \nhanno alcun attacco e "
        L"danneggiano \nsolo attraverso il contatto fisico.", 1, 1, 497, 0, 22, 20} 
        
    };

    //creating consumable 
    Item* consumables[4] = {new EstusFlask(), new GreenBlossom(), new HomewardBone(), new Pendant()};
};
#endif
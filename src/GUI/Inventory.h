#ifndef _INVENTORY_H
#define _INVENTORY_H

#include <SFML/Graphics.hpp>

#include "Items/Item.h"
#include "Items/EstusFlask.h"
#include "Items/GreenBlossom.h"
#include "Items/HomewardBone.h"
#include "Items/Pendant.h"
#include "Items/NullItem.h"
#include "Constants.h"

class Inventory
{
public:
    Inventory(sf::RenderWindow &window);
    ~Inventory() = default;

    // getter and setter to open inventory from HUD
    bool getOpen() const;
    void setOpen(bool isOpen);

    // to assign item
    Item *receiveItem() const;
    Item *receiveItem(int nItem) const;

    // to set item amount when an item is bought
    void setItemAmount(int nItem, int amount);

    // getter for nTab to assign item only on first tab
    int getNTab() const;

    // to switch between first and previous tab
    void nextTab();
    void previousTab();

    // to switch between first and previous page
    virtual void nextItem();
    virtual void previousItem();

    // method to reset nPage, tracker and nTab
    void resetPositions();

    // method to show the description of the item
    bool getShowDescription() const;
    void setShowDescription(bool showDescription);

    // method to display assign sprite system
    virtual void displayBox();

    // method to open/close assign box
    bool getAssign() const;
    void setAssign(bool isAssign);

    // to draw text for the inventory
    void drawText(std::wstring text, sf::Vector2f pos, int characterSize);

    // to draw item's description when enter button is pressed on highlited item
    void drawDescription(int nItem);

    // drawing Inventory and items
    // virtual for shop
    virtual void draw();

protected:
    // to display items and inventory in hud
    sf::RenderWindow &window;

    // font for drawing text in inventory
    sf::Font font;

    // setting text for inventory
    sf::Text text;

    // setting texture to display sprites
    sf::Texture texture;

    // to display inventory sprite
    sf::Sprite sprite;

    // to display box sprite for items' descriptions
    sf::Sprite descriptionSprite;

    // to display assign box for items assign
    sf::Sprite boxSprite;

    // for tracking item in inventory
    sf::Sprite trackerSprite;
    int tracker = 0; // for tracking positions
    sf::Vector2f trackerPos[4] = {{invTrackerPosX, firstTrackerPosY}, {invTrackerPosX, secondTrackerPosY}, {invTrackerPosX, thirdTrackerPosY}, {invTrackerPosX, fourthTrackerPosY}};

    // boolean value to let the hud know when we want to open/close inventory
    bool isOpen = false;

    // boolean value to get the item description
    bool showDescription = false;

    // boolean value to open assign box
    bool isAssign = false;

    // to change tab in inventory between consumables and collectibles
    int nTab = 0; // it starts from consumables
    // list of strings of two elements to indicate the name of the tab
    std::wstring tabName[2] = {L"Consumabili >", L"< Collezionabili"};

    // tracker to scroll between items
    int itemScroll = 0; // starting from the first item

    // to change page in a tab
    int nPage = 0;

    // items
    Item *items[16] = {
        // first tab
        // consumables
        new EstusFlask(),
        new GreenBlossom(),
        new HomewardBone(),
        new Pendant(),
        new NullItem(),
        new NullItem(),
        new NullItem(),
        new NullItem(),

        // second tab
        // collectibles
        // guardiano
        new Item(L"Anima del Guardiano", 0, L"Anima del leone alato bianco, \nprotettore del Santuario, che \ntemeva la diffusione dell'Abisso.",
                 1, 1, {guardianSoulX, guardianSoulY, guardianSoulWidth, guardianSoulHeight}, {0, 0, 0, 0}),
        // Artorias
        new Item(L"Anima di Artorias", 0, L"Anima di un cavaliere valoroso, che \n?? stato consumato dall'Abiosso. "
                                          L"La \nLeggenda narra che Artorias ha \nsconfitto l'Abisso, ma ?? solo una \nstoria raccontata a met??; "
                                          L"sembra \nche sia stato sconfitto e il suo onore \npreservato da un eroe non \ncelebrato, "
                                          L"il quale ha veramente \nsconfitto l'Abisso.",
                 1, 1, {artoriasX, artoriasY, artoriasWidth, artoriasHeight}, {0, 0, 0, 0}),
        // Manus
        new Item(L"Anima di Manus", 0, L"Anima di manus, Padre dell'Abisso. \nChiaramente, una volta era un \nessere umano che, a causa della"
                                       L" \nperdita di un oggetto a lui caro, un \npendente, che lo port?? alla follia, \ndivenne Padre dell'Abisso.",
                 1, 1,
                 {manusX, manusY, manusWidth, manusHeight}, {0, 0, 0, 0}),
        // cittadino di oolacile
        new Item(L"Testa Cittadino \ndi Oolacile", 0, L"Creature umanoidi "
                                                      L"corrotte \ndall'Abisso. Sono caratterizzati da \nun busto di cavallo e una folta \nbarba, con occhi di colore rosso.",
                 1, 1, {residentX, residentY, residentWidth, residentHeight}, {0, 0, 0, 0}),
        // stregone di oolacile
        new Item(L"Testa Stregone \ndi Oolacile", 0, L"Creature che somigliano "
                                                     L"ai cittadini \ndi Oolacile, ma possiedono un aspetto \nfemminile.",
                 1, 1, {sorcererX, sorcererY, sorcererWidth, sorcererHeight}, {0, 0, 0, 0}),
        // scudo di Artorias (scudo grande purificatore)
        new Item(L"Scudo Grande \nPurificatore", 0, L"Scudo usato da Artorias, cavaliere \nche ha affrontato l'Abisso. Artorias, \nprofondamente spaventato \n"
                                                    L"dall'Abisso, us?? questo scudo per \nproteggere il suo fedele compagno \nSif dalle Disumanit??. Purtroppo, \nrisulta uno scudo troppo "
                                                    L"pesante \nper essere equipaggiato.",
                 1, 1, {aShieldX, aShieldY, aShieldWidth, aShieldHeight}, {0, 0, 0, 0}),
        // guardiano di pietra
        new Item(L"Testa guardiano \ndi Pietra", 0, L"Testa dei Guardiani di Pietra. In \nrealt??, questi nemici sono un corpo di \npietra "
                                                    L"animato, armati di un'ascia di \npietra, ma senza uno scudo.",
                 1, 1, {stoneGuardX, stoneGuardY, stoneGuardWidth, stoneGuardHeight}, {0, 0, 0, 0}),
        // disumanita'
        new Item(L"Disumanit??", 0, L"Queste creature sono una \n"
                                   L"rappresentazione dell'umanit?? come \nun'entit?? non ancora formatasi. A \ndifferenza degli altri nemici, non \nhanno alcun attacco e "
                                   L"danneggiano \nsolo attraverso il contatto fisico.",
                 1, 1, {humanityX, humanityY, humanityWidth, humanityHeight}, {0, 0, 0, 0})};
};

#endif
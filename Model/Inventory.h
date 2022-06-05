#ifndef _HUD_H
#define _HUD_H

#include <SFML/Graphics.hpp>

#include "Item.h"
#include "EstusFlask.h"
#include "GreenBlossom.h"
#include "HomewardBone.h"
#include "Pendant.h"
#include "NullItem.h"

class Inventory{
public:

    Inventory(sf::RenderWindow &window);
    ~Inventory() = default;

    //getter and setter to open inventory from HUD
    bool getInvOpen() const;
    void setInvOpen(bool isInventoryOpen);

    //getter and setter for when the character use or acquire an item//TODO maybe useful later
    int getItemCount(Item &item) const;
    void setItemCount(Item &item, int value);

    //to switch between first and previous tab
    void nextTab();
    void previousTab();

    //drawing Inventory and items
    void draw() const;

private:
    //to display items and inventory in hud
    sf::RenderWindow &window;

    //setting texture to display sprites
    sf::Texture texture;

    //to display inventory sprite
    sf::Sprite inventorySprite;

    //boolean value to let the hud know when we want to open/close inventory
    bool isInventoryOpen = false;

    //to change tab in inventory between consumables and collectibles
    int nTab = 0;//it starts from consumables

    //tracker to scroll between items
    int itemScroll = 0;//starting from the first item

    //items
    Item* items[16] = {
        //first tab
        //consumables
        new EstusFlask(), 
        new GreenBlossom(), 
        new HomewardBone(), 
        new Pendant(),
        new NullItem(),
        new NullItem(),
        new NullItem(),
        new NullItem(),

        //second tab
        //collectibles
        //guardiano
        new Item(L"Anima del Guardiano", 0,L"Anima del leone alato bianco, \nprotettore del Santuario, che \ntemeva la diffusione dell'Abisso.",
         1, 1, {396, 73, 18, 22}, {0, 0, 0, 0}),
        //Artorias
        new Item(L"Anima di Artorias", 0, L"Anima di un cavaliere valoroso, che \nè stato consumato dall'Abiosso. "
        L"La \nLeggenda narra che Artorias ha \nsconfitto l'Abisso, ma è solo una \nstoria raccontata a metà; "
        L"sembra \nche sia stato sconfitto e il suo onore \npreservato da un eroe non \ncelebrato, "
        L"il quale ha veramente \nsconfitto l'Abisso.", 1, 1, {440, 73, 18, 22}, {0, 0, 0, 0}),
        //Manus
        new Item(L"Anima di Manus", 0 , L"Anima di manus, Padre dell'Abisso. \nChiaramente, una volta era un \nessere umano che, a causa della"
        L" \nperdita di un oggetto a lui caro, un \npendente, che lo portò alla follia, \ndivenne Padre dell'Abisso.", 1 , 1, 
        {396, 99, 18, 22}, {0, 0, 0, 0}),
        //cittadino di oolacile
        new Item(L"Testa Cittadino \ndi Oolacile", 0, L"Creature umanoidi "
        L"corrotte \ndall'Abisso. Sono caratterizzati da \nun busto di cavallo e una folta \nbarba, con occhi di colore rosso.", 
        1, 1, {440, 96, 23, 26}, {0, 0, 0, 0}),
        //stregone di oolacile
        new Item(L"Testa Stregone \ndi Oolacile", 0, L"Creature che somigliano "
        L"ai cittadini \ndi Oolacile, ma possiedono un aspetto \nfemminile.", 1, 1, {497, 47, 27, 21}, {0, 0, 0, 0}),
        //scudo di Artorias (scudo grande purificatore)
        new Item(L"Scudo Grande \nPurificatore", 0, L"Scudo usato da Artorias, cavaliere \nche ha affrontato l'Abisso. Artorias, \nprofondamente spaventato \n"
        L"dall'Abisso, usò questo scudo per \nproteggere il suo fedele compagno \nSif dalle Disumanità. Purtroppo, \nrisulta uno scudo troppo "
        L"pesante \nper essere equipaggiato.", 1, 1, {419, 143, 22, 21}, {0, 0, 0, 0}),
        //guardiano di pietra
        new Item(L"Testa guardiano \ndi Pietra", 0, L"Testa dei Guardiani di Pietra. In \nrealtà, questi nemici sono un corpo di \npietra "
        L"animato, armati di un'ascia di \npietra, ma senza uno scudo.", 1 , 1, {497, 24, 21, 21}, {0, 0, 0, 0}),
        //disumanita'
        new Item(L"Disumanità", 0, L"Queste creature sono una \n"
        L"rappresentazione dell'umanità come \nun'entità non ancora formatasi. A \ndifferenza degli altri nemici, non \nhanno alcun attacco e "
        L"danneggiano \nsolo attraverso il contatto fisico.", 1, 1, {497, 0, 22, 20}, {0, 0, 0, 0})
    };
};

#endif
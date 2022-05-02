#ifndef _HUD_H
#define _HUD_H

#include <SFML/Graphics.hpp>

#include "GameCharacter.h"
#include "Item.h"
#include "EstusFlask.h"
#include "GreenBlossom.h"
#include "HomewardBone.h"
#include "Pendant.h"
#include "NPC.h"

class HUD
{

public:

    HUD(sf::RenderWindow &window, Hero &hero);

    bool getInvIsOpen();

    void setFirstTab(bool firstTab);

    void draw() const;

    void displayHealth(GameCharacter &character);

    void displayDescription();

    void drawInventory();

    void updateEvent(sf::Event keyInput, bool isInteracting);

    void drawQuickSlot();

    void assignItem(Item *consumable, int slot);

    void checkNPCAggro(NPC npc);

protected:
    //for using quickslot items
    Hero &hero;
    //for functions of sprites
    sf::RenderWindow &window;
    //texture and sprites for hud
    sf::Texture hudTexture;
    sf::Sprite healthSprite;
    sf::Sprite quickslotSprite;
    sf::Sprite actionsSprite;
    sf::Sprite inventorySprite;
    sf::Sprite descriptionSprite;
    sf::Sprite assignSprite;
    sf::Sprite trackerSprite;
    sf::Text text;
    sf::Font font;
    //obscure interact button in hud
    sf::Sprite obscureInteract;
    //switch for some sprites like inventory, healthsprite,...
    bool isInvOpen = false;
    bool firstTab = true;
    int inventoryScroll = 0;
    int descriptionScroll = 0;
    bool switching = false;
    bool quickAssign = false;
    //to get NPC aggro in hud for interactions
    bool NPCAggro = false;

    //for displaying items in quickslot
    //{"empty slot", 0, "...", 0, 0, 129, 4, 1, 1}
    std::vector <Item*> quickSlot = {NULL, NULL, NULL};

    //Collectible items
    Item collectibles[8] = {
        //guardiano
        {"Anima del Guardiano", 0,"Anima del leone alato bianco, protettore del \nSantuario, che temeva la diffusione \ndell'Abisso.",
         1, 2, 396, 73, 18, 22},

        //Artorias
        {"Anima di Artorias", 0, "Anima di un cavaliere valoroso, che è stato \nconsumato dall'Abiosso. "
        "La Leggenda narra \nche Artorias ha sconfitto l'Abisso, ma è solo \nuna storia raccontata a metà; "
        "sembra che \nsia stato sconfitto e il suo onore preservato \nda un eroe non celebrato, "
        "il quale ha \nveramente sconfitto l'Abisso.", 1, 1, 440, 73, 18, 22},

        //Manus
        {"Anima di Manus", 0 , "Anima di manus, Padre dell'Abisso. \nChiaramente, una volta era un essere umano \nche, a causa della"
        " perdita di un oggetto a lui \ncaro, un pendente, che lo portò alla follia, \ndivenne Padre dell'Abisso.", 1 , 1, 396, 99, 18, 22},

        //cittadino di Oolacile
        {"Testa Cittadino di Oolacile", 0, "Creature umanoidi "
        "corrotte dall'Abisso. Sono \ncaratterizzati da un busto di cavallo e una \nfolta barba, con occhi di colore rosso.", 
        1, 1, 440, 96, 23, 26},  
        
        //stregone di Oolacile
        {"Testa Stregone di Oolacile", 0, "Creature che somigliano "
        "ai cittadini di Oolacile, \nma possiedono un aspetto femminile.", 1, 1, 497, 47, 27, 21},

        //Scudo di Artorias(scudo grande purificatore) 
        {"Scudo Grande Purificatore", 0, "Scudo usato da Artorias, cavaliere che ha \naffrontato l'Abisso. Artorias, profondamente \nspaventato "
        "dall'Abisso, usò questo scudo \nper proteggere il suo fedele compagno Sif \ndalle Disumanità. Purtroppo, risulta uno \nscudo troppo "
        "pesante per essere \nequipaggiato.", 1, 1, 419, 143, 22, 21},

        //Guardiano di Pietra
        {"Testa guardiano di Pietra", 0, "Testa dei Guardiani di Pietra. In realtà, \nquesti nemici sono un corpo di pietra "
        "animato, \narmati di un'ascia di pietra, ma senza uno \nscudo.", 1 , 1, 497, 24, 21, 21}, 
        
        //Disumanita'
        {"Disumanità", 0, "Queste creature sono una "
        "rappresentazione \ndell'umanità come un'entità non ancora \nformatasi. A differenza degli altri nemici, non \nhanno alcun attacco e "
        "danneggiano solo\nattraverso il contatto fisico.", 1, 1, 497, 0, 22, 20} 
        
    };

    //creating consumable 
    std::vector<Item*> consumables = {new EstusFlask(), new GreenBlossom(), new HomewardBone(), new Pendant()};
};
#endif
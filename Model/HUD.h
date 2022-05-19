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

    bool getInvIsOpen();

    void setFirstTab(bool firstTab);

    void draw();

    void displayHealth(GameCharacter &character);

    void displayDescription();

    void drawInventory();

    void updateEvent(sf::Event keyInput, bool isInteracting);

    void drawQuickSlot();

    void assignItem(Item *consumable, int slot);

    void checkNPCAggro(NPC &npc);

    //obscuring action buttons
    void obscureButton(sf::Vector2f pos);

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
    sf::Text healthText;
    sf::Font font;
    //obscure button sprite
    sf::Sprite obscureSprite;
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

    //for displaying items in quickslot
    Item* quickSlot[3] = {new NullItem(), new NullItem(), new NullItem()};

    //Collectible items
    Item collectibles[8] = {
        //guardiano
        {L"Anima del Guardiano", 0,L"Anima del leone alato bianco, protettore del \nSantuario, che temeva la diffusione \ndell'Abisso.",
         1, 1, 396, 73, 18, 22},

        //Artorias
        {L"Anima di Artorias", 0, L"Anima di un cavaliere valoroso, che è stato \nconsumato dall'Abiosso. "
        L"La Leggenda narra \nche Artorias ha sconfitto l'Abisso, ma è solo \nuna storia raccontata a metà; "
        L"sembra che \nsia stato sconfitto e il suo onore preservato \nda un eroe non celebrato, "
        L"il quale ha \nveramente sconfitto l'Abisso.", 1, 1, 440, 73, 18, 22},

        //Manus
        {L"Anima di Manus", 0 , L"Anima di manus, Padre dell'Abisso. \nChiaramente, una volta era un essere umano \nche, a causa della"
        L" perdita di un oggetto a lui \ncaro, un pendente, che lo portò alla follia, \ndivenne Padre dell'Abisso.", 1 , 1, 396, 99, 18, 22},

        //cittadino di Oolacile
        {L"Testa Cittadino \ndi Oolacile", 0, L"Creature umanoidi "
        L"corrotte dall'Abisso. Sono \ncaratterizzati da un busto di cavallo e una \nfolta barba, con occhi di colore rosso.", 
        1, 1, 440, 96, 23, 26},  
        
        //stregone di Oolacile
        {L"Testa Stregone \ndi Oolacile", 0, L"Creature che somigliano "
        L"ai cittadini di Oolacile, \nma possiedono un aspetto femminile.", 1, 1, 497, 47, 27, 21},

        //Scudo di Artorias(scudo grande purificatore) 
        {L"Scudo Grande \nPurificatore", 0, L"Scudo usato da Artorias, cavaliere che ha \naffrontato l'Abisso. Artorias, profondamente \nspaventato "
        L"dall'Abisso, usò questo scudo \nper proteggere il suo fedele compagno Sif \ndalle Disumanità. Purtroppo, risulta uno \nscudo troppo "
        L"pesante per essere \nequipaggiato.", 1, 1, 419, 143, 22, 21},

        //Guardiano di Pietra
        {L"Testa guardiano \ndi Pietra", 0, L"Testa dei Guardiani di Pietra. In realtà, \nquesti nemici sono un corpo di pietra "
        L"animato, \narmati di un'ascia di pietra, ma senza uno \nscudo.", 1 , 1, 497, 24, 21, 21}, 
        
        //Disumanita'
        {L"Disumanità", 0, L"Queste creature sono una "
        L"rappresentazione \ndell'umanità come un'entità non ancora \nformatasi. A differenza degli altri nemici, non \nhanno alcun attacco e "
        L"danneggiano solo\nattraverso il contatto fisico.", 1, 1, 497, 0, 22, 20} 
        
    };

    //creating consumable 
    Item* consumables[4] = {new EstusFlask(), new GreenBlossom(), new HomewardBone(), new Pendant()};
};
#endif
#ifndef _HUD_H
#define _HUD_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Glyph.hpp>

#include "GameCharacter.h"
#include "Item.h"
#include "EstusFlask.h"
#include "GreenBlossom.h"
#include "HomewardBone.h"
#include "Pendant.h"

class HUD{

public:

    HUD(bool isInvOpen, bool firstTab, int nScroll, sf::RenderWindow &window);

    bool getInvIsOpen();

    void setInvIsOpen(bool isInvOpen);

    void setFirstTab(bool firstTab);

    void draw(sf::RenderTarget &rt) const;

    void displayHealth(GameCharacter &character, sf::RenderTarget &rt);

    void displayDescription();

    void drawInventory();

    void openCloseInv();

    void scrollList();

    void updateEvent(sf::Event keyInput);

    //TODO for later: void updateDelayTime(float dt);

protected:
    //for functions of sprites
    sf::RenderWindow &window;//TODO adjust in other methos
    //texture and sprites for hud
    sf::Texture hudTexture;
    sf::Sprite healthSprite;
    sf::Sprite quickslotSprite;
    sf::Sprite actionsSprite;
    sf::Sprite inventorySprite;
    sf::Sprite descriptionSprite;
    sf::Text text;
    sf::Font font;
    bool isInvOpen;
    bool firstTab;
    int nScroll;
    bool switching = false;

    //Collectible items
    Item collectibles[8] = {
        //guardiano
        {"Anima del Guardiano", 0,"Anima del leone alato bianco, protettore del Santuario, che temeva la diffusione dell'abisso", 1, 0, 396, 73, 18, 22},

        //Artorias
        {"Anima di Artorias", 0, "Anima di un cavaliere valoroso, che è stato consumato dall'Abiosso. "
        "La Leggenda narra che Artorias ha sconfitto l'Abisso, ma è solo una storia raccontata a metà; "
        "sembra che sia stato sconfitto e il suo onore preservato da un eroe non celebrato, "
        "il quale ha veramente sconfitto l'Abisso", 1, 0, 440, 73, 18, 22},

        //Manus
        {"Anima di Manus", 0 , "Anima di manus, Padre dell'Abisso. Chiaramente, una volta era un essere umano che, a causa della"
        " perdita di un oggetto a lui caro, un pendente, che lo portò alla follia, divenne Padre dell'Abisso", 1 , 0, 396, 99, 18, 22},

        //cittadino di Oolacile
        {"Testa Cittadino di Oolacile", 0, "Creature umanoidi \
        corrotte dall'Abisso. Sono caratterizzati da un busto di cavallo e una folta barba, con occhi di colore rosso", 1, 0, 440, 96, 23, 26},  
        
        //stregone di Oolacile
        {"Testa Stregone di Oolacile", 0, "Creature che somigliano "
        "ai cittadini di Oolacile, ma possiedono un aspetto femminile", 1, 0, 497, 47, 27, 21},

        //Scudo di Artorias(scudo grande purificatore) 
        {"Scudo Grande Purificatore", 0, "Scudo usato da Artorias, cavaliere che ha affrontato l'Abisso. Artorias, profondamente spaventato "
        "dall'Abisso, usò questo scudo per proteggere il suo fedele compagno Sif dalle Disumanità. Purtroppo, risulta uno scudo troppo "
        "pesante per essere equipaggiato", 1, 1, 419, 143, 22, 21},

        //Guardiano di Pietra
        {"Testa guardiano di Pietra", 0, "Testa dei Guardiani di Pietra. In realtà, questi nemici sono un corpo di pietra "
        " animato, armati di un'ascia di pietra, ma senza uno scudo", 1 , 0, 497, 24, 21, 21}, 
        
        //Disumanita'
        {"Disumanità", 0, "Queste creature sono una "
        "rappresentazione dell'umanità come un'entità non ancora formatasi. A differenza degli altri nemici, non hanno alcun attacco e "
        "danneggiano solo attraverso il contatto fisico", 1, 0, 497, 0, 22, 20} 
        
    };

    //Consumable items
    EstusFlask flask;
    GreenBlossom blossom;
    HomewardBone homeward;
    Pendant pendant;  
};
#endif
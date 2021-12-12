#ifndef _HUD_H
#define _HUD_H

#include <SFML/Graphics.hpp>

#include "GameCharacter.h"
#include "Item.h"

class HUD{

public:

    HUD(bool isInvOpen, bool firstTab, int nScroll);

    bool getInvIsOpen();

    void setInvIsOpen(bool isInvOpen);

    void setFirstTab(bool firstTab);

    void draw(sf::RenderTarget &rt) const;

    void displayHealth(GameCharacter &character, sf::RenderTarget &rt);

    void drawInventory(sf::RenderTarget &rt);

    void openCloseInv();

    void scrollList();

protected:
    sf::Texture hudTexture;
    sf::Sprite healthSprite;
    sf::Sprite quickslotSprite;
    sf::Sprite actionsSprite;
    sf::Sprite inventorySprite;
    sf::Text text;
    sf::Font font;
    bool isInvOpen;
    bool firstTab;
    int nScroll;
    Item firstCollRaw[2] = {{"Anima del Guardiano", 0,
        "Anima del leone alato bianco, protettore del Santuario, che temeva la diffusione dell'abisso", 1, 1, 396, 71, 18, 22}, 
        {"Testa Cittadino di Oolacile", 0, "Creature umanoidi "
        "corrotte dall'Abisso. Sono caratterizzati da un busto di cavallo e una folta barba, con occhi di colore rosso", 1, 1, 469, 95, 21, 25}};
    Item secCollRaw[2] = {{"Anima di Artorias", 0, "Anima di un cavaliere valoroso, che è stato consumato dall'Abiosso. "
        "La Leggenda narra che Artorias ha sconfitto l'Abisso, ma è solo una storia raccontata a metà; "
        "sembra che sia stato sconfitto e il suo onore preservato da un eroe non celebrato, "
        "il quale ha veramente sconfitto l'Abisso", 1, 1, 417, 71, 18, 22}, {"Testa Stregone di Oolacile", 0, "Creature che somigliano "
        "ai cittadini di Oolacile, ma possiedono un aspetto femminile", 1, 1, 440, 95, 25, 21}};    
    Item thirCollRaw[2] = {{"Anima di Manus", 0 , "Anima di manus, Padre dell'Abisso. Chiaramente, una volta era un essere umano che, a causa della"
        " perdita di un oggetto a lui caro, un pendente, che lo portò alla follia, divenne Padre dell'Abisso", 1 , 1, 440, 71, 18, 22}, 
        {"Scudo Grande Purificatore", 0, "Scudo usato da Artorias, cavaliere che ha affrontato l'Abisso. Artorias, profondamente spaventato "
        "dall'Abisso, usò questo scudo per proteggere il suo fedele compagno Sif dalle Disumanità. Purtroppo, risulta uno scudo troppo "
        "pesante per essere equipaggiato", 1, 1, 421, 143, 18, 20}};
    Item fourCollRaw[2] = {{"Testa guardiano di Pietra", 0, "Testa dei Guardiani di Pietra. In realtà, questi nemici sono un corpo di pietra "
        " animato, armati di un'ascia di pietra, ma senza uno scudo", 1 , 1, 417, 95, 19, 21}, {"Disumanità", 0, "Queste creature sono una "
        "rappresentazione dell'umanità come un'entità non ancora formatasi. A differenza degli altri nemici, non hanno alcun attacco e "
        "danneggiano solo attraverso il contatto fisico", 1, 1, 392, 96, 22, 20} };
};
#endif
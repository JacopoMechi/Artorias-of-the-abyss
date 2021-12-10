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
        "Anima del leone alato bianco, protettore del Santuario, che temeva la diffusione dell'abisso", 1, 1, 393, 2, 12, 13}, 
        {"Anima di Artorias", 0, "Anima di un cavaliere valoroso, che è stato consumato dall'Abiosso. "
        "La Leggenda narra che Artorias ha sconfitto l'Abisso, ma è solo una storia raccontata a metà; "
        "sembra che sia stato sconfitto e il suo onore preservato da un eroe non celebrato, "
        "il quale ha veramente sconfitto l'Abisso", 1, 1, 409, 2, 12, 13}};
    /*Item secCollRaw[2] = {{"Anima di Manus", 0 , "Anima di manus, Padre dell'Abisso. Chiaramente, una volta era un essere umano che, a causa della"
        " perdita di un oggetto a lui caro, un pendente, che lo portò alla follia, divenne Padre dell'Abisso", 1 , 0,}};    
    //TODO add souls sprites
    Item thirCollRaw[1];
    Item fourCollRaw[1];*///FIXME danno fastidio
};
#endif
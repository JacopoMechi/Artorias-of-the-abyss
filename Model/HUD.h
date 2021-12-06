#ifndef _HUD_H
#define _HUD_H

#include <SFML/Graphics.hpp>

#include "GameCharacter.h"
#include "Item.h"

class HUD{

public:

    HUD(bool isInvOpen, bool firstTab);

    bool getInvIsOpen();

    void setInvIsOpen(bool isInvOpen);

    bool getFirstTab();

    void setFirstTab(bool firstTab);

    void draw(sf::RenderTarget &rt) const;

    void displayHealth(GameCharacter &character, sf::RenderTarget &rt);

    void drawInventory(sf::RenderTarget &rt);

    void openCloseInv();

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
    Item guardianSoul{"Anima del Guardiano", 0, 
        "Anima del leone alato bianco, protettore del Santuario, che temeva la diffusione dell'abisso", 1, 0, 289, 273, 6, 7};//change > 0  to be displayed
    /*Item firCollRaw[1] = {Item("Anima del Guardiano", 0, 
        "Anima del leone alato bianco, protettore del Santuario, che temeva la diffusione dell'abisso", 1, 0, 289, 273, 6, 7)};
    Item secCollRaw[1];
    Item thirCollRaw[1];
    Item fourCollRaw[1];*///FIXME danno fastidio
};
#endif
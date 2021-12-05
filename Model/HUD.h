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

    void diplayInventoryTabs(sf::RenderTarget &rt);

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
    //bool swap = true;
};
#endif
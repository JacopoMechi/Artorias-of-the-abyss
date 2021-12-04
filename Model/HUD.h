#ifndef _HUD_H
#define _HUD_H

#include <SFML/Graphics.hpp>

#include "GameCharacter.h"
#include "Item.h"

class HUD{

public:

    HUD(bool isInvOpen);

    bool getInvIsOpen();

    void setInvIsOpen(bool isInvOpen);

    void draw(sf::RenderTarget &rt) const;

    void displayHealth(GameCharacter &character, sf::RenderTarget &rt);

    void useInventory();

    void drawInventory(sf::RenderTarget &rt) const;

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
};
#endif
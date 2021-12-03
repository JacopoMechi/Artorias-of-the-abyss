#ifndef _INVENTORY_H
#define _INVENTORY_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Item.h"

class Inventory {//FIXME
public:
    Inventory(bool isOpen);

    void setIsOpen(bool isOpen);

    bool getIsOpen();

    void use();

    void draw(sf::RenderTarget& rt) const;

protected:
    int itemTracker = 0;
    //Item& itemList;
    bool isOpen;
    sf::Sprite inventorySprite;
    sf::Texture inventoryTexture;
};

#endif //_INVENTORY_H
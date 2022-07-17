#ifndef _NULLITEM_H
#define _NULLITEM_H

#include "Item.h"

class NullItem: public Item{
public:
    NullItem(std::wstring itemName = L"", int itemPrice = 0, std::wstring itemDescription = L"", 
            int maxItemCount = 0, int itemCount = 0, sf::IntRect spriteRect = {0, 0, 0, 0}, sf::IntRect effectRect = {0, 0, 0, 0});
    virtual ~NullItem();

    virtual void displayItem(float posX, float posY, sf::RenderWindow &window) override;

    virtual void use(Hero &hero) override;
};

#endif
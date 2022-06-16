#ifndef _SHOP_H
#define _SHOP_H

#include "Inventory.h"

class Shop: public Inventory {
public:
    Shop(sf::RenderWindow &window);
    
    //drawing shop's interface
    virtual void draw() override;

    //getter and setter to open shop are in invetory's base class

    //overriding page switching system of iventory
    virtual void nextItem() override;
    virtual void previousItem() override;

    //getter to know which shop to open
    void setNPCType(int type);

    void purchaseItem();

private:
    int type = -1;//default value which indicates no NPCs

    //setting pos for highlight tracker in shop
    sf::Vector2f trackerShopPos[2] = {{541, 295},{541, 400}};

};

#endif //_SHOP_H
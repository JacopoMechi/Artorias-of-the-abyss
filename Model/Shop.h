#ifndef _SHOP_H
#define _SHOP_H

#include "Inventory.h"

class Shop: public Inventory {
public:
    Shop(sf::RenderWindow &window);
    
    //drawing shop's interface
    virtual void draw() override;

    //getter and setter to open shop are in invetory's base class

    //getter to know which shop to open
    void setNPCType(int type);

    void purchaseItem();

private:
    int type = -1;//default value which indicates no NPCs


};

#endif //_SHOP_H
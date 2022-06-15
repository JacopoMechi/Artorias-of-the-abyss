#ifndef _SHOP_H
#define _SHOP_H

#include "Inventory.h"

class Shop: public Inventory {
public:
    Shop(sf::RenderWindow &window);
    
    //drawing shop's interface
    virtual void draw() override;

    //getter and setter to open shop in invetory's base class

    void purchaseItem();

private:


};

#endif //_SHOP_H
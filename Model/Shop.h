#ifndef _SHOP_H
#define _SHOP_H

#include "Inventory.h"

class Shop: public Inventory {
public: 
    
    virtual void draw() override;

    void purchaseItem();

private:


};

#endif //_SHOP_H
#ifndef _INVENTORY_H
#define _INVENTORY_H

#include "Item.h"

class Inventory {
public: 
    
void use();

protected:
    int itemTracker = 0;
    Item& itemList;
};

#endif //_INVENTORY_H
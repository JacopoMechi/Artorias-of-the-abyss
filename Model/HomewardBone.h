#ifndef _HOMEWARDBONE_H
#define _HOMEWARDBONE_H

#include "Item.h"
//#include "MapElements.h"
//#include "Hero.h"

class HomewardBone: public Item {
public: 
    explicit HomewardBone(std::string itemName = "Osso del Ritorno", int itemPrice = 2000,
                 std::string itemDescription = "Permette il teletrasporto all'ultimo falo' interagito", int maxItemCount = 3, int itemCount = 0,
                 int x = 497, int y = 71, int width = 23, int height = 22);
    ~HomewardBone();

    //void use(Hero& hero, MapElements& bonfire);
};

#endif //_HOMEWARDBONE_H
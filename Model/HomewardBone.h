#ifndef _HOMEWARDBONE_H
#define _HOMEWARDBONE_H

#include "Item.h"
//#include "MapElements.h"
//#include "Hero.h"

class HomewardBone: public Item {
public: 
    explicit HomewardBone(std::wstring itemName = L"Osso del Ritorno", int itemPrice = 2000,
                 std::wstring itemDescription = L"Permette il teletrasporto \nall'ultimo falo' interagito", int maxItemCount = 3, int itemCount = 0,
                 sf::IntRect spriteRect = {497, 71, 23, 22}, sf::IntRect effectRect = {0, 0, 0, 0});
    ~HomewardBone();

    void use(Hero& hero);//, MapElements& bonfire
};

#endif //_HOMEWARDBONE_H
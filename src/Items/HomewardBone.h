#ifndef _HOMEWARDBONE_H
#define _HOMEWARDBONE_H

#include "Item.h"

class HomewardBone: public Item {
public: 
    explicit HomewardBone(std::wstring itemName = L"Osso del Ritorno", int itemPrice = 2000,
                 std::wstring itemDescription = L"Permette il teletrasporto \nall'ultimo falo' interagito", int maxItemCount = 3, int itemCount = 0,
                 sf::IntRect spriteRect = {boneX, boneY, boneWidth, boneHeight}, sf::IntRect effectRect = {0, 0, 0, 0});
    virtual ~HomewardBone();
    virtual void use(Hero& hero) override;
};

#endif //_HOMEWARDBONE_H
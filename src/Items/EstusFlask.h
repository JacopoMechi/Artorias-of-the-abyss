#ifndef _ESTUSFLASK_H
#define _ESTUSFLASK_H

#include "Item.h"

class EstusFlask: public Item {
public:
    explicit EstusFlask(std::wstring itemName = L"Fiaschetta di Cura",int itemPrice = 0,
                        std::wstring itemDescriptin = L"Fiaschette che curano \n30hp", int maxItemCount = 5, int itemCount = 5, 
                        sf::IntRect spriteRect = {flaskX, flaskY, flaskWidth, flaskHeight}, sf::IntRect effectRect = {flaskEffectX, flaskEffectY, flaskEffectWidth, flaskEffectHeight});
    virtual ~EstusFlask();
    virtual void use(Hero& hero) override;
private:
    int healthRestored = 30;
};

#endif //_ESTUSFLASK_H
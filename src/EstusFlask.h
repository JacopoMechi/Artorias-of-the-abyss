#ifndef _ESTUSFLASK_H
#define _ESTUSFLASK_H

#include "Item.h"

class EstusFlask: public Item {
public:
    explicit EstusFlask(std::wstring itemName = L"Fiaschetta di Cura",int itemPrice = 0,
                        std::wstring itemDescriptin = L"Fiaschette che curano \n30hp", int maxItemCount = 5, int itemCount = 5, 
                        sf::IntRect spriteRect = {412, 2, 20, 21}, sf::IntRect effectRect = {530, 157, 17, 22});
    virtual ~EstusFlask();
    virtual void use(Hero& hero) override;
    //TODO LATER reset usage in Bonfire
private:
    int healthRestored = 30;// TODO blance healh restored
};

#endif //_ESTUSFLASK_H
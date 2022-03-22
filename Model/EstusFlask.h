#ifndef _ESTUSFLASK_H
#define _ESTUSFLASK_H

#include "Item.h"
#include "Hero.h"

class EstusFlask: public Item {
public:
    explicit EstusFlask(std::string itemName = "Fiaschetta di Cura",int itemPrice = 0,
                        std::string itemDescriptin = "Fiaschette che curano 30hp", int maxItemCount = 5, int itemCount = 5, int x = 412, int y = 2, 
                        int width = 20, int height = 21);
    virtual ~EstusFlask();
    void use(Hero& hero) override;
private:
    int healthRestored = 30;// TODO blance healh restored
};

#endif //_ESTUSFLASK_H
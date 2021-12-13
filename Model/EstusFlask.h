#ifndef _ESTUSFLASK_H
#define _ESTUSFLASK_H

#include "Item.h"
//#include "Hero.h"

class EstusFlask: public Item {
public:
    explicit EstusFlask(std::string itemName = "Fiaschetta di Cura",int itemPrice = 0,
                        std::string itemDescriptin = "Fiaschette che curano 30hp", int maxItemCount = 5, int itemCount = 5, float x = 412, float y = 2, 
                        int width = 20, int height = 21);
    ~EstusFlask();
    //TODO void use(Hero& hero);
private:
    int healthRestored = 30;// TODO blance healh restored
};

#endif //_ESTUSFLASK_H
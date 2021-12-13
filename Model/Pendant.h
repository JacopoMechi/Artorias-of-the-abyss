#ifndef _PENDANT_H
#define _PENDANT_H

#include "Item.h"
//#include "GameCharacter.h"

class Pendant: public Item {
public://is it correct the override like this?
    explicit Pendant(std::string itemName = "Pendente", int itemPrice = 10000,
                     std::string itemDescription = "Permette la deviazione delle spells", int maxItemCount = 100000, int itemCount = 0,
                     int x = 497, int y = 98, int width = 26, int height = 21);
    ~Pendant();
    void use(GameCharacter& hero);
private:
    int immuneTime = 3;
};

#endif //_PENDANT_H
#ifndef _PENDANT_H
#define _PENDANT_H

#include "Item.h"

class Pendant: public Item {
public://is it correct the override like this?
    explicit Pendant(std::string itemName = "Pendente", int itemPrice = 10000,
                     std::string itemDescription = "Permette la deviazione delle spells", int maxItemCount = 1, int itemCount = 0,
                     int x = 498, int y = 99, int width = 23, int height = 17);
    ~Pendant();
    void use(Hero& hero);
private:
    int immuneTime = 3;
};

#endif //_PENDANT_H
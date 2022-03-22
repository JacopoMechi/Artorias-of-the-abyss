#ifndef _GREENBLOSSOM_H
#define _GREENBLOSSOM_H

#include "Item.h"
//#include "Hero.h"


class GreenBlossom: public Item {
public:
    explicit GreenBlossom(std::string itemName = "Estratto di Fiore verde", int itemPrice = 1000,
                          std::string itemDescription = "Riduce il cooldown dei dash per 60 secondi", int maxItemCount = 10, 
                          int itemCount = 0, int x = 453, int y = 2, int width = 20, int height = 20);
    ~GreenBlossom();
    void use(Hero &hero);
private:
    float newCooldown = 0.8f;// TODO needs to be balanced
    int timeEffect = 60;
};

#endif //_GREENBLOSSOM_H
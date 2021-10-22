#ifndef _GREENBLOSSOM_H
#define _GREENBLOSSOM_H

#include "Item.h"
#include "Hero.h"


class GreenBlossom: public Item {
public:
    explicit GreenBlossom(std::string n = "Fiore verde", int p = 1000, int c = 0,
                          std::string d = "Riduce il cooldown dei dash per 60 secondi", int M = 10);
    ~GreenBlossom();
    void use(Hero &hero, int newCooldown, int timeEffect);
private:
    int newCooldwon;// needs a value
    int timeEffect = 60;
};

#endif //_GREENBLOSSOM_H
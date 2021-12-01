#ifndef _ESTUSFLASK_H
#define _ESTUSFLASK_H

#include "Item.h"
#include "Hero.h"

class EstusFlask: public Item {
public:
    explicit EstusFlask(std::string n = "Fiaschetta di Cura",int p = 0,
                        std::string d = "Fiaschette che curano 30hp", int M = 5, int c = 5);
    ~EstusFlask();
    void use(Hero& hero);
private:
    int healthRestored = 30;// TODO blance healh restored
};

#endif //_ESTUSFLASK_H
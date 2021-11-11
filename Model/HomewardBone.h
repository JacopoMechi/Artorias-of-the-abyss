#ifndef _HOMEWARDBONE_H
#define _HOMEWARDBONE_H

#include "Item.h"
#include "MapElements.h"
#include "Hero.h"

class HomewardBone: public Item {
public: 
    explicit HomewardBone(std::string n = "Osso del Ritorno", int p = 2000,
                 std::string d = "Permette il teletrasporto all'ultimo falo' interagito", int M = 3, int c = 0);
    ~HomewardBone();

    void use(Hero& hero, MapElements& bonfire);
};

#endif //_HOMEWARDBONE_H
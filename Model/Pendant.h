#ifndef _PENDANT_H
#define _PENDANT_H

#include "Item.h"
#include "GameCharacter.h"

class Pendant: public Item {
public://is it correct the override like this?
    explicit Pendant(std::string n = "Pendente", int p = 10000,
                     std::string d = "Permette la deviazione delle spells", int M = 100000, int c = 0);
    ~Pendant();
    void use(GameCharacter& hero);
private:
    int immuneTime = 3;
};

#endif //_PENDANT_H
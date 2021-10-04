/**
 * Project Untitled
 */


#ifndef _SHIELD_H
#define _SHIELD_H

#include "Weapon.h"


class Shield: public Weapon {
public: 
    void defence;
    
void reduceDamage();
};

#endif //_SHIELD_H
#ifndef _SWORD_H
#define _SWORD_H

#include "Weapon.h"
class Sword : public Weapon
{
public:
    virtual void setLevel(int level) override;

protected:
    Sword(int level = 1);

    ~Sword();
};

#endif //_SWORD_H
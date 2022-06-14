#ifndef _CATALYST_H
#define _CATALYST_H

#include "Weapon.h"

class Catalyst : public Weapon
{
public:
    virtual void setLevel(int level) override;

protected:
    Catalyst(int level = 1);

    ~Catalyst();
};

#endif //_CATALYST_H
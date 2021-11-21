#ifndef _WEAPON_H
#define _WEAPON_H

class Weapon
{
public:
    int getDamage();

    int getLevel();

    virtual void setLevel(int level) = 0;

    explicit Weapon(int level = 1);

    //~Weapon();

protected:
    int damage;
    int level;
};

#endif //_WEAPON_H
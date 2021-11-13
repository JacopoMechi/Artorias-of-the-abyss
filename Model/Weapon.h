#ifndef _WEAPON_H
#define _WEAPON_H

class Weapon
{
public:
    int getDamage();

    int getLevel();

    virtual void setLevel(int level) = 0;

protected:
    explicit Weapon(int level = 1);

    ~Weapon();

    int damage;
    int level;
};

#endif //_WEAPON_H
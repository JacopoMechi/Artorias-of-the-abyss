#ifndef _WEAPON_H
#define _WEAPON_H

class Weapon
{
public:
    explicit Weapon(int level = 1);

    ~Weapon();

    int getDamage();

    int getLevel();

    virtual void setLevel(int level) = 0;

protected:
    int damage;
    int level;
};

#endif //_WEAPON_H
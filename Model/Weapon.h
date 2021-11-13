#ifndef _WEAPON_H
#define _WEAPON_H

class Weapon
{
public:
    Weapon(int damage, int level);

    ~Weapon();

    int getDamage();

    void setDamage(int damage);

    int getLevel();

    void setLevel(int level);

    virtual int use() = 0;

protected:
    int damage;
    int level;
};

#endif //_WEAPON_H
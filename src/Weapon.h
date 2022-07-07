#ifndef _WEAPON_H
#define _WEAPON_H

#include <SFML/Graphics.hpp>

class Weapon
{
public:
    int getDamage();

    int getLevel();

    virtual void setLevel(int level);

    explicit Weapon(int level = 1);

    virtual void use(sf::RenderWindow &window);

    //~Weapon();

protected:
    int damage;
    int level;
};

#endif //_WEAPON_H
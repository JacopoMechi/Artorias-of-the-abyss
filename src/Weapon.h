#ifndef _WEAPON_H
#define _WEAPON_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Weapon
{
public:
    int getDamage();

    int getLevel();

    virtual void setLevel(int level);

    virtual void use(sf::RenderWindow &window);

    Weapon(sf::IntRect weaponRect, sf::Vector2f weaponScale, int nFrames, int level = 1);

    virtual ~Weapon() = default;

protected:
    //variable for weapon's sprite
    sf::Sprite weaponSprite;
    sf::Texture texture;
    // for weapon's animation
    int nFrames;

    int damage;
    int level;
};

#endif //_WEAPON_H
#ifndef _WEAPON_H
#define _WEAPON_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Weapon
{
public:
    int getDamage() const;

    int getLevel() const;

    virtual void setLevel(int level);
    
    void setStartAnimation(bool startAnimation);

    sf::Sprite getSprite() const;

    //getters for unit testing
    int getNFrames() const;
    int getIFrame() const;

    virtual void use(sf::RenderWindow &window, sf::IntRect entityRect, sf::Vector2f entityPos, float dt);

    Weapon(sf::IntRect weaponRect, sf::Vector2f weaponScale, int nFrames, int level = 1);

    virtual ~Weapon() = default;

protected:
    //variable for weapon's sprite
    sf::Sprite weaponSprite;
    sf::Texture texture;
    sf::IntRect weaponRect;
    // for weapon's animation
    int nFrames;
    bool startAnimation = false;
    sf::IntRect currentRect;
    //to set position of the weapon if it is a sword or a staff
    int xVariation;
    int yVariation;
    //creating weapon's animation
    float weaponAnimationTime = 0.0f;
    float weaponAnimationHolding = 0.13f;
    int iWeaponFrame = 0;

    int damage;
    int level;
};

#endif //_WEAPON_H
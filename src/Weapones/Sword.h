#ifndef _SWORD_H
#define _SWORD_H

#include "Weapon.h"
class Sword : public Weapon
{
public:

    virtual void setLevel(int level) override;

    virtual void use(sf::RenderWindow &window, sf::IntRect entityRect, sf::Vector2f entityPos, float dt) override;

    explicit Sword(sf::IntRect weaponRect = {0, 162, 21, 40}, sf::Vector2f weaponScale = {7.5f, 7.5f}, int nFrames = 5, int level = 1);

    virtual ~Sword() = default;
protected:
};

#endif //_SWORD_H
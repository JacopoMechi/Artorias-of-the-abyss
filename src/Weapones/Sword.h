#ifndef _SWORD_H
#define _SWORD_H

#include "Weapon.h"
class Sword : public Weapon
{
public:

    virtual void setLevel(int level) override;

    virtual void use(sf::RenderWindow &window, sf::IntRect entityRect, sf::Vector2f entityPos, float dt) override;

    explicit Sword(sf::IntRect weaponRect = {firstSwordX, firstSwordY, firstSwordWidth, firstSwordHeight}, sf::Vector2f weaponScale = {swordScale, swordScale}, int nFrames = maxSwordFrames, int level = 1);

    virtual ~Sword() = default;
protected:
};

#endif //_SWORD_H
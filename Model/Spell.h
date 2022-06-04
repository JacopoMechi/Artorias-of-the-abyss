#ifndef _SPELL_H
#define _SPELL_H

#include "GameCharacter.h"

class Spell: public GameCharacter{
public:
    explicit Spell(const sf::Vector2f& pos = {0,0}, int hp = 0, int armor = 0, int cash = 0, float movementSpeed = 100);
    virtual ~Spell() = default;

    //cancelling implementation of no needed functions
    virtual void receiveDamage(int points) override;
    virtual void attack(sf::RenderWindow &window) override;
    virtual void movement(bool isInventoryOpen, bool isInteracting) override;


};

#endif
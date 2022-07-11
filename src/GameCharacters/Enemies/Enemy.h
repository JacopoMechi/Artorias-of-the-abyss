#ifndef _ENEMY_H
#define _ENEMY_H

#include "GameCharacters/GameCharacter.h"
#include "GameCharacters/Hero.h"

class Enemy : public GameCharacter
{
public:
    Enemy(sf::RenderWindow &window, const sf::Vector2f &pos, int hp, int armor, int cash, float movementSpeed);

    bool getAggro();

    void setAggro(bool aggro);

    virtual void attack(std::unique_ptr<Hero> hero) = 0;

protected:
    bool isRanged;
    bool aggro;
};

#endif
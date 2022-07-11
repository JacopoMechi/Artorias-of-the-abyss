#ifndef _ENEMY1_H
#define _ENEMY1_H

#include "Enemy.h"

class Enemy1 : public Enemy
{
public:
    Enemy1(sf::RenderWindow &window, const sf::Vector2f &pos, int hp, int armor, int cash, float movementSpeed);

    void attack(std::unique_ptr<Hero> hero) override;

    void movement(bool isInventoryOpen, bool isInteracting) override;
};

#endif
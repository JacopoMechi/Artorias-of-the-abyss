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

    virtual void attack(Hero &hero, float dt) = 0;

    virtual void update(float dt) override;

protected:
    std::vector<sf::IntRect> frameRects; // to set enemies frame rects
    bool isRanged;
    bool aggro;
    const float attackHoldTime = enemyAttHoldTimeAmount;
    float resetAttack = 0.0f;
};

#endif
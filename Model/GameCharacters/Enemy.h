#ifndef _ENEMY_H
#define _ENEMY_H

#include "GameCharacter.h"

class Enemy : public GameCharacter
{
public:
    // enum class Type
    // {
    //     Boss1,
    //     Boss2,
    //     Boss3,
    //     Enemy1,
    //     Enemy2,
    //     Enemy3,
    //     Enemy4
    // };

    Enemy(sf::RenderWindow &window, const sf::Vector2f &pos, int hp, int armor, int cash, float movementSpeed);

    bool getAggro();

    void setAggro(bool aggro);

    void attack() override;

protected:
    bool isRanged;
    bool aggro;
};

#endif
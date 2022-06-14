#include "Enemy.h"

Enemy::Enemy(sf::RenderWindow &window, const sf::Vector2f &pos, int hp, int armor, int cash, float movementSpeed) : GameCharacter(window, pos, hp, armor, cash, movementSpeed) {}

bool Enemy::getAggro()
{
    return aggro;
}

void Enemy::setAggro(bool aggro)
{
    this->aggro = aggro;
}
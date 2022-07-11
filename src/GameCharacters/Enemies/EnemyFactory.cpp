#include "EnemyFactory.h"

std::unique_ptr<Enemy> EnemyFactory::createEnemy(int type, sf::RenderWindow &window, const sf::Vector2f &pos, int hp, int armor, int cash, float movementSpeed) const
{
    if (type == 1)
    {
        return std::unique_ptr<Enemy1>(new Enemy1(window, pos, hp, armor, cash, movementSpeed));
    }
    else
        return 0;
}
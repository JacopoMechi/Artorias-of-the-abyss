#include "EnemyFactory.h"

std::unique_ptr<Enemy> EnemyFactory::makeEnemy(std::string type, sf::RenderWindow &window, const sf::Vector2f &pos, int hp, int armor, int cash, float movementSpeed) const
{
    std::unique_ptr<Enemy> enemy;
    enemy = createEnemy(type, window, pos, hp, armor, cash, movementSpeed);

    return enemy;
}

std::unique_ptr<Enemy> EnemyFactory::createEnemy(std::string type, sf::RenderWindow &window, const sf::Vector2f &pos, int hp, int armor, int cash, float movementSpeed) const
{
    if (type.compare("enemy1") == 0)
    {
        return std::unique_ptr<Enemy1>(new Enemy1(window, pos, hp, armor, cash, movementSpeed));
    }
    else
        return 0;
}
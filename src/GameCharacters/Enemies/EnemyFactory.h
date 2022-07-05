#ifndef _ENEMYFACTORY_H
#define _ENEMYFACTORY_H
#include <SFML/Graphics.hpp>
#include <string>
#include "Enemy.h"
#include "Enemy1.h"

class EnemyFactory
{
public:
    std::unique_ptr<Enemy> makeEnemy(std::string type, sf::RenderWindow &window, const sf::Vector2f &pos, int hp, int armor, int cash, float movementSpeed) const;

    std::unique_ptr<Enemy> createEnemy(std::string type, sf::RenderWindow &window, const sf::Vector2f &pos, int hp, int armor, int cash, float movementSpeed) const;
};
#endif
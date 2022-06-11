#include "Enemy.h"

Enemy::Enemy(sf::RenderWindow &window, const sf::Vector2f &pos, int hp, int armor, int cash, float movementSpeed) : GameCharacter(window, pos, hp, armor, cash, movementSpeed)
{
    // texture.loadFromFile(texturePath);
    // sprite.setTexture(texture); // loading chracter's sprite
    // switch (enemyType)
    // {
    // case Type::Boss1:
    //     defaultRect = {0, 0, 16, 22};
    //     frameRect = defaultRect;
    //     break;
    // case Type::Boss2:
    //     defaultRect = {0, 0, 16, 22};
    //     frameRect = defaultRect;
    //     break;
    // case Type::Boss3:
    //     defaultRect = {0, 0, 16, 22};
    //     frameRect = defaultRect;
    //     break;
    // case Type::Enemy1:
    //     defaultRect = {138, 4, 23, 30};
    //     frameRect = defaultRect;
    //     break;
    // case Type::Enemy2:
    //     defaultRect = {0, 0, 16, 22};
    //     frameRect = defaultRect;
    //     break;
    // case Type::Enemy3:
    //     defaultRect = {0, 0, 16, 22};
    //     frameRect = defaultRect;
    //     break;
    // case Type::Enemy4:
    //     defaultRect = {0, 0, 16, 22};
    //     frameRect = defaultRect;
    //     break;
    // }
    // sprite.setScale(7.5f, 7.5f);
}

bool Enemy::getAggro()
{
    return aggro;
}

void Enemy::setAggro(bool aggro)
{
    this->aggro = aggro;
}

void Enemy::attack()
{
}
#include "Enemy.h"

Enemy::Enemy(sf::RenderWindow &window, const sf::Vector2f &pos, int hp, int armor, int cash, float movementSpeed) : GameCharacter(window, pos, hp, armor, cash, movementSpeed)
{
    if (!texture.loadFromFile(texturePath))
        std::cout << "Error on loading hero's texture" << std::endl;
    sprite.setTexture(texture);
    sprite.setScale(7.5f, 7.5f);
}

bool Enemy::getAggro()
{
    return aggro;
}

void Enemy::setAggro(bool aggro)
{
    this->aggro = aggro;
}
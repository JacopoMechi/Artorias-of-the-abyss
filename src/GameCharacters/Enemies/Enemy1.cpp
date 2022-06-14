#include "Enemy1.h"

Enemy1::Enemy1(sf::RenderWindow &window, const sf::Vector2f &pos, int hp, int armor, int cash, float movementSpeed) : Enemy(window, pos, hp, armor, cash, movementSpeed)
{
    texture.loadFromFile(texturePath);
    sprite.setTexture(texture);
    defaultRect = {138, 4, 23, 30};
    frameRect = defaultRect;
    sprite.setScale(7.5f, 7.5f);
}

void Enemy::attack()
{
}

void Enemy1::movement(bool isInventoryOpen, bool isInteracting) {}
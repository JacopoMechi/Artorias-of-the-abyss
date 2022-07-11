#include "Enemy1.h"

Enemy1::Enemy1(sf::RenderWindow &window, const sf::Vector2f &pos, int hp, int armor, int cash, float movementSpeed) : Enemy(window, pos, hp, armor, cash, movementSpeed)
{
    texture.loadFromFile(texturePath);
    sprite.setTexture(texture);
    defaultRect = {138, 4, 23, 30};
    frameRect = defaultRect;
    sprite.setScale(7.5f, 7.5f);
}

void Enemy1::attack(std::unique_ptr<Hero> hero)
{
    if (getPos().x > 230 && getPos().x < 1550 && hero->getPos().y == getPos().y)
    {
        if (hero->getPos().x > getPos().x)
            setPos({getPos().x + 0.1f, getPos().y});
        else if (hero->getPos().x < getPos().x)
            setPos({getPos().x - 0.1f, getPos().y});
    }
    else if (getPos().y > 30 && getPos().y < 745 && hero->getPos().x == getPos().x)
    {
        if (hero->getPos().y > getPos().y)
            setPos({getPos().x, getPos().y + 0.1f});
        else if (hero->getPos().y < getPos().y)
            setPos({getPos().x, getPos().y - 0.1f});
    }
}

void Enemy1::movement(bool isInventoryOpen, bool isInteracting) {}
#include "Enemy1.h"

Enemy1::Enemy1(sf::RenderWindow &window, const sf::Vector2f &pos, int hp, int armor, int cash, float movementSpeed) : Enemy(window, pos, hp, armor, cash, movementSpeed)
{
    defaultRect = {138, 4, 23, 31};
    // defaultRect = {169, 3, 22, 30};
    // defaultRect = {202, 3, 22, 31};
    // defaultRect = {232, 6, 26, 28};
    // defaultRect = {265, 4, 22, 30};
    // defaultRect = {297, 1, 22, 33};
    // defaultRect = {329, 0, 22, 34};
    // defaultRect = {361, 6, 23, 28};

    frameRect = defaultRect;
    sprite.setTextureRect(defaultRect);
    sprite.setPosition(pos);
}

void Enemy1::attack(Hero &hero)
{
    if (dir.y == 0 && dir.x == 0 && pos.y < hero.getPos().y + hero.getSize().y / 2 && hero.getPos().y + hero.getSize().y / 2 < pos.y + getSize().y)
    {
        if (hero.getPos().x > pos.x)
            dir.x = 1;
        else if (hero.getPos().x < pos.x)
            dir.x = -1;
    }
    if ((pos.x >= 1550 && dir.x == 1) || (pos.x <= 230 && dir.x == -1))
        dir.x = 0;

    if (dir.x == 0 && dir.y == 0 && pos.x < hero.getPos().x + hero.getSize().x / 2 && hero.getPos().x + hero.getSize().x / 2 < pos.x + getSize().x)
    {
        if (hero.getPos().y > pos.y)
            dir.y = 1;
        else if (hero.getPos().y < pos.y)
            dir.y = -1;
    }

    if ((pos.y >= 745 && dir.y == 1) || (pos.y <= 30 && dir.y == -1))
        dir.y = 0;
}

void Enemy1::movement(bool isInventoryOpen, bool isInteracting) {}
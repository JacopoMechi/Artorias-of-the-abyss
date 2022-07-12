#include "Enemy1.h"

Enemy1::Enemy1(sf::RenderWindow &window, const sf::Vector2f &pos, int hp, int armor, int cash, float movementSpeed) : Enemy(window, pos, hp, armor, cash, movementSpeed)
{
    texture.loadFromFile(texturePath);
    sprite.setTexture(texture);
    frameRects.push_back({138, 4, 23, 31});
    frameRects.push_back({169, 3, 22, 30});
    frameRects.push_back({202, 3, 22, 31});
    frameRects.push_back({232, 6, 26, 28});
    frameRects.push_back({265, 4, 22, 30});
    frameRects.push_back({297, 1, 22, 33});
    frameRects.push_back({329, 0, 22, 34});
    frameRects.push_back({361, 6, 23, 28});
    defaultFrames = 8;
    frameRect = frameRects[0];
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
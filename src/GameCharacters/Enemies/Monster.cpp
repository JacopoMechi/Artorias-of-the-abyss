#include "Monster.h"

Enemy1::Enemy1(sf::RenderWindow &window, const sf::Vector2f &pos, int hp, int armor, int cash, float movementSpeed) : Enemy(window, pos, hp, armor, cash, movementSpeed)
{
    frameRects.push_back({firstMonsterRectX, firstMonsterRectY, firstMonsterRectWidth, firstMonsterREctHeight});
    frameRects.push_back({secondMonsterRectX, secondMonsterRectY, secondMonsterRectWidth, secondMonsterRectHeight});
    frameRects.push_back({thirdMonsterRectX, thirdMonsterRectY, thirdMonsterRectWidth, thirdMonsterRectHeight});
    frameRects.push_back({fourthMonsterRectX, fourthMonsterRectY, fourthMonsterRectWidth, fourthMonsterRectHeight});
    frameRects.push_back({fifthMonsterRectX, fifthMonsterRectY, fifthMonsterRectWidth, fifthMonsterRectHeight});
    frameRects.push_back({sixthMonsterRectX, sixthMonsterRectY, sixthMonsterRectWidth, sixthMonsterRectHeight});
    frameRects.push_back({seventhMonsterRectX, seventhMonsterRectY, seventhMonsterRectWidth, seventhMonsterRectHeight});
    frameRects.push_back({eighthMonsterRectX, eighthMonsterRectY, eighthMonsterRectWidth, eighthMonsterRectHeight});
    frameRect = frameRects[0];
    sprite.setTextureRect(frameRect);
}

void Enemy1::attack(Hero &hero, float dt)
{
    if (!aggro)
        resetAttack += dt;

    if (resetAttack >= attackHoldTime)
    {
        resetAttack = 0.0f;
        aggro = true;
    }

    if (aggro && dir.y == 0 && dir.x == 0 && pos.y < hero.getPos().y + hero.getSize().y / 2 && hero.getPos().y + hero.getSize().y / 2 < pos.y + getSize().y)
    {
        if (hero.getPos().x > pos.x)
            dir.x = 1;
        else if (hero.getPos().x < pos.x)
            dir.x = -1;
    }
    if ((pos.x >= rightMonsterbound && dir.x == 1) || (pos.x <= leftMonsterBound && dir.x == -1))
        dir.x = 0;

    if (aggro && dir.x == 0 && dir.y == 0 && pos.x < hero.getPos().x + hero.getSize().x / 2 && hero.getPos().x + hero.getSize().x / 2 < pos.x + getSize().x)
    {
        if (hero.getPos().y > pos.y)
            dir.y = 1;
        else if (hero.getPos().y < pos.y)
            dir.y = -1;
    }

    if ((pos.y >= topMonsterBound && dir.y == 1) || (pos.y <= bottomMonsterBound && dir.y == -1))
        dir.y = 0;

    if (dir.x == 0 && dir.y == 0)
        aggro = false;

    if ((dir.x != 0 || dir.y != 0) && getSprite().getGlobalBounds().intersects(hero.getSprite().getGlobalBounds()))
    {
        hero.receiveDamage(1);
    }
}

void Enemy1::movement(bool isInventoryOpen, bool isInteracting) {}
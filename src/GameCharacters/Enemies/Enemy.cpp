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

void Enemy::update(float dt){
    vel = dir * movementSpeed;
    pos += vel * dt;

    nFrames = defaultFrames;
    if (dir.x > 0.0f)
    {
        frameRect = frameRects[iFrame];
    }
    else if (dir.x < 0.0f)
    {
        frameRect = {frameRects[iFrame].width, frameRects[iFrame].top, -frameRects[iFrame].width, frameRects[iFrame].height}; // flipped sprite
    }
    else if (dir.y == 0)
    {
        nFrames = 1;
    }

    // checking when animationTime reaches max gap (animationHolding): this means that is time to change sprite frame rect
    animationTime += dt;
    if (animationTime >= animationHolding)
    {
        iFrame = (++iFrame) % nFrames;
        animationTime = 0.0f;
    }

    sprite.setTextureRect({frameRect.left + iFrame * std::abs(frameRect.width), frameRect.top, frameRect.width, frameRect.height});
    sprite.setPosition(pos);
}
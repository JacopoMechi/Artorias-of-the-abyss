#include "GameCharacter.h"

const std::string GameCharacter::texturePath = "../Textures/Textures.png";

GameCharacter::GameCharacter(sf::RenderWindow &window, const sf::Vector2f &pos, int hp, int armor, int cash, float movementSpeed) : window(window),
                                                                                                                                    pos(pos), hp(hp), movementSpeed(movementSpeed), weapon(nullptr)
{
}

int GameCharacter::getHp() const
{
    return hp;
}

void GameCharacter::setHp(int hp)
{
    if (hp < 0)
        hp = 0;
    this->hp = hp;
}

sf::Vector2f GameCharacter::getPos() const
{
    return pos;
}

void GameCharacter::setPos(sf::Vector2f pos)
{
    this->pos = pos;
}

int GameCharacter::getMovementSpeed() const
{
    return movementSpeed;
}

void GameCharacter::setMovementSpeed(int movementSpeed)
{
    this->movementSpeed = movementSpeed;
}

Weapon *GameCharacter::getWeapon() const
{
    return weapon;
}

void GameCharacter::setWeapon(Weapon *weapon)
{
    this->weapon = weapon;
}

void GameCharacter::receiveDamage(int points)
{
    points = points * armor / 100;
    setHp(hp - points);
}

bool GameCharacter::isInteractable(float interactableDistance, GameCharacter &entity)
{
    if (abs(sqrt(((entity.getPos().x - pos.x) * (entity.getPos().x - pos.x)) + ((entity.getPos().y - pos.y) * (entity.getPos().y - pos.y)))) < interactableDistance)
        return true;
    else
        return false;
}

void GameCharacter::draw() const
{
    window.draw(sprite);
}

void GameCharacter::update(float dt)
{
    vel = dir * movementSpeed;
    pos += vel * dt;

    nFrames = 8;
    if (dir.x > 0.0f)
    {
        frameRect = defaultRect;
    }
    else if (dir.x < 0.0f)
    {
        frameRect = {defaultRect.width, defaultRect.top, -defaultRect.width, defaultRect.height}; // flipped sprite
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

    sprite.setTextureRect({frameRect.left + iFrame * abs(frameRect.width), frameRect.top, frameRect.width, frameRect.height});
    sprite.setPosition(pos);
}

sf::Vector2f GameCharacter::getSize() const
{
    return {this->sprite.getScale().x * defaultRect.width, this->sprite.getScale().y * defaultRect.height};
}
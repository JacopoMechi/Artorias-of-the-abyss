#include "GameCharacter.h"

const std::string GameCharacter::texturePath = "../Textures/Textures.png";

GameCharacter::GameCharacter(sf::RenderWindow &window, const sf::Vector2f &pos, int hp, float movementSpeed) : window(window),
                                                                                                               pos(pos), HP(hp), movementSpeed(movementSpeed), weapon(nullptr)
{
}

int GameCharacter::getHp() const
{
    return HP;
}

void GameCharacter::setHp(int hp)
{
    if (hp < 0)
        hp = 0;
    this->HP = hp;
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

bool GameCharacter::isInteractable(GameCharacter &entity)
{
    if (abs(sqrt(((entity.getPos().x - pos.x) * (entity.getPos().x - pos.x)) + ((entity.getPos().y - pos.y) * (entity.getPos().y - pos.y)))) < interactableDistance)
        return true;
    else
        return false;
}

void GameCharacter::draw(sf::RenderTarget &rt) const
{
    rt.draw(sprite);
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
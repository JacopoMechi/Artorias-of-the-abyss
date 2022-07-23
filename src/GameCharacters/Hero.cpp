#include "Hero.h"

Hero::Hero(sf::RenderWindow &window, bool isKnight, const sf::Vector2f &pos, int hp, int cash, float movementSpeed) : isKnight(isKnight), GameCharacter(window, pos, hp, armor, cash, movementSpeed)
{
    if (!texture.loadFromFile(texturePath))
        std::cout << "Error on loading hero's texture" << std::endl;
    sprite.setTexture(texture); // loading chracter's sprite
    // assigning weapon to hero
    // setting hero's sprite
    // this will be a default position with which the player will spawn
    if (isKnight)
    {
        defaultRect = {knightX, knightY, knightWidth, knightHeight};   // for hero's sprite
        auraShield.setTexture(texture); // the aura shield is an exclusive of hero
        auraShield.setTextureRect({auraX, auraY, auraWidth, auraHeight});
        auraShield.setScale(auraScale, auraScale);
        canAttack = true;
        startSpell = true;
        sword = std::make_unique<Sword>(); // knight's weapon assign
        baseArmor = 60;
    }
    else
    {
        defaultRect = {mageX, mageY, mageWidth, mageHeight};
        canAttack = false;
        catalyst = std::make_unique<Catalyst>(); // mage's weapon assign
        baseArmor = mageArmor;
    }
    armor = baseArmor;
    frameRect = defaultRect;
    sprite.setScale(heroScale, heroScale);
    sprite.setTextureRect(frameRect);
}

int Hero::getDash() const
{
    return dashCount;
}
void Hero::setDash(int dashCount)
{
    this->dashCount = dashCount;
}

void Hero::setDirX(float value)
{
    dir.x = value;
}

void Hero::setDirY(float value)
{
    dir.y = value;
}

int Hero::getCooldown() const
{
    return dashTimeHolding;
}

void Hero::setCooldown(float dashTimeHolding)
{
    this->dashTimeHolding = dashTimeHolding;
}

bool Hero::getCharacterType() const
{
    return isKnight;
}

bool Hero::getCanAttack() const
{
    return canAttack;
}

void Hero::setCanAttack(bool canAttack)
{
    this->canAttack = canAttack;
    isHitted = false; // setting isHitted to false to check if the enemy got hit
}

bool Hero::getStartingSpell() const
{
    return startSpell;
}

bool Hero::getAuraReady() const
{
    return auraReady;
}

void Hero::setAuraReady(bool auraReady)
{
    this->auraReady = auraReady;
    armor = 100; // hero will not take damage
}

void Hero::changeLevel(int level)
{
    if (isKnight)
    {
        if (level == 1)
            defaultRect = {secondKngihtX, secondKnightY, secondKnightWidth, secondKnightHeight};
        else if (level == 2)
            defaultRect = {thirdKnightX, thirdKnightY, thirdKnightWidth, thirdKnightHeight};
        else
            std::cout << "Error on setting knight's level" << std::endl;
        sword->setLevel(level + 1);
    }
    else
    {
        if (level == 1)
            defaultRect = {secondMageX, secondMageY, secondMageWidth, secondMageHeight};
        else if (level == 2)
            defaultRect = {thirdMageX, thirdMageY, thirdMageWidth, thirdMageHeight};
        else
            std::cout << "Error on setting mage's level" << std::endl;
        catalyst->setLevel(level + 1);
    }
}

void Hero::dash()
{
    // for dashing, we just need to move the character position farther only in the moment that we press Space key
    dashing = dashDistance * dir;
    if (dashCount > 0)
    {
        dashCount--;
        pos += dashing;
    }
}

void Hero::blockDamage(sf::RenderWindow &window)
{
    auraShield.setPosition((pos.x - auraVariationX), (pos.y - auraVariationY));
    window.draw(auraShield);
}

void Hero::attack(sf::RenderWindow &window)
{
    if (isKnight)
        sword->use(window, frameRect, pos, delayTime);
    else
    {
        startSpell = catalyst->getStartSpell();
        if (!startSpell)
            catalyst->setSpellDirection(pos, frameRect);
        catalyst->use(window, frameRect, pos, delayTime);
    }
}

void Hero::dealDamage(GameCharacter &entity)
{
    if (isKnight)
    {
        if (!isHitted && sword->getSprite().getGlobalBounds().intersects(entity.getSprite().getGlobalBounds()))
        {
            entity.receiveDamage(sword->getDamage());
            isHitted = true;
        }
    }
    else
    {
        if (!isHitted && catalyst->getSprite().getGlobalBounds().intersects(entity.getSprite().getGlobalBounds()))
        {
            entity.receiveDamage(catalyst->getDamage());
            isHitted = true;
        }
    }
}

// handling character action inputs like attack, roll, interact
void Hero::updateDelay(float dt)
{
    // updating delay time
    delayTime = dt;

    // handling sword attack cooldown
    if (!canAttack && isKnight)
    {
        attackTime += delayTime;
        if (attackTime >= attackTimeHolding)
        {
            attackTime = 0;
            canAttack = true;
        }
    }

    // handling shield aura time
    if (!auraReady)
    {
        auraTime += delayTime;
        if (auraTime >= auraTimeHolding)
        {
            auraTime = 0;
            auraReady = true;
            armor = baseArmor;
        }
    }

    // handling dash cooldown
    if (dashCount < maxDashes)
    {
        dashTime += delayTime;
        if (dashTime >= dashTimeHolding)
        {
            dashTime = 0;
            dashCount++;
        }
    }
}
void Hero::movement(bool isInventoryOpen, bool isInteracting)
{
}

void Hero::setSpawnPoint(sf::Vector2f pos)
{
    respawnPos = pos;
}

sf::Vector2f Hero::getSpawnPoint() const
{
    return respawnPos;
}

Weapon *Hero::getWeapon()
{
    if (isKnight)
        return sword.get();
    else
        return catalyst.get();
}
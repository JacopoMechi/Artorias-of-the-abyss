#include "Hero.h"

Hero::Hero(sf::RenderWindow &window, const sf::Vector2f &pos, int hp, int armor, int cash, float movementSpeed, bool isKnight) : GameCharacter(window, pos, hp, armor, cash, movementSpeed), isKnight(isKnight)
{
    texture.loadFromFile("../Textures/Textures.png");
    sprite.setTexture(texture);       // loading chracter's sprite
    weaponAttack.setTexture(texture); // loading character's weapon
    // setting hero's sprite
    // this will be a default position with which the player will spawn
    if (isKnight)
    {
        defaultRect = {0, 0, 16, 22};
        auraShield.setTexture(texture);
        auraShield.setTextureRect({501, 124, 20, 26});
        auraShield.setScale(7.0f, 7.0f);
        weaponRect = {0, 162, 21, 40}; // weapon's sprite
        weaponAttack.setScale(7.5f, 7.5f);
        nWeaponFrames = 5; // for attack animation
        canAttack = true;
        startSpell = true;
    }
    else
    {
        defaultRect = {0, 83, 15, 21};
        weaponRect = {2, 332, 38, 36};
        weaponAttack.setScale(3.5f, 3.5f);
        nWeaponFrames = 1;
        spellSprite.setTexture(texture);
        spellRect = {3, 299, 33, 20};
        currentSpellRect = spellRect;
        spellSprite.setTextureRect(currentSpellRect);
        spellSprite.setScale(3.5f, 3.5f);
        spellPos = {pos.x + 150, pos.y + 40}; // because the caracter starts facing right side
        spellSprite.setPosition(spellPos);
        canAttack = false;
    }
    weaponAttack.setTextureRect(weaponRect);
    frameRect = defaultRect;
    sprite.setScale(7.5f, 7.5f);
}

int Hero::getDash() const
{
    return dashCount;
}
void Hero::setDash(int dashCount)
{
    this->dashCount = dashCount;
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
}

bool Hero::getStartAnimation() const
{
    return startAnimation;
}
void Hero::setStartAnimation(bool startAnimation)
{
    this->startAnimation = startAnimation;
}

bool Hero::getStartingSpell() const
{
    return startSpell;
}

void Hero::setStartingSpell(bool startSpell)
{
    this->startSpell = startSpell;
}

bool Hero::getAuraReady() const
{
    return auraReady;
}
void Hero::setAuraReady(bool auraReady)
{
    this->auraReady = auraReady;
}

int Hero::getMoneyAmount() const
{
    return moneyCounter;
}

void Hero::setMoneyAmount(int moneyCounter)
{
    this->moneyCounter = moneyCounter;
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
void Hero::switchZone()
{ // TODO useful later maybe
}
void Hero::useBonfire()
{
}
void Hero::blockDamage()
{
    auraShield.setPosition((pos.x - 10), (pos.y - 3)); //(pos.x+3), (pos.y+3)
    window.draw(auraShield);
}

void Hero::attack()
{
    window.draw(spellSprite);
    if (startAnimation)
    {
        // setting position and rectangles of the weapon
        if (frameRect.width > 0)
        {
            currentRect = weaponRect;
            if (isKnight)
            {
                xVariation = 100;
                yVariation = -50;
            }
            else
            {
                xVariation = 10;
                yVariation = 40;
            }
        }
        else if (frameRect.width < 0)
        {
            currentRect = {weaponRect.width, weaponRect.top, -weaponRect.width, weaponRect.height};
            if (isKnight)
            {
                xVariation = -120;
                yVariation = -50;
            }
            else
            {
                xVariation = -20;
                yVariation = 40;
            }
        }

        // updating iFrames for weapon
        weaponAnimationTime += delayTime;
        if (weaponAnimationTime >= weaponAnimationHolding)
        {
            iWeaponFrame = (++iWeaponFrame) % nWeaponFrames;
            weaponAnimationTime = 0.0f;
            if (iWeaponFrame == 0)
                startAnimation = false;
        }

        // drawing animation
        if (startAnimation)
        {
            weaponAttack.setPosition(pos.x + xVariation, pos.y + yVariation);
            weaponAttack.setTextureRect({currentRect.left + iWeaponFrame * abs(currentRect.width), currentRect.top, currentRect.width, currentRect.height});
            window.draw(weaponAttack);
        }
    }
}

// handling character action inputs like attack, roll, interact
void Hero::updateDelayAndInputs(sf::Event keyInput, float dt)
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
        { // TODO or when character got hit
            auraTime = 0;
            auraReady = true;
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
    if (!isInventoryOpen && !isInteracting)
    {

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && pos.y > 30)
        {
            dir.y = -1.0f;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && pos.y < 745)
        {
            dir.y = 1.0f;
        }
        else
            dir.y = 0;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && pos.x > 230)
        {
            dir.x = -1.0f;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && pos.x < 1550)
        {
            dir.x = 1.0f;
        }
        else
            dir.x = 0;
    }
    else
        dir = {0, 0};
}

void Hero::respawn(float posX, float posY)
{
    // finish hero
}

// setting spell direction
void Hero::setSpellDirection()
{
    if (frameRect.width > 0)
    {
        spellDirection = 1; // right
        spellPos.x = pos.x + 150;
        currentSpellRect = spellRect;
    }
    if (frameRect.width < 0)
    {
        spellDirection = -1; // left
        spellPos.x = pos.x - 150;
        currentSpellRect = {spellRect.width, spellRect.top, -spellRect.width, spellRect.height};
    }
    spellPos.y = pos.y + 40;
    spellSprite.setTextureRect(currentSpellRect);
    spellSprite.setPosition(spellPos);
}

void Hero::castSpell()
{ // boolean value to know when is active or not
    if (startSpell)
    {
        if (0 < spellPos.x && spellPos.x < 1920)
        { // to set the range of the spell

            // to move the spell horizzontaly
            spellPos.x += spellSpeed * delayTime * spellDirection;
            spellSprite.setPosition(spellPos);

            // printing on screen
            window.draw(spellSprite);
        }
        else
            startSpell = false;
    }
}

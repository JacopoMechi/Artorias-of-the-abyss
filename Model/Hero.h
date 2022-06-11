#ifndef _HERO_H
#define _HERO_H

#include <string>
#include <cmath>
#include <iostream>

#include <SFML/Graphics.hpp>
#include "GameCharacter.h"
#include "Bonfire.h"

class Hero : public GameCharacter
{
    // TODO add a method to switch hero's armor and weapon when a boss is killed
public:
    Hero(sf::RenderWindow &window, const sf::Vector2f &pos, int hp, float movementSpeed, bool isKnight);
    virtual ~Hero() = default;

    int getDash() const;
    void setDash(int dashCount);

    // for green blossom which reduce dashes cooldown
    int getCooldown() const;
    void setCooldown(float dashTimeHolding);

    // getter for isKnight
    bool getCharacterType() const;

    // for hud to obscure attack
    bool getCanAttack() const;
    void setCanAttack(bool canAttack);

    // for starting naimation from hud
    bool getStartAnimation() const;
    void setStartAnimation(bool startAnimation);

    // getter and setter for aura
    bool getAuraReady() const;
    void setAuraReady(bool auraReady);

    // getter and setter for spell starting animation
    bool getStartingSpell() const;
    void setStartingSpell(bool startSpell);

    // getter and setter for changing the amount of money the character has
    int getMoneyAmount() const;
    void setMoneyAmount(int moneyCounter);

    float getHeroPosY() const;
    void setHeroPosY(float heroPosY);

    int getArmor();
    void setArmor(int armorValue);

    void dash();
    void addItem();
    void switchZone();
    void useBonfire();

    void blockDamage(sf::RenderWindow &window);

    virtual void attack(sf::RenderWindow &window) override;

    void updateDelayAndInputs(sf::Event keyInput, float dt);

    virtual void movement(bool isInventoryOpen, bool isInteracting) override;

    void respawn(float posX, float posY);
    // void receiveDamage(int points) override;

    void setSpellDirection();

    void castSpell(sf::RenderWindow &window);

protected:
    int dialogueTracker = 0;
    bool isInventoryOpen;
    Weapon *leftWeapon;
    bool isKnight;
    float delayTime;
    int moneyCounter = 10000;

    // shield aura sprite
    sf::Sprite auraShield;

    // sword swing sprite
    sf::Sprite weaponAttack;

    // spell system creation (after the use of the staff)
    sf::Sprite spellSprite;
    sf::Vector2f spellPos;
    float spellSpeed = 500; // for spell's speed
    // for right and left swap of the sprite
    sf::IntRect spellRect;
    sf::IntRect currentSpellRect;
    int spellDirection = 1; // to set direction in cast method //1 because characters starts from the right

    // handling shield aura time
    bool auraReady = true;
    float auraTimeHolding = 1.0f;
    float auraTime = 0.0f;

    // handling dashes
    int dashCount = 3;
    int maxDashes = 3;
    float dashTimeHolding = 2.0f;
    float dashTime = 0.0f;

<<<<<<< HEAD
    // handling attack cooldown
    bool canAttack = true;
    float attackTimeHolding = 0.5f;
    float attackTime = 0.0f;

    // int cooldown = 5;
    int amount;

    // for setting weapon pos when character is moving
    float weaponPosX;

    // declaring weapon's position (to flip it when character flips from right to left or from left to right)
    sf::IntRect weaponRect;
    sf::IntRect currentRect;
    // to set position of the weapon if it is a sword or a staff
    int xVariation;
    int yVariation;
    // to start spell animation
    bool startSpell;

    // boolean variable to start the animation
    bool startAnimation;

    // creating weapon's animation
    float weaponAnimationTime = 0.0f;
    float weaponAnimationHolding = 0.13f;
    int iWeaponFrame = 0;
    int nWeaponFrames;

    sf::Vector2f dashing;
    float dashDistance = 100.0f;
};

#endif //_HERO_H
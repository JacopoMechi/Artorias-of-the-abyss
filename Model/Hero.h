#ifndef _HERO_H
#define _HERO_H

#include <string>
#include <cmath>
#include <iostream>

#include <SFML/Graphics.hpp>
#include "GameCharacter.h"
#include "Bonfire.h"



class Hero: public GameCharacter {
    //TODO add a method to switch hero's armor and weapon when a boss is killed
public: 

    Hero(bool isKnight, const sf::Vector2f& pos, int hp, int armor, int cash, float movementSpeed);
    virtual ~Hero() = default;

    int getDash();
    void setDash(int dashCount);

    //for green blossom which reduce dashes cooldown
    int getCooldown();
    void setCooldown(float dashTimeHolding);

    //for hud to obscure attack
    bool getCanAttack();
    void setCanAttack(bool canAttack);

    //getter and setter for aura 
    bool getAuraReady();
    void setAuraReady(bool auraReady);

    float getHeroPosY();
    void setHeroPosY(float heroPosY);

    void dash();

    void addItem();
    
    void switchZone();
    
    void useBonfire();

    void blockDamage(sf::RenderWindow &window);
    
    void attack(sf::RenderWindow& window) override;

    void updateDelayAndInputs(sf::Event keyInput, float dt);
    
    void movement(bool isInventoryOpen, bool isInteracting);
    
    void respawn(float posX, float posY);

protected: 

    int dialogueTracker = 0;
    bool isInventoryOpen;
    Weapon* leftWeapon;
    bool isKnight;
    float delayTime;

    //shield aura sprite
    sf::Sprite auraShield;

    //sword swing sprite
    sf::Sprite weaponAttack;

    //handling shield aura time
    bool auraReady = true;
    float auraTimeHolding = 1.0f;
    float auraTime = 0.0f;

    //handling dashes
    int dashCount = 3;
    int maxDashes = 3;
    float dashTimeHolding = 1.0f;
    float dashTime = 0.0f;

    //handling attack cooldown
    bool canAttack = true;
    float attackTimeHolding = 0.5f;
    float attackTime = 0.0f;

    //int cooldown = 5;
    Bonfire* bonfire ;
    int amount;

    //for setting weapon pos when character is moving
    float weaponPosX;

    //declaring weapon's position (to flip it when character flips from right to left or from left to right)
    sf::IntRect weaponRect;
    sf::IntRect currentRect;

    //creating weapon's animation
    float weaponAnimationTime = 0.0f;
    float weaponAnimationHolding = 0.13f;
    int iWeaponFrame = 0;
    int nWeaponFrames;

    sf::Vector2f dashing;
    float dashDistance = 100.0f;
};

#endif //_HERO_H
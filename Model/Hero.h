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

    float getHeroPosY();
    void setHeroPosY(float heroPosY);

    void dash();

    void addItem();
    
    void switchZone();
    
    void useBonfire();

    void raiseShield();
    
    void attack() override;

    void updateDelayAndInputs(sf::Event keyInput, float dt);
    
    void movement(bool isInventoryOpen, bool isInteracting);
    
    void respawn(float posX, float posY);

    Weapon* getShield();
    void setShield(Weapon* weapon);

protected: 

    int dialogueTracker = 0;
    bool isInventoryOpen;
    Weapon* leftWeapon;
    bool isKnight;
    float delayTime;

    //handling dashes
    int dashCount = 3;
    int maxDashes = 3;
    float dashTimeHolding = 1.0f;
    float dashTime = 0.0f;

    //handling attack cooldown
    bool canAttack = true;
    float attackTimeHolding = 0.1f;
    float attackTime = 0.0f;
 

    float actionTime = 0.0f;
    int actionFrame = 0;
    sf::IntRect lastActionFrame = {0, 158, 31, 22};

    //int cooldown = 5;
    Bonfire* bonfire ;
    int amount;

    sf::Vector2f dashing;
    float dashDistance = 100.0f;
};

#endif //_HERO_H
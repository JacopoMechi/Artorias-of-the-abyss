#ifndef _HERO_H
#define _HERO_H

#include <string>
#include <cmath>
#include <iostream>

#include <SFML/Graphics.hpp>
#include "GameCharacter.h"
#include "Bonfire.h"



class Hero: public GameCharacter {
public: 

    Hero(bool isKnight, int hp, int armor, int cash, float movementSpeed, const sf::Vector2f& pos);
    ~Hero();

    int getDash();
    void setDash(int dashCount);

    int getCooldown();
    void setCooldown(int cooldown);

    float getHeroPosY();
    void setHeroPosY(float heroPosY);

    void dash();

    void addItem();
    
    void useItem();
    
    void switchZone();
    
    void useBonfire();

    void restoreHp(int amount);

    void raiseShield();
    
    void attack();

    void updateInputs(sf::Event keyInput);
    
    void movement(bool isInventoryOpen);
    
    void respawn(float posX, float posY);

    Weapon* getShield();
    void setShield(Weapon* weapon);

protected: 

    int dialogueTracker = 0;
    bool isInventoryOpen;
    Weapon* leftWeapon;
    bool isKnight;
    int dashCount = 3;

    float actionTime = 0.0f;
    int actionFrame = 0;
    sf::IntRect lastActionFrame = {0, 158, 31, 22};

    int cooldown = 5;
    Bonfire* bonfire ;
    int amount;

    sf::Vector2f dashing;
    float dashDistance = 100.0f;
};

#endif //_HERO_H